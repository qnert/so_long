/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:39 by skunert           #+#    #+#             */
/*   Updated: 2023/05/08 13:59:58 by skunert          ###   ########.fr       */
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
	mlx_image_t		*pikatchu;
	mlx_image_t		*pokeball;
	mlx_image_t		*pika_kid;
	mlx_image_t		*tree;
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
void	ft_fill_map(t_game *game, char **map_input);
int		ft_game_begin(t_game *game, char **map_input);

//game hooks
void	ft_move(void *param);
void	ft_all_hooks(void *param);

#endif