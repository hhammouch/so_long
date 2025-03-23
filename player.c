/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:03:10 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/23 00:05:32 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_collectible(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
}

int	handle_exit(t_game *game, int new_x, int new_y)
{
	int	move;

	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles > 0)
			return (0);
		ft_printf("\033[1;32m\nCongratulations! You won!\n\033[0m");
		move = game->moves + 1;
		ft_printf("\033[1;33m\n    Score: %d moves\n\n\033[0m", move);
		close_game(game);
	}
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width
		|| new_y < 0 || new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	handle_collectible(game, new_x, new_y);
	if (!handle_exit(game, new_x, new_y))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("\033[1;32mMoves: \033[0m\033[1;34m%d\033[0m\n", game->moves);
	map_rendder(game);
}
