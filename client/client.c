/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:09:51 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/20 19:15:40 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	await_confirmation(void);
static void	confirmation_signal_handler(int signal);
static void	exit_signal_handler(int signal);
static void	send_message(int pid, char *msg);

static volatile t_client	g_client = {0, 0};

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (EXIT_FAILURE);
	signal(SIGUSR1, confirmation_signal_handler);
	signal(SIGUSR2, exit_signal_handler);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}

static void	confirmation_signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		g_client.server_confirmation = 1;
		g_client.bits_count++;
	}
}

static void	exit_signal_handler(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("%u bytes sent successfully!\n", g_client.bits_count / 8);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(int pid, char *msg)
{
	unsigned int	byte_i;
	unsigned char	current_char;

	while (*msg)
	{
		byte_i = 8;
		current_char = *msg++;
		while (byte_i--)
		{
			g_client.server_confirmation = 0;
			if ((current_char >> byte_i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			await_confirmation();
		}
	}
	byte_i = 8;
	while (byte_i--)
	{
		g_client.server_confirmation = 0;
		kill(pid, SIGUSR1);
		await_confirmation();
	}
}

// TODO improve this code
// ! pause() is not working properly
// ! infinite loop is not the best way too handle this too
static void	await_confirmation(void)
{
	while (!g_client.server_confirmation)
		;
}
