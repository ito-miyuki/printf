/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2023/11/22 13:36:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	print_char(int c)
{
	return (write(1, &c, sizeof(char)));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if(!str)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		while (*str != '\0')
		{
			print_char((int)*str);
			count++;
			str++;
		}	
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}
int	print_u_int(unsigned int n)
{
    int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < 10)
		return (print_char(symbols[n]));
	else
	{
		count = print_u_int(n / 10);
		return (count + print_u_int(n % 10));
	}
}
int	print_hexa_upper(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_hexa_upper(n / base, base);
		return (count + print_hexa_upper(n % base, base));
	}
}

int	print_ptraddress(long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
		return (print_char(symbols[n]));
	else
	{
		count = print_ptraddress(n / 16);
		return (count + print_ptraddress(n % 16));
	}
}
int print_ptr(long n)
{
	int count;

	count += write (1, "0x", 2);
	return (count + print_ptraddress(n));
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, unsigned int), 10);
	else if (specifier == 'u')
		count += print_u_int(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += print_hexa_upper((long)va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		count += print_char('%');
	else if (specifier == 'p')
		count += print_ptr((long)va_arg(ap, void*));
	else
		count += write(1, &specifier, 1);
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
			count += print_format(*(++str), ap);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
/*
int main()
{
	int	test;
	test = ft_printf("%u\n", -42);
	ft_printf("How many chars: %d\n", test);
	test = printf("%u\n", -42);
	printf("How many chars: %d\n", test);
}
*/