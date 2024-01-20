/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:23 by rapcampo          #+#    #+#             */
/*   Updated: 2024/01/20 20:24:35 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned char	*g_message = NULL;

void	flood_string(unsigned char bits, siginfo_t *info)
{
	if (bits == 0x00)
	{
		write(1, g_message, ft_unstrlen(g_message));
		write(1, "\n", 1);
		free(g_message);
		kill(info->si_pid, SIGUSR1);
		g_message = NULL;
	}
	else
		g_message = ft_unstrjoin(g_message, bits);
}

void	handle_signals(int sig, siginfo_t *info, void *s)
{
	static int					byte;
	static unsigned char		bits;

	(void)s;
	if (sig == SIGUSR1)
		bits |= (0x01 << byte);
	byte++;
	if (byte == 0x08)
	{
		flood_string(bits, info);
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
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signals;
	sigemptyset(&sa.sa_mask);
	(void) argv;
	sa.sa_flags = SA_SIGINFO;
	print_pid();
	while (argc == 1)
	{
		signal(SIGINT, handle_sigint);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			write(1, "\e[91mhandler could not be resolved\e[0m", 39);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			write(1, "\e[91mhandler could not be resolved\e[0m", 39);
		pause();
	}
}
