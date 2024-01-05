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

void send_bits(int pid, char *str)
{
	int	i;
	int pos;
	unsigned char temp;

	i = 0;
	temp = 0;
	pos = 0;
	while (str[pos])
	{
		while (i < 8)
		{
			temp = (str[pos] >> i & 1);
			if (temp == 1)
				kill(pid, SIGUSR1);
				//write(1, "1", 1);
			else
				kill(pid, SIGUSR2);
				//write(1, "0", 1);
			i++;
			usleep(100);
		}
		i = 0;
		pos++;
	}
}

int main (int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_bits(ft_atoi(argv[1]), argv[2]);
	return (0);
}
