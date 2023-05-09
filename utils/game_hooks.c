/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:12:57 by skunert           #+#    #+#             */
/*   Updated: 2023/05/09 10:49:38 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		if (game->trainer->instances[0].y >= 60)
			game->trainer->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		if (game->trainer->instances[0].y <= game->height - 100)
			game->trainer->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		if (game->trainer->instances[0].x <= game->width - 100)
			game->trainer->instances[0].x += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		if (game->trainer->instances[0].x >= 50)
			game->trainer->instances[0].x -= 5;
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
	int		i;

	game = param;
	i = 0;
	while (i < game->tmp && game->num_of_coll > 0)
	{
		if (sqrt(pow(game->trainer->instances[0].x - game->ball->instances[i].x, 2) + pow(game->trainer->instances[0].y - game->ball->instances[i].y, 2)) < 25)
		{
			if (game->num_of_coll <= 1)
				mlx_delete_image(game->mlx, game->ball);
			else
				game->ball->instances[i].y -= 200000;
				game->num_of_coll--;
		}
		i++;
	}
}

void	ft_exit(void *param)
{
	t_game	*game;

	game = param;
	if (game->num_of_coll == 0 && (sqrt(pow(game->trainer->instances[0].x - game->pokemon->instances[0].x, 2) + pow(game->trainer->instances[0].y - game->pokemon->instances[0].y, 2))) < 25)
		mlx_close_window(game->mlx);
}

void	ft_all_hooks(void *param)
{
	ft_move(param);
	ft_collect(param);
	ft_exit(param);
}
