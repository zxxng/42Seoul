/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:13:56 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/25 19:49:39 by jaeyyoo          ###   ########.fr       */
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

void	dfs(char **map, int **visit, int x, int y, int *exit, int *item)
{
	const int dx[] = {0, 0, 1, -1};
	const int dy[] = {1, -1, 0, 0};
	int i;

	visit[x][y] = 1;
	if (map[x][y] == 'E') {
		printf("e\n");
		(*exit)++;
	}
	if (map[x][y] == 'C') {
		printf("c\n");
		(*item)++;
	}
	i = 0;
	while (i < 4)
	{
		if (map[x + dx[i]][y + dy[i]] != '1' && \
			visit[x + dx[i]][y + dy[i]] == 0)
			dfs(map, visit, x + dx[i], y + dy[i], exit, item);
		i++;
	}
	printf("x : %d y : %d\n", y, x);
}

void	escape_check(t_game *game)
{
	int	exit;
	int	item;
	int	**visit;
	int	i;

	exit = 0;
	item = 0;
	visit = malloc(sizeof(int *) * (game->height));
	if (!visit)
		map_error(game);
	i = 0;
	while (i < game->height)
	{
		visit[i] = malloc(sizeof(int) * (game->width));
		ft_bzero(visit[i], game->width);
		//if (!visit[i])
		//{
		//	visit_free();
		//	map_error();
		//}
		i++;
	}
	dfs(game->map, visit, game->x, game->y, &exit, &item);
	printf("exit %d\nitem %d\n", exit, item);
	if (exit != 1 || item != game->count.item)
		map_error(game);
}
