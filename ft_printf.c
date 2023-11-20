/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2023/11/20 14:59:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int print_char(int c)
{
    return (write(1, &c, 1));
}

int print_str(char *str)
{
    int i;

    i = 0;
    while (*str != '\0')
    {
        print_char((int)*str);
        i++;
        str++;
    }
    return (i);
}
int ft_print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        print_char(va_arg(ap, int));
    else if (specifier == 's')
        print_str(va_arg(ap, char *));
    else if (specifier == 'd')
        print_digit((long)va_arg(ap, int), 10);
    else if (specifier == 'x')
        print_digit((long)va_arg(ap, unsigned int), 16);
    else
        count += write(1, &specifier, 1); //adrees of speifier
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     count;

    va_start(ap, str);
    count = 0;
    while (*str != '\0');
    {
        if (*str == '%')
            count += ft_print_format(*(++str), ap);
        else
            count += write(1, str, 1);
        str++;
    }
    va_end(ap);
    return (count);
}

