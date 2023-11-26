/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:12:26 by mito              #+#    #+#             */
/*   Updated: 2023/11/26 12:51:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_int(unsigned int n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < 10)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_u_int(n / 10);
		if (count < 0)
			return (-1);
		return (count + print_u_int(n % 10));
	}
}
