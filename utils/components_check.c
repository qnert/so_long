/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:27:40 by skunert           #+#    #+#             */
/*   Updated: 2023/05/08 18:45:13 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_walls(char **matrix)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	j = 0;
	line_len = ft_strlen(matrix[0]);
	while (matrix[i] != NULL)
	{
		if (matrix[i][0] != '1' || matrix[i][line_len - 1] != '1')
			return (0);
		i++;
	}
	while (matrix[0][j] != '\0' && matrix[i - 1][j] != '\0')
	{
		if (matrix[0][j] != '1' || matrix[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_component(char **matrix, int comp)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == comp)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	ft_check_wrong_comp(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == '1' || matrix[i][j] == '0' ||
				matrix[i][j] == 'P' || matrix[i][j] == 'E' ||
				matrix[i][j] == 'C')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_double_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}
