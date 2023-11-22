/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:04:36 by mito              #+#    #+#             */
/*   Updated: 2023/11/22 15:03:37 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(long n)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	return (count + print_ptraddress(n));
}

/*
int	print_ptr(long n)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	return (count + print_digit(n, 16));
}
*/
