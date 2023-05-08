/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:54:32 by skunert           #+#    #+#             */
/*   Updated: 2023/05/08 18:51:03 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_map(t_game *game, char **map_input)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map_input[i] != NULL)
	{
		j = 0;
		x = 0;
		while (map_input[i][j] != '\0')
		{
			mlx_image_to_window(game->mlx, game->grass, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
	ft_fill_component(game, map_input, 'C', game->ball);
	ft_fill_component(game, map_input, 'P', game->trainer);
	ft_fill_component(game, map_input, 'E', game->pokemon);
	ft_fill_component(game, map_input, '1', game->tree);
}

void	ft_fill_component(t_game *game, char **map_input,
							char c, mlx_image_t *img)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map_input[i] != NULL)
	{
		j = 0;
		x = 0;
		while (map_input[i][j] != '\0')
		{
			if (map_input[i][j] == c)
				mlx_image_to_window(game->mlx, img, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
}
