/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:43:03 by skunert           #+#    #+#             */
/*   Updated: 2023/05/05 10:51:29 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map_input;
	mlx_t	*mlx;

	if (argc == 2)
	{
		map_input = ft_check_map(argv[1]);
		mlx = NULL;
		if (map_input == NULL)
			return (0);
		if (ft_game_begin(mlx) == 0)
			return (0);
		free_arr(map_input);
	}
	return (0);
}
