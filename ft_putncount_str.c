/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:39 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/06 12:18:34 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen_printf(char *s);

int	ft_putncount_str(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen_printf(s)));
}

static size_t	ft_strlen_printf(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
