/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:22:37 by skunert           #+#    #+#             */
/*   Updated: 2023/05/20 13:17:53 by skunert          ###   ########.fr       */
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
	game->num_of_coll = ft_check_component(map_input, 'C');
	game->tmp = game->num_of_coll;
	game->moves = 0;
	game->map_input = map_input;
	return (game);
}

void	ft_get_imgs(t_game *game)
{
	mlx_texture_t	*tex_trainer;
	mlx_texture_t	*tex_pokemon;
	mlx_texture_t	*tex_ball;
	mlx_texture_t	*tex_tree;
	mlx_texture_t	*tex_grass;

	tex_grass = mlx_load_png("./textures/grass.png");
	game->grass = mlx_texture_to_image(game->mlx, tex_grass);
	mlx_delete_texture(tex_grass);
	tex_trainer = mlx_load_png("./textures/trainer.png");
	game->trainer = mlx_texture_to_image(game->mlx, tex_trainer);
	mlx_delete_texture(tex_trainer);
	tex_pokemon = mlx_load_png("./textures/charizard.png");
	game->pokemon = mlx_texture_to_image(game->mlx, tex_pokemon);
	mlx_delete_texture(tex_pokemon);
	tex_ball = mlx_load_png("./textures/ultra.png");
	game->ball = mlx_texture_to_image(game->mlx, tex_ball);
	mlx_delete_texture(tex_ball);
	tex_tree = mlx_load_png("./textures/tree.png");
	game->tree = mlx_texture_to_image(game->mlx, tex_tree);
	mlx_delete_texture(tex_tree);
}

int	ft_distance_of_points(int x, int y)
{
	int	i;
	int	j;

	i = pow(x, 2);
	j = pow(y, 2);
	return (sqrt(i + j));
}

int	ft_game_begin(t_game *game, char **map_input)
{
	game = ft_game_init(map_input);
	game->mlx = mlx_init(game->width, game->height, "Gotcha!", false);
	if (game->mlx == NULL)
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 0);
	ft_get_imgs(game);
	ft_fill_map(game);
	mlx_put_string(game->mlx, "Move counter: ", 0, 0);
	mlx_loop_hook(game->mlx, ft_all_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (1);
}
