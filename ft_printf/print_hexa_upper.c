/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:25 by mito              #+#    #+#             */
/*   Updated: 2023/11/26 12:33:43 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_upper(long n, int base)
{
	int		count;
	char	*symbols;
	int fail;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		fail = write (1, "-", 1);
		if (fail < 0)
            return (-1);
		return (print_digit(-n, base) - 1);
	}
	else if (n < base)
	{
		fail = print_char(symbols[n]);
		if (fail < 0)
            return (-1);
        return (fail);
	}
	else
	{
		count = print_hexa_upper(n / base, base);
		if (count < 0)
            return (-1);
		return (count + print_hexa_upper(n % base, base));
	}
}
