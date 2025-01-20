/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:09:51 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/20 00:33:02 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static volatile	int	received_bytes;

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		received_bytes++;
	else
	{
		ft_printf("%i bytes sent successfully!\n", received_bytes / 8);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(int pid, char *msg)
{
	int		byte_i;
	char	current_char;

	while (*msg)
	{
		byte_i = 8;
		current_char = *msg++;
		while (byte_i--)
		{
			if (current_char >> byte_i & 1) // check if bit is 1
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100); // ! to avoid accumulating equal signs
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (EXIT_FAILURE);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (42)
		pause();
	return (EXIT_SUCCESS);
}
