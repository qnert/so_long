/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:12:57 by skunert           #+#    #+#             */
/*   Updated: 2023/05/08 20:44:34 by skunert          ###   ########.fr       */
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
}

void	ft_collect(void	*param)
{
	t_game	*game;
	int		i;

	game = param;
	i = 0;
	ft_printf("%d\n", game->num_of_coll);
}

void	ft_all_hooks(void *param)
{
	ft_move(param);
	ft_collect(param);
}
