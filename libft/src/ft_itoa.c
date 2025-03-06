/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:17:06 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/06 18:35:49 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_numlen(int n)
{
	size_t	len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	parse_number(long long n, char *str, size_t *i)
{
	if (n > 9)
		parse_number(n / 10, str, i);
	str[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long long	long_n;

	str = (char *)malloc(get_numlen(n) + 1);
	if (!str)
		return (NULL);
	i = 0;
	long_n = n;
	if (long_n < 0)
	{
		str[i++] = '-';
		long_n = -long_n;
	}
	parse_number(long_n, str, &i);
	str[i] = '\0';
	return (str);
}
