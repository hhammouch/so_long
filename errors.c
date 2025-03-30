/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:06:15 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/30 01:27:57 by hhammouc         ###   ########.fr       */
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
