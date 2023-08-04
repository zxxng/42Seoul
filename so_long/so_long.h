/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:54:00 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/04 14:30:28 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "lib/mlx/mlx.h"
# include "lib/libft/get_next_line.h"

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
	int		size;
	char	**map;
	t_count	count;
	int		x;
	int		y;
	int		move;
}	t_game;

typedef struct s_check {
	t_count	count;
	int		flag;
	int		**visit;
}	t_check;

// main
int		error_message(char *type);
void	free_map(t_game *game, char *type);
void	read_map(char *filename, t_game *game);
void	draw_map(t_game *game);

// valid check
void	valid_check(t_game *game);
void	count_chars(t_game *game);
void	count_check(t_game *game);
void	wall_check(t_game *game);
void	escape_check(t_game *game);

// key_press
int		key_press(int keycode, t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
int		exit_game(t_game *game);
int		exit_window(t_game *game);
void	exit_so_long(t_game *game);

#endif
