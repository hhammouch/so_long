/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:04:25 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/22 02:52:43 by hhammouc         ###   ########.fr       */
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
int	close_game(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->map)
		free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
int	handle_keypress(int key, t_game *game)
{
	if (key == 53)
		close_game(game);
	else if (key == 123)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == 124)
		move_player(game, game->player_x + 1, game->player_y);
	else if (key == 126)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == 125)
		move_player(game, game->player_x, game->player_y + 1);
	return (0);
}
void	handle_events(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0L << 0, close_game, game);
}