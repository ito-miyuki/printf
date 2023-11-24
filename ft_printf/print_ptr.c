/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:04:36 by mito              #+#    #+#             */
/*   Updated: 2023/11/24 11:29:47 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (n == 0)
	{
		return (count + write (1, "0", 1));
	}
	else if (n <= -ULONG_MAX)
	{
		return (count += write (1, "1", 1));
	}
	else if (n >= ULONG_MAX)
	{
		write (1, "ffffffffffffffff", 16);
		return (count + 16);
	}
	return (count + print_ptraddress(n));
}
