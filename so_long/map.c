/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:10:20 by siokim            #+#    #+#             */
/*   Updated: 2022/07/29 11:09:12 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *err_msg, t_game *game)
{
	if (ft_strncmp(err_msg, "0", 1))
	{
		write (1, "Error\n", 6);
		write (1, err_msg, ft_strlen(err_msg));
		exit(1);
	}
	if (game->e_c_p[0] < 1 || game->e_c_p[1] < 1 || game->e_c_p[2] != 1)
		print_error("Map must have exit, collectible,\
only one starting position.\n", 0);
	draw_map(game);
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
	int	i_j[2];

	i_j[0] = -1;
	while (game->map[++i_j[0]])
	{
		i_j[1] = -1;
		while (game->map[i_j[0]][++i_j[1]])
		{
			if (game->map[i_j[0]][i_j[1]] == '0')
				drawing("./xpm/tile.xpm", game, i_j[0], i_j[1]);
			else if (game->map[i_j[0]][i_j[1]] == '1')
				drawing("./xpm/wall.xpm", game, i_j[0], i_j[1]);
			else if (game->map[i_j[0]][i_j[1]] == 'E')
				drawing("./xpm/door.xpm", game, i_j[0], i_j[1]);
			else if (game->map[i_j[0]][i_j[1]] == 'C')
				drawing("./xpm/key.xpm", game, i_j[0], i_j[1]);
			else if (game->map[i_j[0]][i_j[1]] == 'P')
				drawing("./xpm/player.xpm", game, i_j[0], i_j[1]);
			else
				print_error("only 5 possible characters\n", 0);
		}
	}
	while (--i_j[1] >= 0)
		if (game->map[i_j[0] - 1][i_j[1]] != '1')
			print_error("closed/surrounded by walls.\n", 0);
}

void	check_map(t_game *game)
{
	int		i;
	int		j_p[2];

	i = -1;
	while (game->map[++i])
	{
		j_p[0] = -1;
		while (game->map[i][++j_p[0]])
		{
			if ((i == 0 || j_p[0] == 0) && game->map[i][j_p[0]] != '1')
				print_error("closed/surrounded by walls.\n", 0);
			else if (game->map[i][j_p[0]] == 'E')
				game->e_c_p[0]++;
			else if (game->map[i][j_p[0]] == 'C')
				game->e_c_p[1]++;
			else if (game->map[i][j_p[0]] == 'P')
				game->e_c_p[2]++;
		}
		if (i != 0 && j_p[1] != j_p[0])
			print_error("The map must be rectangular.\n", 0);
		if (game->map[i][j_p[0] - 1] != '1')
			print_error("closed/surrounded by walls.\n", 0);
		j_p[1] = j_p[0];
	}
	print_error("0", game);
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
		print_error("map file error\n", 0);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			print_error("empty_line_error\n", 0);
		tmp = ft_strjoin(read_file, line);
		read_file = ft_strdup(tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(read_file, '\n');
	free(read_file);
}
