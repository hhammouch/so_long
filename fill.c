/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:28:33 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/21 19:35:55 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int row, int col, int *items)
{
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	if (map[row][col] == 'C' || map[row][col] == 'E')
		(*items)++;
	map[row][col] = 'V';
	flood_fill(map ,row + 1, col, items);
	flood_fill(map ,row - 1, col, items);
	flood_fill(map ,row, col + 1, items);
	flood_fill(map ,row, col - 1, items);
}

static char	**copy_map(char **map)
{
	char	**m_copy;
	int		i;

	i = 0;
	while(map[i])
		i++;
	m_copy = malloc(sizeof(char *) * (i + 1));
	if (!m_copy)
		print_error("Allocation failed");
	i = 0;
	while (map[i])
	{
		m_copy[i] = ft_strdup(map[i]);
		if (!m_copy)
		{
			while(--i >= 0)
				free(m_copy[i]);
			free(m_copy);
			print_error("Allocation failed");
		}
		i++;
	}
	m_copy[i] = NULL;
	return (m_copy);
}

int	is_path_accessible(char **map, int y, int x, int itemes)
{
	char	**map_copy;
	int		required_items;
	int		c_count;
	int		p_count;
	int		e_count;

	map_copy = copy_map(map);
	components_count(map, &c_count, &p_count, &e_count);
	required_items = e_count + c_count;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				flood_fill(map_copy, y, x, &itemes);
				break;
			}
			x++;
		}
		y++;
	}
	free_map(map_copy);
	return (itemes == required_items);
}
