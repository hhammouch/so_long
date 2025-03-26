/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:55:47 by hhammouc          #+#    #+#             */
/*   Updated: 2024/12/06 19:58:52 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(char format, va_list list)
{
	int		count;
	char	*str;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (format == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(list, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthexa(va_arg(list, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	else if (format == 'p')
		count += ft_putaddress(va_arg(list, unsigned long));
	else if (format == 's')
	{
		str = va_arg(list, char *);
		if (!str)
			str = "(null)";
		count += ft_putstr(str);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!format)
		return (-1);
	va_start(list, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += printer(format[i], list);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
