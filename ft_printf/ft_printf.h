/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:43:02 by mito              #+#    #+#             */
/*   Updated: 2023/11/22 16:04:23 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	print_format(char specifier, va_list ap);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base);
int	print_u_int(unsigned int n);
int	print_hexa_upper(long n, int base);
int	print_ptr(long n);
int	print_ptraddress(long n);

#endif
