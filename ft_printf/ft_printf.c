/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2023/11/24 15:14:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			count += print_format(*(++str), ap);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
*/

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count += print_format(*(++str), ap);
			if (count < 0)
                return (-1);
		}
		else
		{
			count += write(1, str, 1);
			if (count < 0)
                return (-1);
		}
		str++;
	}
	va_end(ap);
	if (count == -1)
		return (-1);
	return (count);
}
/*
int main()
{
    int test;
    int test2;
    test = ft_printf("\001\002\007\v\010\f\r\n");
    printf("%c", '\n');
    ft_printf("How many chars: %d\n", test);
    printf("%c", '\n');
    test2 = printf("\001\002\007\v\010\f\r\n");
    printf("%c", '\n');
    printf("How many chars: %d\n", test2);
}
*/
