/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:39 by skunert           #+#    #+#             */
/*   Updated: 2023/05/10 09:36:25 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libs/libs.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stddef.h>
# include <errno.h>

//struct to get all the infos
typedef struct Game
{
	mlx_t			*mlx;
	int				width;
	int				height;
	int				num_of_coll;
	int				tmp;
	int				moves;
	char			**map_input;
	int				**tree_coordinates;
	mlx_image_t		*pokemon;
	mlx_image_t		*ball;
	mlx_image_t		*trainer;
	mlx_image_t		*tree;
	mlx_image_t		*grass;
}	t_game;

//struct for all game vars
//check map | check rectangle |input to matrix
void	free_arr(char **arr);
int		ft_check_file_type(char *str);
char	**ft_check_map_file(char *str);
int		check_map_rectangle(char **matrix);
char	**ft_check_map(char *str);

//check map components of the matrix
int		ft_check_walls(char **matrix);
int		ft_check_component(char **matrix, int comp);
int		ft_check_wrong_comp(char **matrix);
int		ft_check_double_newline(char *str);

//game related funcs
t_game	*ft_game_init(char **map_input);
void	ft_get_imgs(t_game *game);
int		ft_distance_of_points(int x, int y);
int		ft_game_begin(t_game *game, char **map_input);

//game hooks
void	ft_move(void *param);
void	ft_collect(void	*param);
void	ft_exit(void *param);
void	ft_all_hooks(void *param);

//fill the map
void	ft_fill_map(t_game *game);
void	ft_fill_component(t_game *game, char c, mlx_image_t *img);

//walls funcs
void	ft_create_matrix_xy(t_game *game);
void	ft_fill_matrix(t_game *game);
#endif