/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:23 by rapcampo          #+#    #+#             */
/*   Updated: 2024/01/15 11:49:51 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_message = NULL;

void	flood_string(unsigned char bits)
{
	if (bits == 0x00)
	{
		write(1, g_message, ft_unstrlen(g_message));
		write(1, "\n", 1);
		free(g_message);
		g_message = NULL;
	}
	else
		g_message = ft_unstrjoin(g_message, bits);
}

void	handle_signals(int sig)
{
	static int					byte;
	static unsigned char		bits;

	if (sig == SIGUSR1)
		bits |= (0x01 << byte);
	byte++;
	if (byte == 0x08)
	{
		flood_string(bits);
		byte = 0;
		bits = 0;
	}
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		if (g_message)
			free(g_message);
		write(1, "\n\n\e[92mServer has been shutdown successfuly!\e[0m\n", 50);
		exit(EXIT_SUCCESS);
	}
}

static void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "\e[31mServer PID: ", 18);
	write(1, pid, ft_strlen(pid));
	write(1, "\e[0;5;95m\nWaiting for message...\e[0m\n", 38);
	free(pid);
}

int	main(int argc, char **argv)
{
	(void) argv;
	print_pid();
	while (argc == 1)
	{
		signal(SIGUSR1, handle_signals);
		signal(SIGUSR2, handle_signals);
		signal(SIGINT, handle_sigint);
		if (signal(SIGUSR1, handle_signals) == SIG_ERR)
			write(1, "\e[91mhandler could not be resolved\e[0m", 39);
		if (signal(SIGUSR2, handle_signals) == SIG_ERR)
			write(1, "\e[91mhandler could not be resolved\e[0m", 39);
		pause();
	}
}
