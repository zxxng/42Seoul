/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 17:02:46 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(void	*mlx, void *win, int target, int idx, int size)
{
	void	*image;
	int		wi;
	int		hi;
	int		x;
	int		y;

	if (target == '0')
		image = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &wi, &hi);
	else if (target == '1')
		image = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wi, &hi);
	else if (target == 'C')
		image = mlx_xpm_file_to_image(mlx, "./images/item.xpm", &wi, &hi);
	else if (target == 'E')
		image = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &wi, &hi);
	else if (target == 'P')
		image = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &wi, &hi);
	x = idx / size;
	y = idx % size;
	mlx_put_image_to_window(mlx, win, image, x * 60, y * 60);
}

void	game_init(t_game *game)
{
	game->width = 1;
	game->height = 1;
	game->size = 0;
	game->map = malloc(1);
	if (!game->map)
		return ;
	game->map[0] = '\0';
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	game_init(game);
	if (!game)
		return ;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->height == 1)
			game->width = ft_strlen(line) - 2;
		game->height++;
		game->map = ft_strjoin(game->map, line);
		game->size = game->width * game->height + 1;
		free(line);
	}
	close(fd);
}
