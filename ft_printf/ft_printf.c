/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2023/11/27 14:53:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (count);
}

/*
int main()
{
	//%%%
	int	test;
	int	test2;
	
	test = ft_printf("%%%", "Miyuki");
	ft_printf("How many chars: %d\n", test);
	printf("%c", '\n');
	test2 = printf("%%%", "Miyuki");
	printf("How many chars: %d\n", test2);

	//%space
	int	test5;
	int	test6;
	test5 = ft_printf("%");
	ft_printf("How many chars: %d\n", test5);
	// printf("%c", '\n');
	test6 = printf("%");
	printf("How many chars: %d\n", test6);

	//{hey%# y#}
	int	test7;
	int	test8;
	test7 = ft_printf("{hey%# y#}", "Miyuki");
	ft_printf("How many chars: %d\n", test7);
	printf("%c", '\n');
	test8 = printf("{hey%# y#}", "Miyuki");
	printf("How many chars: %d\n", test8);

	return (0);
}

*/
/*
int main(void)
{
    int	test3;
	int	test4;
	
	//test3 = ft_printf("Hello, \n%s", "Miyuki");
	test3 = ft_printf("%", "Miyuki");
	ft_printf("How many chars: %d\n", test3);
	printf("%c", '\n');
	test4 = printf("Hello, \n%s", "Miyuki");
	test4 = printf("%", "Miyuki");
	printf("How many chars: %d\n", test4);
    return (0);
}
*/