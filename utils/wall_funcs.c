/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:04:41 by skunert           #+#    #+#             */
/*   Updated: 2023/05/10 09:19:51 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_matrix_xy(t_game *game)
{
	int	i;

	i = 0;
	game->tree_coordinates = malloc(sizeof(int *) * ft_check_component(game->map_input, '1'));
	while (i < ft_check_component(game->map_input, '1'))
	{
		game->tree_coordinates[i] = malloc(sizeof(int) * 2);
		i++;
	}
	game->tree_coordinates[i] = NULL;
	ft_fill_matrix(game);
}

void	ft_fill_matrix(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (game->map_input[i] != NULL)
	{
		j = 0;
		while (game->map_input[i][j] != '\0')
		{
			if (game->map_input[i][j] == '1')
			{
				game->tree_coordinates[k][0] = j;
				game->tree_coordinates[k][1] = i;
				k++;
			}
			j++;
		}
		i++;
	}
}