/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:12:26 by mito              #+#    #+#             */
/*   Updated: 2023/11/26 12:30:09 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_int(unsigned int n)
{
	int		count;
	char	*symbols;
	int	fail;

	symbols = "0123456789";
	if (n < 10)
	{
		fail = print_char(symbols[n]);
		if (fail < 0)
			return (-1);
		return (fail);
	}
	else
	{
		count = print_u_int(n / 10);
		if (count < 0)
			return (-1);
		return (count + print_u_int(n % 10));
	}
}
