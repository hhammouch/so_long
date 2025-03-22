/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:04:25 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/22 01:18:05 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	size;
	
	size = game->tile_size;
	game->wall = mlx_xpm_file_to_image(game->mlx, "rec/wall.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx, "rec/player.xpm", &size, &size);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "rec/collectible.xpm",&size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "rec/exit.xpm", &size, &size);
	game->empty = mlx_xpm_file_to_image(game->mlx, "rec/empty.xpm", &size,&size);
	if (!game->wall || !game->empty || !game->player || !game->exit || !game->collectible)
		print_error("Failed to load textures.");
}

void	put_tile_to_window(t_game *game, int x, int y, void *tile)
{
	mlx_put_image_to_window(game->mlx, game->win, tile,
		x * game->tile_size, y * game->tile_size);
}
void	map_rendder(t_game *game)
{
	int	y;
	int	x;
	
	y = 0;
	mlx_clear_window(game->mlx,game->win);
	while(y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
					put_tile_to_window(game, x, y, game->wall);
			else if (game->map[y][x] == '0')
				put_tile_to_window(game, x, y, game->empty);
			else if (game->map[y][x] == 'P')
				put_tile_to_window(game, x, y, game->player);
			else if (game->map[y][x] == 'E')
				put_tile_to_window(game, x, y, game->exit);
			else if (game->map[y][x] == 'C')
				put_tile_to_window(game, x, y, game->collectible);
			x++;
		}
		y++;
	}
}
