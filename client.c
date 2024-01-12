/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:08 by rapcampo          #+#    #+#             */
/*   Updated: 2023/11/23 13:38:10 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bits(int pid, char c)
{
	int	i;
	unsigned char temp;

	i = -1;
	temp = 0;
	while (++i < 8)
	{
		temp = (c >> i & 1);
		if (temp == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}


int main (int argc, char **argv)
{
	pid_t pid;
	int i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		(void)argc;
		write (1, "\e[91m\e[5mWrong Format!!!\e[0m\n", 30);
		write (1, "\e[4mPlease input pid and your message!\e[0m\n", 44);
		exit(EXIT_FAILURE);
	}
	return (0);
}
