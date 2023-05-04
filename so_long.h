/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:39 by skunert           #+#    #+#             */
/*   Updated: 2023/05/04 17:21:27 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libs/libs.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stddef.h>
# include <errno.h>

void	free_arr(char **arr);
int		ft_check_file_type(char *str);
char	**ft_check_map_file(char *str);
int		check_map_rectangle(char **matrix);
char	**ft_check_map(char *str);

#endif