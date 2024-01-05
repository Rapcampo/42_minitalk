/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniserver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:23 by rapcampo          #+#    #+#             */
/*   Updated: 2023/11/23 13:38:24 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signals(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	int	byte;
	unsigned char bits;
	
	bits = 0;
	if (sig = SIGUSR1)
	{
		byte <<= 1;
		byte += 1;
		bits++;
	}
	else
	{
		byte <<= 1;
		bits++;
	}
	if (bits = 8)
		return; 

}

void	handle_SIGINT(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "Server has been shutdown successfuly\n", 38);
		exit(0);
	}
}

static void	print_pid(void)
{
	char *pid;

	pid = ft_itoa(getpid());
	write(1, "Server PID: ", 11);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}
int main (void)
{
	struct sigaction sa;

	print_pid();
	sa.sa_sigaction = &handle_signals;
	sa.sa_handler = &handle_SIGINT;
	sigaction(SIGINT, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "handler could not be resolved\n", 31);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "handler could not be resolved\n", 31);
	while (1)
		sleep(1);
}
