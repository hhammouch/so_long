/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:26 by hhammouc          #+#    #+#             */
/*   Updated: 2024/12/05 00:21:28 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putx(char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}

int	ft_puthexa(unsigned int nb, char format)
{
	int		count;
	int		i;
	char	*base;
	char	nbr[8];

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	base = ft_putx(format);
	while (nb)
	{
		nbr[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
	{
		write(1, &nbr[--i], 1);
		count++;
	}
	return (count);
}
