/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptraddress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:47 by mito              #+#    #+#             */
/*   Updated: 2023/11/22 16:14:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptraddress(long n)
{
	int		count;
	char	*symbols;
	char	*long_max;
	char	*long_min;

	symbols = "0123456789abcdef";
	long_min = "8000000000000000";
	long_max = "7fffffffffffffff";
	if (n < LONG_MIN)
	{
		print_str(long_min);
		count = 16;
	}
	else if (n > LONG_MAX)
	{
		return (print_str(long_max));
		count = 16;
	}
	else if (n < 16)
		return (print_char(symbols[n]));
	else
	{
		count = print_ptraddress(n / 16);
		return (count + print_ptraddress(n % 16));
	}
	return (count);
}
