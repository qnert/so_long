/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:12:31 by skunert           #+#    #+#             */
/*   Updated: 2023/05/20 12:09:45 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_check_file_type(char *str)
{
	int		i;
	char	**split_path;
	char	**split_file;

	i = 0;
	split_path = ft_split(str, '/');
	while (split_path[i] != NULL)
		i++;
	i--;
	split_file = ft_split(split_path[i], '.');
	free_arr(split_path);
	i = 0;
	while (split_file[i] != NULL)
		i++;
	i--;
	if (ft_strncmp(split_file[i], "ber", ft_strlen(split_file[i])) != 0)
		return (free_arr(split_file), 0);
	free_arr(split_file);
	return (1);
}

char	**ft_check_map_file(char *str)
{
	char				**return_matrix;
	char				*map_input;
	char				*get_line;
	int					fd;

	map_input = ft_calloc(1, 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(map_input);
		return (ft_printf("Error occured: %s\n", strerror(errno)), NULL);
	}
	get_line = get_next_line(fd);
	while (get_line != NULL)
	{
		map_input = ft_strjoin_free(map_input, get_line);
		free(get_line);
		get_line = get_next_line(fd);
		if (get_line == NULL)
			break ;
	}
	if (ft_check_double_newline(map_input) == 0)
		return (free(map_input), NULL);
	return_matrix = ft_split(map_input, '\n');
	return (free(map_input), return_matrix);
}

int	ft_check_map_rectangle(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i] != NULL)
	{
		if (ft_strlen(matrix[0]) != ft_strlen(matrix[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**ft_check_map(char *str)
{
	char	**map_input;

	if (ft_check_file_type(str) == 0)
		return (ft_printf("Error\n"), NULL);
	map_input = ft_check_map_file(str);
	if (map_input == NULL)
		return (ft_printf("Error\n"), NULL);
	if (ft_check_map_rectangle(map_input) == 0)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_check_walls(map_input) == 0)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_check_component(map_input, 'C') == 0)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_check_component(map_input, 'E') != 1)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_check_component(map_input, 'P') != 1)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_check_wrong_comp(map_input) == 0)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	if (ft_copy_and_check(map_input) == 0)
		return (ft_printf("Error\n"), free_arr(map_input), NULL);
	return (map_input);
}
