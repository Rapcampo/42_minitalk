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

void	flood_string(unsigned char bits)
{
	static unsigned char	*message = NULL;
	char letter;
	letter = bits;
	if (letter == '\0')
	{
		write(1, message, ft_strlen((char *)message));
		free(message);
		message = NULL;
	}
	else 
		message = ft_strjoin(message, ((char *)ft_itoa(letter)));
}

void	handle_signals(int sig)
{
	static int					i;
	static unsigned char		bits;
	char						*buffer;

	if (sig == SIGUSR1)
	{
		bits |= (1 << i);
	}
	i++;
	if (i == 8)
	{
		flood_string(bits);
//		write (1, &bits, 1);
		i = 0;
		bits = 0;
	}
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
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
