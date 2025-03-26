/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:18:34 by hhammouc          #+#    #+#             */
/*   Updated: 2024/12/04 16:47:45 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_convert(long nb, char nbr[11])
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nbr[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	size_t	i;
	char	nbr[11];
	int		count;

	nb = n;
	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	i = ft_putnbr_convert(nb, nbr);
	while (i > 0)
	{
		write(1, &nbr[--i], 1);
		count++;
	}
	return (count);
}
