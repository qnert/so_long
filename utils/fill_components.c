/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:54:32 by skunert           #+#    #+#             */
/*   Updated: 2023/05/17 17:39:29 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (game->map_input[i] != NULL)
	{
		j = 0;
		x = 0;
		while (game->map_input[i][j] != '\0')
		{
			mlx_image_to_window(game->mlx, game->grass, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
	ft_fill_component(game, '1', game->tree);
	ft_fill_component(game, 'C', game->ball);
	ft_fill_component(game, 'P', game->trainer);
	ft_fill_component(game, 'E', game->pokemon);
}

void	ft_fill_component(t_game *game, char c, mlx_image_t *img)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_input[i] != NULL)
	{
		j = 0;
		while (game->map_input[i][j] != '\0')
		{
			if (game->map_input[i][j] == c)
				mlx_image_to_window(game->mlx, img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
