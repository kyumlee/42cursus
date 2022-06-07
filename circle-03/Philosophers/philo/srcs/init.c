/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:00:28 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/06 17:30:53 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	init_all(int argc, char **argv, t_all *all)
{
	if (argc != 5 && argc != 6)
		return (0);
	all->num_of_philos = ft_atoi(argv[1]);
	if (all->num_of_philos < 1 || all->num_of_philos > 200)
		return (0);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (all->time_to_die < 60 || all->time_to_eat < 60
		|| all->time_to_sleep < 60)
		return (0);
	all->num_must_eat = -1;
	if (argc == 6)
		all->num_must_eat = ft_atoi(argv[5]);
	if (argc == 6 && all->num_must_eat < 1)
		return (0);
	all->done = 0;
	all->time = 0;
	pthread_mutex_init(&all->status, NULL);
	return (1);
}

int	init_philo(t_all *all)
{
	int	i;

	all->philo = malloc(sizeof(t_philo) * all->num_of_philos);
	if (!all->philo)
		return (0);
	i = -1;
	while (++i < all->num_of_philos)
	{
		all->philo[i].id = i;
		all->philo[i].l_fork = i;
		all->philo[i].r_fork = (i + 1) % all->num_of_philos;
		all->philo[i].last_eat_time = 0;
		all->philo[i].eat_count = 0;
		pthread_mutex_init(&all->philo[i].protect, NULL);
		all->philo[i].all = all;
	}
	return (1);
}

int	init_forks(t_all *all)
{
	int	i;

	all->fork = malloc(sizeof(pthread_mutex_t) * all->num_of_philos);
	if (!all->fork)
		return (0);
	i = -1;
	while (++i < all->num_of_philos)
		pthread_mutex_init(&all->fork[i], NULL);
	return (1);
}

int	init(int argc, char **argv, t_all *all)
{
	if (!init_all(argc, argv, all))
		return (0);
	if (!init_philo(all))
		return (0);
	if (!init_forks(all))
		return (0);
	return (1);
}
