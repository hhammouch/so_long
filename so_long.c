/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:43:17 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/22 02:54:20 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("\033[1;33mUsage:\033[1;37m./so_long <map.ber>");
	game.map = read_map(argv[1]);
	valid_map(game.map);
	init_game(&game);
	map_rendder(&game);
	handle_events(&game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
