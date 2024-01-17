/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:08 by rapcampo          #+#    #+#             */
/*   Updated: 2024/01/15 11:48:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, unsigned char c)
{
	int				i;
//	unsigned char	temp;

	i = -1;
//	temp = 0;
	while (++i < 8)
	{
	//	temp = (c >> i & 1);
		if ((c >> i & 1) != 0)
			
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

/*void	send_null(int pid, char *to_print)
{
	int	i;
	int size;

	i = 0;
	size = ft_strlen(to_print);
	while (i <= size)
		send_bits(pid, (unsigned char)to_print[i++]);
}*/

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		{
			send_bits(pid, argv[2][i]);
	//		i++;
		}
		send_bits(pid, 0x00);
	//	send_null(pid, argv[2]);
	}
	else
	{
		(void)argc;
		write (1, "\e[5;91mWrong Format!!!\e[0m\n", 28);
		write (1, "\e[4mPlease input pid and your message!\e[0m\n", 44);
		exit(EXIT_FAILURE);
	}
	return (0);
}
