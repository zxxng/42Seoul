/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:03:08 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/03 17:59:13 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_check(t_game *game)
{
	if (game->count.player != 1 || game->count.exit != 1 || \
	game->count.item < 1)
		free_map(game, "map");
	if (game->width * game->height != game->size)
		free_map(game, "map");
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
				free_map(game, "map");
			if (i == game->height - 1 && game->map[i][j] != '1')
				free_map(game, "map");
			if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				free_map(game, "map");
		}
	}
}

static void	dfs(char **map, t_check *check, int col, int row)
{
	const int	nc[] = {0, 0, 1, -1};
	const int	nr[] = {1, -1, 0, 0};
	int			i;

	check->visit[col][row] = 1;
	if (map[col][row] == 'E')
	{
		check->count.exit++;
		check->flag = 0;
		return ;
	}
	if (map[col][row] == 'C')
		check->count.item++;
	i = 0;
	while (i < 4)
	{
		if (map[col + nc[i]][row + nr[i]] != '1' && \
			check->visit[col + nc[i]][row + nr[i]] == 0)
			dfs(map, check, col + nc[i], row + nr[i]);
		i++;
	}
}

static void	check_init(t_check *check, t_game *game)
{
	int	i;

	check->flag = 1;
	check->count.player = 1;
	check->count.exit = 0;
	check->count.item = 0;
	check->visit = malloc(sizeof(int *) * (game->height));
	if (!check->visit)
		free_map(game, "malloc");
	i = 0;
	while (i < game->height)
	{
		check->visit[i] = malloc(sizeof(int) * (game->width));
		if (!check->visit[i])
		{
			i = 0;
			while (check->visit[i])
				free(check->visit[i++]);
			free(check->visit);
			free_map(game, "malloc");
		}
		ft_bzero(check->visit[i], game->width * sizeof(int));
		i++;
	}
}

void	escape_check(t_game *game)
{
	t_check	*check;
	int		i;

	check = malloc(sizeof(t_check));
	if (!check)
		free_map(game, "malloc");
	check_init(check, game);
	dfs(game->map, check, game->y, game->x);
	i = 0;
	while (i < game->height)
		free(check->visit[i++]);
	free(check->visit);
	if (check->count.exit != 1 || check->flag != 0 || \
	check->count.item != game->count.item)
	{
		free(check);
		free_map(game, "map");
	}
	free(check);
}
