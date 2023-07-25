/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:13:56 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/24 17:45:11 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_check(t_game *game)
{
	if (game->count.player != 1 || game->count.exit != 1 || \
	game->count.item < 1)
		map_error(game);
	if (game->width * game->height != game->size)
		map_error(game);
}

void	wall_check(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (i == 0 && game->map[i][j] != '1')
				map_error(game);
			if (i == game->height - 1 && game->map[i][j] != '1')
				map_error(game);
			if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				map_error(game);
		}
	}
}
