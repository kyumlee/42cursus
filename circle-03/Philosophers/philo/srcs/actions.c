/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:06:16 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/09 20:14:49 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	has_taken_forks(t_all *all, t_philo *philo)
{
	if (all->done)
		return (0);
	usleep(100);
	pthread_mutex_lock(&all->fork[philo->l_fork]);
	print_status(all, philo, "has taken a fork");
	if (all->num_of_philos == 1)
	{
		ft_sleep(all->time_to_die);
		pthread_mutex_unlock(&all->fork[philo->l_fork]);
	}
	pthread_mutex_lock(&all->fork[philo->r_fork]);
	print_status(all, philo, "has taken a fork");
	return (1);
}

int	is_eating(t_all *all, t_philo *philo)
{
	if (all->done)
		return (0);
	if (are_done_eating(all))
		return (0);
	pthread_mutex_lock(&philo->protect);
	philo->last_eat_time = get_time();
	print_status(all, philo, "is eating");
	ft_sleep(all->time_to_eat);
	pthread_mutex_unlock(&philo->protect);
	philo->eat_count++;
	pthread_mutex_unlock(&all->fork[philo->l_fork]);
	pthread_mutex_unlock(&all->fork[philo->r_fork]);
	return (1);
}

int	is_sleeping(t_all *all, t_philo *philo)
{
	if (all->done)
		return (0);
	print_status(all, philo, "is sleeping");
	ft_sleep(all->time_to_sleep);
	return (1);
}

int	is_thinking(t_all *all, t_philo *philo)
{
	if (all->done)
		return (0);
	print_status(all, philo, "is thinking");
	return (1);
}
