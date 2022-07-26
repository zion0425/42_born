/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:13:06 by siokim            #+#    #+#             */
/*   Updated: 2022/07/26 20:17:56 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define MOVE_WALL 1

typedef struct s_param
{
	int	x;
	int	y;
	int	move;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		e_c_p[3];
	t_player	param;
}	t_game;

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	draw_map(t_game *game);
void	check_map(t_game *game);
void	read_map(char	*map_path, t_game *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
