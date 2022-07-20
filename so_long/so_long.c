/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:20:14 by siokim            #+#    #+#             */
/*   Updated: 2022/07/20 17:23:09 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
	
// }

int main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*heroes_path = "./img/heroes/knight/knight_idle_anim_f0.png";
	int		heroes_width;
	int		heroes_height;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 600, "Hello World!");
	// img = mlx_png_file_to_image(mlx, heroes_path, &heroes_width, &heroes_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	mlx_loop(mlx);
}

