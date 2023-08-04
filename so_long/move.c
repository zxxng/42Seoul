/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:02:52 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/01 12:59:46 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	if (game->y < 1 || game->map[game->y - 1][game->x] == '1')
		return ;
	if (game->map[game->y - 1][game->x] == 'E')
	{
		if (!game->count.item)
		{
			game->move++;
			exit_so_long(game);
		}
		return ;
	}
	game->move++;
	if (game->map[game->y - 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->y--;
		game->count.item--;
		draw_map(game);
		return ;
	}
	game->map[game->y][game->x] = '0';
	game->map[game->y - 1][game->x] = 'P';
	game->y--;
	draw_map(game);
}

void	move_s(t_game *game)
{
	if (game->y + 1 > game->height || game->map[game->y + 1][game->x] == '1')
		return ;
	if (game->map[game->y + 1][game->x] == 'E')
	{
		if (!game->count.item)
		{
			game->move++;
			exit_so_long(game);
		}
		return ;
	}
	game->move++;
	if (game->map[game->y + 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->y++;
		game->count.item--;
		draw_map(game);
		return ;
	}
	game->map[game->y][game->x] = '0';
	game->map[game->y + 1][game->x] = 'P';
	game->y++;
	draw_map(game);
}

void	move_a(t_game *game)
{
	if (game->x < 1 || game->map[game->y][game->x - 1] == '1')
		return ;
	if (game->map[game->y][game->x - 1] == 'E')
	{
		if (!game->count.item)
		{
			game->move++;
			exit_so_long(game);
		}
		return ;
	}
	game->move++;
	if (game->map[game->y][game->x - 1] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
		game->x--;
		game->count.item--;
		draw_map(game);
		return ;
	}
	game->map[game->y][game->x] = '0';
	game->map[game->y][game->x - 1] = 'P';
	game->x--;
	draw_map(game);
}

void	move_d(t_game *game)
{
	if (game->x > game->width || game->map[game->y][game->x + 1] == '1')
		return ;
	if (game->map[game->y][game->x + 1] == 'E')
	{
		if (!game->count.item)
		{
			game->move++;
			exit_so_long(game);
		}
		return ;
	}
	game->move++;
	if (game->map[game->y][game->x + 1] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
		game->x++;
		game->count.item--;
		draw_map(game);
		return ;
	}
	game->map[game->y][game->x] = '0';
	game->map[game->y][game->x + 1] = 'P';
	game->x++;
	draw_map(game);
}
