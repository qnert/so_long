/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:12:31 by skunert           #+#    #+#             */
/*   Updated: 2023/05/04 16:11:59 by skunert          ###   ########.fr       */
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
		return (0);
	free_arr(split_file);
	return (1);
}

int	ft_check_map_file(char *str)
{
	char				*map_input;
	char				*get_line;
	unsigned int		line_len;
	unsigned int		new_line_len;
	int					fd;

	map_input = ft_calloc(1, 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error occured: %s\n", strerror(errno)), -1);
	get_line = get_next_line(fd);
	line_len = ft_strlen(get_line);
	while (get_line != NULL)
	{
		map_input = ft_strjoin_free(map_input, get_line);
		free(get_line);
		get_line = get_next_line(fd);
		if (get_line == NULL)
			break ;
		new_line_len = ft_strlen(get_line);
		if (!ft_strchr(get_line, '\n'))
			new_line_len++;
		if (new_line_len != line_len)
			return (-1);
	}
	free(map_input);
	return (fd);
}

int	ft_check_map(char *str)
{
	int	fd;

	if (ft_check_file_type(str) == 0)
		return (-1);
	fd = ft_check_map_file(str);
	return (fd);
}
