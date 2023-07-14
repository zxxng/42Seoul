/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:55:31 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/14 16:41:14 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	map_error(t_game *game)
{
	int	i;

	i = 0;
	while (i > game->height)
		free(game->map[i++]);
	free(game->map);
	write(1, "Error: Invalid map\n", 19);
	exit(0);
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	game->count.player = 0;
	game->count.exit = 0;
	game->count.item = 0;
	game->x = 0;
	game->y = 0;
}

int	main(int ac, char *av[])
{
	t_game	*game;
	int		win_wi;
	int		win_he;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1, "Error: Invalid malloc\n", 22);
		return (0);
	}
	game_init(game);
	read_map(av[1], game);
	win_wi = game->width * 60;
	win_he = game->height * 60;
	game->win = mlx_new_window(game->mlx, win_wi, win_he, "jaeyyoo's so_long");
	draw_map(game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(game->mlx);
}
