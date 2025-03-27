/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:20:47 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/27 14:17:14 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Failed to initialize MiniLibX.");
	game->tile_size = 32;
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	game->collectibles = 0;
	game->moves = 0;
	count_collectibles(game);
	player_position(game);
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size, "So Long");
	if (!game->win)
		print_error("Failed to create a game window.");
	load_textures(game);
	map_rendder(game);
	handle_events(game);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x00FF00, "Moves :      0");
	mlx_loop(game->mlx);
}
