/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:17:34 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/06 19:18:44 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	are_done_eating(t_all *all)
{
	int	i;

	if (all->num_must_eat == -1)
		return (0);
	i = 0;
	while (i < all->num_of_philos)
	{
		if (all->philo[i].eat_count == all->num_must_eat)
			i++;
		else
			return (0);
	}
	if (i == all->num_of_philos)
	{
		all->done = 1;
		return (1);
	}
	return (0);
}

void	*thread(void *val)
{
	t_philo	*philo;
	t_all	*all;

	philo = (t_philo *)val;
	all = philo->all;
	if (philo->id % 2 && all->num_of_philos != 1)
		ft_sleep(all->time_to_eat);
	while (!all->done)
	{
		if (!has_taken_forks(all, philo))
			return (0);
		if (!is_eating(all, philo))
			return (0);
		if (!is_sleeping(all, philo))
			return (0);
		if (!is_thinking(all, philo))
			return (0);
	}
	return (0);
}

void	*monitor(void *val)
{
	t_philo	*philo;
	t_all	*all;

	philo = (t_philo *)val;
	all = philo->all;
	while (!all->done)
	{
		pthread_mutex_lock(&philo->protect);
		if (elapsed_time(philo->last_eat_time) >= all->time_to_die)
		{
			print_status(all, philo, "died");
			all->done = 1;
			pthread_mutex_unlock(&philo->protect);
			break ;
		}
		pthread_mutex_unlock(&philo->protect);
		usleep(100);
	}
	return (0);
}

int	run(t_all *all, t_philo *philo)
{
	int	i;

	i = -1;
	all->time = get_time();
	while (++i < all->num_of_philos)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&philo[i].th, NULL, thread, (void *)&philo[i]))
			return (0);
		if (pthread_create(&philo[i].mn, NULL, monitor, (void *)&philo[i]))
			return (0);
	}
	i = -1;
	while (++i < all->num_of_philos)
	{
		if (pthread_join(philo[i].th, NULL))
			return (0);
		if (pthread_join(philo[i].mn, NULL))
			return (0);
	}
	return (1);
}
