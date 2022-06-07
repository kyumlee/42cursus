/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:52:31 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:54:53 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_textures(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		all->textures[i].img.img = mlx_xpm_file_to_image(
				all->mlx.mlx,
				all->textures[i].path,
				&all->textures[i].img.width,
				&all->textures[i].img.height);
		all->textures[i].img.data = mlx_get_data_addr(
				all->textures[i].img.img,
				&all->textures[i].img.bpp,
				&all->textures[i].img.size_l,
				&all->textures[i].img.endian);
		free(all->textures[i].path);
		if (!all->textures[i].img.img)
			ft_error("Wrong texture filename");
		i++;
	}
}

int		select_texture(t_ray *ray)
{
	if (is_ray_facing_up(ray->angle) && !ray->was_hit_vert)
		return (0);
	else if (is_ray_facing_down(ray->angle) && !ray->was_hit_vert)
		return (1);
	else if (is_ray_facing_left(ray->angle) && ray->was_hit_vert)
		return (2);
	else
		return (3);
}
