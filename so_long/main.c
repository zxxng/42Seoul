/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:55:31 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/04 14:31:31 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_check(t_game *game)
{
	if (!game->map || game->width > 43 || game->height > 23)
		free_map(game, "size");
	count_chars(game);
	count_check(game);
	wall_check(game);
	escape_check(game);
}

int	error_message(char *type)
{
	if (ft_memcmp(type, "argc", 4) == 0)
		ft_printf("Error: Invalid %s\n", type);
	else if (ft_memcmp(type, "file", 4) == 0)
		ft_printf("Error: Invalid %s\n", type);
	else if (ft_memcmp(type, "map", 3) == 0)
		ft_printf("Error: Invalid %s\n", type);
	else if (ft_memcmp(type, "size", 4) == 0)
		ft_printf("Error: Invalid %s, this map is too big!!\n", type);
	else if (ft_memcmp(type, "malloc", 6) == 0)
		ft_printf("Error: Invalid %s\n", type);
	exit(1);
}

void	free_map(t_game *game, char *type)
{
	int	i;

	i = 0;
	while (i < game->height && game->map)
		free(game->map[i++]);
	free(game->map);
	if (ft_memcmp(type, "game", 4) == 0)
		return ;
	error_message(type);
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->size = 0;
	game->map = NULL;
	game->count.player = 0;
	game->count.exit = 0;
	game->count.item = 0;
	game->x = 0;
	game->y = 0;
	game->move = 0;
}

int	main(int ac, char *av[])
{
	t_game	*game;
	int		win_wi;
	int		win_he;
	int		file_len;

	if (ac != 2)
		error_message("argc");
	file_len = ft_strlen(av[1]);
	if (file_len < 5 || ft_memcmp(av[1] + file_len - 4, ".ber", 4) != 0)
		error_message("file");
	game = malloc(sizeof(t_game));
	if (!game)
		error_message("malloc");
	game_init(game);
	read_map(av[1], game);
	win_wi = game->width * 60;
	win_he = game->height * 60;
	game->win = mlx_new_window(game->mlx, win_wi, win_he, "./so_long");
	draw_map(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_window, game);
	mlx_loop(game->mlx);
}
