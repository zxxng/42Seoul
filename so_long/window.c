/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/24 17:42:34 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_chars(t_game *game)
{
	int	col;
	int	row;

	col = -1;
	while (++col < game->height)
	{
		row = -1;
		while (++row < game->width)
		{
			if (game->map[col][row] == 'P')
			{
				game->count.player++;
				game->x = row;
				game->y = col;
			}
			else if (game->map[col][row] == 'E')
				game->count.exit++;
			else if (game->map[col][row] == 'C')
				game->count.item++;
			game->size++;
		}
	}
	count_check(game);
	wall_check(game);
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*read_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(0);
	read_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		read_map = ft_strjoin(read_map, line);
		free(line);
	}
	close(fd);
	printf("width : %d, height : %d\n", game->width, game->height);
	game->map = ft_split(read_map, '\n');
	count_chars(game);
	free(read_map);
}

static void	put_images(t_game *game, int col, int row)
{
	void	*image;
	int		wi;
	int		hi;

	if (game->map[col][row] == '0')
		image = mlx_xpm_file_to_image(game->mlx, "./img/empty.xpm", &wi, &hi);
	else if (game->map[col][row] == '1')
		image = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &wi, &hi);
	else if (game->map[col][row] == 'C')
		image = mlx_xpm_file_to_image(game->mlx, "./img/item.xpm", &wi, &hi);
	else if (game->map[col][row] == 'E')
		image = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &wi, &hi);
	else if (game->map[col][row] == 'P')
		image = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &wi, &hi);
	mlx_put_image_to_window(game->mlx, game->win, image, row * 60, col * 60);
}

void	draw_map(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (col < game->height)
	{
		row = 0;
		while (row < game->width)
		{
			put_images(game, col, row);
			row++;
		}
		col++;
	}
}
