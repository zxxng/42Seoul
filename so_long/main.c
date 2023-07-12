/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:55:31 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 17:09:39 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
{
	static int	a;

	a = 0;
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("\nx: %d, y: %d\n", param->x, param->y);
	return (0);
}

int	main(int ac, char *av[])
{
	void	*mlx;
	void	*win;
	t_param	param;
	t_game	*game;
	int		i;

	param_init(&param);
	mlx = mlx_init();
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	read_map(av[1], game);
	i = 0;
	while (i < game->size)
	{
		if (game->map[i] != '\n')
			put_images(mlx, win, game->map[i], i, game->width);
		i++;
	}
	printf("read_map\n%s", game->map);
	win = mlx_new_window(mlx, game->width * 60, game->height * 60, "so_long");
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
}
