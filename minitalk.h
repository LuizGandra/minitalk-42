/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:10:03 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/01/20 19:08:17 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_message {
	unsigned int	byte_i;
	unsigned char	current_char;
	pid_t			client_pid;
}	t_message;

typedef struct s_client {
	unsigned int	bits_count;
	unsigned int	server_confirmation;
}	t_client;

#endif