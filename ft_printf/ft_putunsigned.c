/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 06:18:21 by hhammouc          #+#    #+#             */
/*   Updated: 2024/12/03 06:27:53 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned long	nb;
	size_t			i;
	char			nbr[11];
	int				count;

	nb = n;
	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (nb)
	{
		nbr[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &nbr[--i], 1);
		count++;
	}
	return (count);
}
