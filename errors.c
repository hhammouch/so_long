/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:06:15 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/30 17:55:25 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_printf("\033[1;31mError\n%s\n\033[0m", msg);
	exit(1);
}

void	er_ex(char *msg, t_game *game)
{
	ft_printf("\033[1;31mError\n%s\n\033[0m", msg);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(1);
}

void	free_exit(char *msg, char *line, char *temp)
{
	ft_printf("\033[1;31mError\n%s\n\033[0m", msg);
	free(line);
	free(temp);
	exit(1);
}

void	free_textures(char *msg, t_game *game)
{
	ft_printf("\033[1;31mError\n%s\n\033[0m", msg);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->empty)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->map)
		free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}
