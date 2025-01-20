/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:10:06 by sithomas          #+#    #+#             */
/*   Updated: 2025/01/20 11:38:22 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CAP_HEX "0123456789ABCDEF"
# define SMALL_HEX "0123456789abcdef"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_putncount_nbr(int n);
int	ft_putncount_ptr(size_t nb);
int	ft_putncount_unsigned_nbr(unsigned int n);
int	ft_putncount_char(char c);
int	ft_putncount_nbr_hex(unsigned int nb, char *hextype);
int	ft_putncount_str(char *s);

/*
Test*/

#endif