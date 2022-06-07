/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:45:47 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/06 19:20:33 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	main(int argc, char **argv)
{
	t_all	all;

	memset(&all, 0, sizeof(all));
	if (!init(argc, argv, &all))
		return (ft_error());
	if (!run(&all, all.philo))
	{
		free_all(&all);
		return (-1);
	}
	free_all(&all);
	return (0);
}
