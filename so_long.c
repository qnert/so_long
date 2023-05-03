/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:43:03 by skunert           #+#    #+#             */
/*   Updated: 2023/05/03 16:28:39 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook_spinnin(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img1;
	mlx_image_t		*img2;
	mlx_image_t		*img3;
	mlx_image_t		*img4;
	mlx_texture_t 	*texture_bridge;
	mlx_texture_t	*texture_sky;
	mlx_texture_t	*texture_beyblade;

	mlx = mlx_init(1400, 500, "Hammerkopf", true);
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	texture_sky = mlx_load_png("pngwing.com.png");
	texture_bridge = mlx_load_png("pngegg.png");
	texture_beyblade = mlx_load_png("output-onlinepngtools.png");
	img1 = mlx_texture_to_image(mlx, texture_sky);
	img2 = mlx_texture_to_image(mlx, texture_sky);
	img3 = mlx_texture_to_image(mlx, texture_bridge);
	img4 = mlx_texture_to_image(mlx, texture_beyblade);
	mlx_image_to_window(mlx, img1, 700, 0);
	mlx_image_to_window(mlx, img2, -80, 0);
	mlx_image_to_window(mlx, img3, -60, -50);
	mlx_image_to_window(mlx, img4, 0, 250);
	mlx_loop_hook(mlx, hook_spinnin, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
