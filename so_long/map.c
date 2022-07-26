/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:10:20 by siokim            #+#    #+#             */
/*   Updated: 2022/07/26 20:41:08 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *err_msg)
{
	write(1, "Error\n", 6);
	write(1, err_msg, ft_strlen(err_msg));
	exit(1);
}

void	drawing(char *path, t_game *game, int i, int j)
{
	void	*img;
	int		x_y[2];

	img = mlx_xpm_file_to_image(game->mlx, path, &x_y[0], &x_y[1]);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, j * 64, i * 64);
	if (!ft_strncmp(path, "./xpm/player.xpm", 16))
	{
		game->param.x = j;
		game->param.y = i;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				drawing("./xpm/tile.xpm", game, i, j);
			else if (game->map[i][j] == '1')
				drawing("./xpm/wall.xpm", game, i, j);
			else if (game->map[i][j] == 'E')
				drawing("./xpm/door.xpm", game, i, j);
			else if (game->map[i][j] == 'C')
				drawing("./xpm/key.xpm", game, i, j);
			else if (game->map[i][j] == 'P')
				drawing("./xpm/player.xpm", game, i, j);
		}
	}
}

void	check_map(t_game *game)
{
	int		i;
	int		j;
	int		prev_j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((i == 0 || j == 0) && game->map[i][j] != '1')
				print_error("closed/surrounded by walls.\n");
			else if (game->map[i][j] == 'E')
				game->e_c_p[0]++;
			else if (game->map[i][j] == 'C')
				game->e_c_p[1]++;
			else if (game->map[i][j] == 'P')
				game->e_c_p[2]++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				print_error("only 5 possible characters\n");
		}
		if (i != 0 && prev_j != j)
			print_error("The map must be rectangular.\n");
		prev_j = j;
	}
	i = -1;
	while (++i < 2)
		if (game->e_c_p[i] < 1)
			print_error("Map must have exit, collectible, starting position.\n");
	if (game->e_c_p[2] != 1)
		print_error("Map must be only one starting position.\n");
	draw_map(game);
}

void	read_map(char	*map_path, t_game *game)
{
	int		fd;
	char	*line;
	char	*read_file;
	char	*tmp;

	read_file = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(read_file, line);
		read_file = ft_strdup(tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(read_file, '\n');
	free(read_file);
}
