/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:38:35 by hhammouc          #+#    #+#             */
/*   Updated: 2024/12/05 18:54:58 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long n)
{
	char	nbr[16];
	char	*symbols;
	int		count;
	int		i;

	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	count += 2;
	i = 0;
	while (n)
	{
		nbr[i] = symbols[n % 16];
		n /= 16;
		i++;
	}
	while (i > 0)
	{
		write(1, &nbr[--i], 1);
		count++;
	}
	return (count);
}
