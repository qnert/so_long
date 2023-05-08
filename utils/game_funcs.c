/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:22:37 by skunert           #+#    #+#             */
/*   Updated: 2023/05/08 14:55:28 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	*ft_game_init(char **map_input)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(1 * sizeof(t_game));
	game->width = ft_strlen(map_input[0]) * 50;
	while (map_input[i] != NULL)
		i++;
	game->height = i * 50;
	return (game);
}

void	ft_fill_map(t_game *game, char **map_input)
{
	mlx_texture_t	*tex_pika_kid;
	mlx_texture_t	*tex_pika;
	mlx_texture_t	*tex_pokeball;
	mlx_texture_t	*tex_tree;

	tex_pika_kid = mlx_load_png("./textures/pokekid.png");
	game->pika_kid = mlx_texture_to_image(game->mlx, tex_pika_kid);
	tex_pika = mlx_load_png("./textures/pikachu.png");
	game->pikatchu = mlx_texture_to_image(game->mlx, tex_pika);
	tex_pokeball = mlx_load_png("./textures/poke-ball.png");
	game->pokeball = mlx_texture_to_image(game->mlx, tex_pokeball);
	tex_tree = mlx_load_png("./textures/tree.png");
	game->tree = mlx_texture_to_image(game->mlx, tex_tree);

	if (map_input == NULL)
		ft_printf("NULL\n");
	mlx_image_to_window(game->mlx, game->pika_kid, 20, 20);
	mlx_image_to_window(game->mlx, game->pikatchu, 300, 20);
	mlx_image_to_window(game->mlx, game->pokeball, 200, 20);
	mlx_image_to_window(game->mlx, game->tree, 100, 20);
}

int	ft_game_begin(t_game *game, char **map_input)
{
	game = ft_game_init(map_input);
	game->mlx = mlx_init(game->width, game->height, "Gotcha!", false);
	if (game->mlx == NULL)
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 0);
	ft_fill_map(game, map_input);
	mlx_loop_hook(game->mlx, ft_all_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}
