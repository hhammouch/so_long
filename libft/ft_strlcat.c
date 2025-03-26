/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:57:57 by hhammouc          #+#    #+#             */
/*   Updated: 2024/10/23 17:57:59 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= dstsize)
		return (srclen + dstsize);
	i = 0;
	j = destlen;
	while (src[i] && (i + destlen + 1) < dstsize)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (destlen + srclen);
}
