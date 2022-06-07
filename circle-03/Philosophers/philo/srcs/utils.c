/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:06:56 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/05 16:53:27 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_error(void)
{
	write(2, "error\n", 6);
	return (-1);
}

int	print_status(t_all *all, t_philo *philo, char *s)
{
	int		ms;

	pthread_mutex_lock(&all->status);
	if (all->done)
	{
		pthread_mutex_unlock(&all->status);
		return (0);
	}
	ms = get_time() - all->time;
	printf("%d %d %s\n", ms, philo->id + 1, s);
	pthread_mutex_unlock(&all->status);
	return (1);
}

void	ft_sleep(long time)
{
	long	start;

	start = get_time();
	while (elapsed_time(start) <= time)
		usleep(1000);
}

int	free_all(t_all *all)
{
	t_philo	*philo;
	int		i;

	philo = all->philo;
	i = -1;
	while (++i < all->num_of_philos)
	{
		pthread_mutex_destroy(&all->fork[i]);
		pthread_mutex_destroy(&philo[i].protect);
	}
	pthread_mutex_destroy(&all->status);
	free(all->fork);
	free(philo);
	return (1);
}
