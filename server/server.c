/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:09:45 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/20 00:40:29 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// * SIGUSR1 -> bit 0
// * SIGUSR2 -> bit 1
static volatile t_message	g_message;

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;

	if (!g_message.client_pid)
		g_message.client_pid = info->si_pid;
	// ! check this logic
	if (signal == SIGUSR2)
		g_message.current_char |= (1 << g_message.byte_i); // ? set the bit 1 in the current index
	if (++g_message.byte_i == 8) // ! received all the 8 bits of the char
	{
		if (!g_message.current_char)
		{
			ft_printf("\n");
			kill(g_message.client_pid, SIGUSR2);
			g_message.client_pid = 0;
		}
		else
		{
			kill(g_message.client_pid, SIGUSR1);
			ft_printf("%c", &g_message.current_char);
		}
		g_message.current_char = 0;
		g_message.byte_i = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %i\n", getpid());
	s_sigaction.sa_sigaction = signal_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}
