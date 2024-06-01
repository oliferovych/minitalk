/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:26:03 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/30 16:12:20 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "Libft/libft.h"
# define BUFF_SIZE 1024

typedef struct s_message
{
	char	*str;
	int		len;
	int		size;
}				t_message;

void	int_to_signals(int num, pid_t pid);
void	char_to_signals(int c, pid_t pid);

int		decode_bytes(int *bit_arr, int bytes);
int		putbit(int signal);
void	ft_addchar(char **string, int c);

#endif
