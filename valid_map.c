/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:39:42 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/30 01:27:23 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	components_count(char **map, int *c_count, int *p_count, int *e_count)
{
	int	i;
	int	j;

	i = 0;
	*c_count = 0;
	*p_count = 0;
	*e_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				(*c_count)++;
			else if (map[i][j] == 'P')
				(*p_count)++;
			else if (map[i][j] == 'E')
				(*e_count)++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				print_error("Map contains invalid characters");
			j++;
		}
		i++;
	}
}

void	components_check(char **map, t_game *game)
{
	int	collectible_count;
	int	player_count;
	int	exit_count;

	components_count(map, &collectible_count, &player_count, &exit_count);
	if (player_count != 1)
		er_ex("Map must have exactly one player (P)", game);
	if (collectible_count < 1)
		er_ex("Map must have at lest one collectible (C)", game);
	if (exit_count != 1)
		er_ex("Map must have exactly one exit (E)", game);
}

int	is_wall(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	valid_map(char **map, t_game *game)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != row_len)
			print_error("Map is not rectangular.");
		i++;
	}
	i = 0;
	while (map[i])
	{
		if ((i == 0 || map[i + 1] == NULL) && !is_wall(map[i]))
			er_ex("Top or Bottom row is not properly enclosed by walls", game);
		if (map[i][0] != '1' || map[i][row_len - 1] != '1')
			er_ex("Left or Right side wall is missing at row index", game);
		i++;
	}
	components_check(map, game);
	check_windows_size(game);
	if (!is_path_accessible(map, 0, 0, 0))
		er_ex("Cannot reach all collectibles or exit", game);
}
