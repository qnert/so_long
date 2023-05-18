/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:10 by skunert           #+#    #+#             */
/*   Updated: 2023/05/18 12:38:11 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_walls_up(void *param)
{
	t_game	*game;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	game = param;
	x1 = game->trainer->instances[0].x / 50;
	y1 = (game->trainer->instances[0].y - 5) / 50;
	x2 = (game->trainer->instances[0].x + 49) / 50;
	y2 = game->trainer->instances[0].y / 50;
	if (game->map_input[y1][x1] == '1'
		|| game->map_input[y2][x2] == '1')
		return (0);
	return (1);
}

int	ft_walls_down(void *param)
{
	t_game	*game;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	game = param;
	x1 = game->trainer->instances[0].x / 50;
	y1 = game->trainer->instances[0].y / 50;
	x2 = (game->trainer->instances[0].x + 49) / 50;
	y2 = game->trainer->instances[0].y / 50;
	if (game->map_input[y1 + 1][x1] == '1'
		|| game->map_input[y2 + 1][x2] == '1')
		return (0);
	return (1);
}

int	ft_walls_left(void *param)
{
	t_game	*game;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	game = param;
	x1 = (game->trainer->instances[0].x + 49) / 50;
	y1 = (game->trainer->instances[0].y + 49) / 50;
	x2 = (game->trainer->instances[0].x + 49) / 50;
	y2 = game->trainer->instances[0].y / 50;
	if (game->map_input[y1][x1 - 1] == '1'
		|| game->map_input[y2][x2 - 1] == '1')
		return (0);
	return (1);
}

int	ft_walls_right(void *param)
{
	t_game	*game;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	game = param;
	x1 = game->trainer->instances[0].x / 50;
	y1 = game->trainer->instances[0].y / 50;
	x2 = game->trainer->instances[0].x / 50;
	y2 = (game->trainer->instances[0].y + 49) / 50;
	if (game->map_input[y1][x1 + 1] == '1'
		|| game->map_input[y2][x2 + 1] == '1')
		return (0);
	return (1);
}
