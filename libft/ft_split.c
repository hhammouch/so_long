/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:09:32 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/29 16:56:08 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	count;

	i = 0;
	if (!s)
		return (0);
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*add_word(char const *s, char c)
{
	char	*p;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	check_free(char **str, size_t j)
{
	while (j > 0)
		free (str[--j]);
	free (str);
}

static char	**fill(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str[j] = add_word(&s[i], c);
			if (!str[j])
			{
				check_free(str, j);
				return (NULL);
			}
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	return (fill(s, c, str));
}
