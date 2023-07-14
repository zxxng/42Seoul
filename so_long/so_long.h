/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:54:00 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/14 16:25:27 by jaeyyoo          ###   ########.fr       */
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

typedef struct s_count {
	int	player;
	int	exit;
	int	item;
}	t_count;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	t_count	count;
	int		x;
	int		y;
}	t_game;

// main
int		map_error(t_game *game);
void	read_map(char *filename, t_game *game);
void	draw_map(t_game *game);

// key_press
int		key_press(int keycode, t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
int		exit_game(t_game *game);

#endif
