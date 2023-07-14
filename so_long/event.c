/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:12:07 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/14 16:10:25 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	int	i;

	game->x = -1;
	game->y = -1;
	i = 0;
	while (i > game->height)
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	printf("x : %d y : %d\n", game->x, game->y);
	return (0);
}
