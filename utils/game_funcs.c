/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:22:37 by skunert           #+#    #+#             */
/*   Updated: 2023/05/05 10:28:54 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_begin(mlx_t *mlx)
{
	mlx = mlx_init(1200, 600, "Gotcha!", false);
	if (mlx == NULL)
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
}
