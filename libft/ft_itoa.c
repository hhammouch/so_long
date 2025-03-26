/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:35:08 by hhammouc          #+#    #+#             */
/*   Updated: 2024/10/27 11:35:09 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(long n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	long	nb;
	char	*s;

	nb = n;
	size = get_size(n);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
