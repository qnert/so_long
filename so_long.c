/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:43:03 by skunert           #+#    #+#             */
/*   Updated: 2023/05/05 09:14:07 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map_input;
	int		i;

	if (argc == 2)
	{
		i = 0;
		map_input = ft_check_map(argv[1]);
		if (map_input == NULL)
			return (0);
		while (map_input[i] != NULL)
		{
			ft_printf("%s\n", map_input[i]);
			i++;
		}
		free_arr(map_input);
	}
	return (0);
}
