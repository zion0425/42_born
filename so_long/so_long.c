/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:20:14 by siokim            #+#    #+#             */
/*   Updated: 2022/07/29 14:50:42 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_event(int x, int y, t_game *game)
{
	x += game->param.x;
	y += game->param.y;
	if (game->map[y][x] == 'C')
	{
		game->e_c_p[1]--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == '1')
		return (MOVE_WALL);
	else if (game->map[y][x] == 'E')
	{
		if (game->e_c_p[1] == 0)
			exit(0);
		return (MOVE_WALL);
	}
	return (0);
}

int	player_move_event(int keycode, t_game *game)
{
	if (keycode == W)
		return (move_event(0, -1, game));
	else if (keycode == A)
		return (move_event(-1, 0, game));
	else if (keycode == S)
		return (move_event(0, 1, game));
	else if (keycode == D)
		return (move_event(1, 0, game));
	return (0);
}

void	draw_player(t_game *game, int keycode)
{
	void	*player_img;
	void	*tile_img;
	int		x_y[2];

	if (player_move_event(keycode, game) == MOVE_WALL)
		return ;
	tile_img = mlx_xpm_file_to_image(game->mlx, \
	"./xpm/tile.xpm", &x_y[0], &x_y[1]);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	tile_img, (game->param.x) * 64, (game->param.y) * 64);
	if (keycode == W)
		game->param.y--;
	else if (keycode == A)
		game->param.x--;
	else if (keycode == S)
		game->param.y++;
	else if (keycode == D)
		game->param.x++;
	game->param.move++;
	player_img = mlx_xpm_file_to_image(game->mlx, \
	"./xpm/player.xpm", &x_y[0], &x_y[1]);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	player_img, (game->param.x) * 64, (game->param.y) * 64);
	ft_printf("move : %d\n", game->param.move);
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		draw_player(game, keycode);
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{	
		ft_memset(&game, 0, sizeof(t_game));
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, 1980, 1080, "Hello World!");
		read_map(argv[1], &game);
		check_map(&game);
		mlx_hook(game.mlx_win, 2, 0, &key_event, &game);
	}
	else if (argc == 1)
		print_error("missing argv\n", 0);
	else if (argc > 2)
		print_error("multiple argv\n", 0);
}
