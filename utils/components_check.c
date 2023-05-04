/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:27:40 by skunert           #+#    #+#             */
/*   Updated: 2023/05/04 17:39:40 by skunert          ###   ########.fr       */
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