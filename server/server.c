/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:09:45 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/20 19:28:49 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// * SIGNALS:
// * SIGUSR1 -> bit 0
// * SIGUSR2 -> bit 1

static void	signal_handler(int signal, siginfo_t *info, void *context);
static void	clean_message(void);

static volatile t_message	g_message = {0, 0, 0};

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %i\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_message.client_pid)
		g_message.client_pid = info->si_pid;
	g_message.current_char |= ((signal == SIGUSR2) << (7 - g_message.byte_i));
	if (++g_message.byte_i == 8)
	{
		if (!g_message.current_char)
		{
			ft_printf("\n");
			kill(g_message.client_pid, SIGUSR2);
			g_message.client_pid = 0;
			clean_message();
			return ;
		}
		else
			ft_printf("%c", g_message.current_char);
		clean_message();
	}
	kill(g_message.client_pid, SIGUSR1);
}

static void	clean_message(void)
{
	g_message.current_char = 0;
	g_message.byte_i = 0;
}
