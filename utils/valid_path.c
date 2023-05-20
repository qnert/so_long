/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:21:24 by skunert           #+#    #+#             */
/*   Updated: 2023/05/20 12:08:19 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_copy_matrix(char **matrix)
{
	int		i;
	int		size;
	char	**copy;

	i = 0;
	size = 0;
	while (matrix[size] != NULL)
		size++;
	copy = malloc((size + 1) * sizeof(char *));
	while (matrix[i] != NULL)
	{
		copy[i] = ft_strdup(matrix[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_fill(char **copy, int y, int x)
{
	if (copy[y][x] == '1' || copy[y][x] == '2')
		return ;
	copy[y][x] = '2';
	ft_fill(copy, y - 1, x);
	ft_fill(copy, y + 1, x);
	ft_fill(copy, y, x - 1);
	ft_fill(copy, y, x + 1);
}

int	ft_check_valid_path(char **copy, int y, int x)
{
	ft_fill(copy, y, x);
	if (ft_check_component(copy, 'C') != 0)
		return (0);
	if (ft_check_component(copy, 'E') == 1)
		return (0);
	return (1);
}

int	ft_copy_and_check(char **map_input)
{
	int		y;
	int		x;
	int		nb;
	char	**copy;

	y = 0;
	while (map_input[y] != NULL)
	{
		x = 0;
		while (map_input[y][x] != '\0')
		{
			if (map_input[y][x] == 'P')
				break ;
			x++;
		}
		if (map_input[y][x] == 'P')
			break ;
		y++;
	}
	copy = ft_copy_matrix(map_input);
	nb = ft_check_valid_path(copy, x, y);
	return (free_arr(copy), nb);
}