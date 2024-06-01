/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:24:05 by dolifero          #+#    #+#             */
/*   Updated: 2024/06/01 15:30:20 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_message(char c, t_message *message)
{
	if (!message->str)
	{
		message->str = malloc(BUFF_SIZE);
		if (!message->str)
			return (ft_printf("Memory allocation failed\n"), exit(1));
		message->len = BUFF_SIZE;
		message->size = 0;
	}
	if (message->size == message->len - 1)
	{
		ft_realloc(&message->str, message->len, message->len * 2);
		message->len *= 2;
	}
	message->str[message->size++] = c;
	if (c == '\0')
	{
		ft_printf("Message: %s\n", message->str);
		free(message->str);
		message->str = NULL;
		message->len = 0;
		message->size = 0;
	}
}

static void	signal_handle(int signum, siginfo_t *info, void *context)
{
	static int			bit_count;
	static char			c;
	static t_message	message = {NULL, 0, 0};
	static int			old_pid = 0;

	if (old_pid != info->si_pid)
	{
		old_pid = info->si_pid;
		c = 0;
		bit_count = 0;
		if (message.str)
			free(message.str);
		message.str = NULL;
		message.len = 0;
		message.size = 0;
	}
	(void)context;
	if (signum == SIGUSR1)
		c |= 1 << bit_count;
	if (++bit_count == 8)
	{
		ft_message(c, &message);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	sa.sa_sigaction = signal_handle;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
