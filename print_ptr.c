/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:04:36 by mito              #+#    #+#             */
/*   Updated: 2023/11/27 12:22:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (count < 0)
		return (-1);
	if (n == 0)
	{
		count += write (1, "0", 1);
		if (count < 0)
			return (-1);
		return (count);
	}
	count += print_ptraddress(n);
	if (count < 0)
		return (-1);
	return (count);
}
