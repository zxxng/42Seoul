/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:12:07 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/01 19:31:25 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	exit_game(t_game *game)
{
	game->x = -1;
	game->y = -1;
	free_map(game, "game");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	exit_so_long(t_game *game)
{
	ft_printf("move count: %d\nfinished so_long!!\n", game->move);
	exit_game(game);
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
	return (0);
}
