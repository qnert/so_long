/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:10 by skunert           #+#    #+#             */
/*   Updated: 2023/05/17 19:31:20 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_walls_up(void *param)
{
	t_game	*game;
	int		i;
	int		x;
	int		y;

	game = param;
	i = 0;
	x = game->trainer->instances[0].x / 50;
	y = (game->trainer->instances[0].y - 5) / 50;
	if (game->map_input[y][x] == '1')
		return (0);
	return (1);
}

int	ft_walls_down(void *param)
{
	t_game	*game;
	int		i;
	int		x;
	int		y;

	game = param;
	i = 0;
	x = game->trainer->instances[0].x / 50;
	y = game->trainer->instances[0].y / 50;
	if (game->map_input[y + 1][x] == '1')
		return (0);
	return (1);
}

int	ft_walls_left(void *param)
{
	t_game	*game;
	int		i;
	int		x;
	int		y;

	game = param;
	i = 0;
	x = (game->trainer->instances[0].x - 5) / 50;
	y = game->trainer->instances[0].y / 50;
	if (game->map_input[y][x] == '1')
		return (0);
	return (1);
}

int	ft_walls_right(void *param)
{
	t_game	*game;
	int		i;
	int		x;
	int		y;

	game = param;
	i = 0;
	x = game->trainer->instances[0].x / 50;
	y = game->trainer->instances[0].y / 50;
	if (game->map_input[y][x + 1] == '1')
		return (0);
	return (1);
}
