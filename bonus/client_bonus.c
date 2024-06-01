/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:24:02 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/30 16:28:33 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Message received.\n");
		exit (0);
	}
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
	}
}

static void	ft_sendstring(char *str, pid_t pid)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("Too few arguments"), 1);
	if (!ft_atoi(argv[1]))
		return (ft_printf("Invalid PID"), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	signal(SIGUSR1, ack_handler);
	ft_sendstring(argv[2], pid);
	while (1)
		pause();
	return (0);
}
