/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:03:38 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:24:13 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	setup(t_all *all, int ac, char *av[])
{
	if (!(ac == 2))
		ft_error("Wrong number of arguments");
	parse(all, av[1]);
	set_all_rest(all);
	set_mlx(all, "cub3D");
	set_img(all);
	set_player(all);
	set_rays(all);
	load_textures(all);
	set_sprites(all);
}

void	update(t_all *all)
{
	move_player(all);
	cast_all_rays(all);
}

void	render(t_all *all)
{
	clear_img(all);
	render_wall_projection(all);
	render_sprite_projection(all);
	render_map(all);
	render_player(all);
	render_rays(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	mlx_do_sync(all->mlx.mlx);
}

int		main_loop(t_all *all)
{
	update(all);
	render(all);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_all	all;

	setup(&all, argc, argv);
	mlx_hook(all.mlx.win, 2, 0, &key_press, &all);
	mlx_hook(all.mlx.win, 3, 0, &key_release, &all);
	mlx_hook(all.mlx.win, 17, 0, &quit_program, &all);
	mlx_loop_hook(all.mlx.mlx, &main_loop, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
