/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:54:00 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 17:02:55 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include "./get_next_line/get_next_line.h"
//# include "./libft/libft.h"

typedef struct s_param {
	int		x;
	int		y;
}	t_param;

typedef struct s_game {
	int		width;
	int		height;
	int		size;
	char	*map;
	//int		*player;
}	t_game;

void	put_images(void	*mlx, void *win, int target, int position, int size);
void	read_map(char *filename, t_game *game);

#endif