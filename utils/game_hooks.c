/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:12:57 by skunert           #+#    #+#             */
/*   Updated: 2023/05/17 19:30:40 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(void *param)
{
	t_game	*game;
	int		y;
	int		x;

	game = param;
	y = game->trainer->instances[0].y;
	x = game->trainer->instances[0].x;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		if (ft_walls_up(game) == 1)
			game->trainer->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		if (ft_walls_down(game) == 1)
			game->trainer->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		if (ft_walls_right(game) == 1)
			game->trainer->instances[0].x += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		if (ft_walls_left(game) == 1)
			game->trainer->instances[0].x -= 5;
}

void	ft_show_moves(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->moves++;
	ft_printf("%d\n", game->moves);
}

void	ft_collect(void	*param)
{
	t_game	*game;
	int		x;
	int		y;
	int		i;

	game = param;
	i = 0;
	while (i < game->tmp && game->num_of_coll > 0)
	{
		x = game->trainer->instances[0].x - game->ball->instances[i].x - 10;
		y = game->trainer->instances[0].y - game->ball->instances[i].y;
		if (ft_distance_of_points(x, y) < 35)
		{
			if (game->num_of_coll <= 1)
				mlx_delete_image(game->mlx, game->ball);
			else
				game->ball->instances[i].y -= 20000;
			game->num_of_coll--;
		}
		i++;
	}
}

void	ft_exit(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = param;
	x = game->trainer->instances[0].x - game->pokemon->instances[0].x - 10;
	y = game->trainer->instances[0].y - game->pokemon->instances[0].y;
	if (game->num_of_coll == 0 && ft_distance_of_points(x, y) < 35)
		mlx_close_window(game->mlx);
}

void	ft_all_hooks(void *param)
{
	ft_move(param);
	ft_show_moves(param);
	ft_collect(param);
	ft_exit(param);
}
