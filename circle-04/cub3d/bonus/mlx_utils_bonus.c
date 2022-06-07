/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:16:48 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 17:36:57 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	set_mlx(t_all *all, char *title)
{
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, WIDTH, HEIGHT, title);
}

void	set_img(t_all *all)
{
	all->img.img = mlx_new_image(all->mlx.mlx, WIDTH, HEIGHT);
	all->img.data = mlx_get_data_addr(all->img.img,
			&all->img.bpp, &all->img.size_l, &all->img.endian);
}

void	clear_img(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			all->img.data[y * WIDTH + x] = 0x00000000;
			y++;
		}
		x++;
	}
}
