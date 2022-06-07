/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:40:27 by kyumlee           #+#    #+#             */
/*   Updated: 2021/10/06 17:30:20 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define LEFT 0
# define RIGHT 1

typedef struct s_all {
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				done;
	long			time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	status;
	struct s_philo	*philo;
}					t_all;

typedef struct s_philo {
	int				id;
	pthread_t		th;
	pthread_t		mn;
	int				l_fork;
	int				r_fork;
	long			last_eat_time;
	int				eat_count;
	pthread_mutex_t	protect;
	struct s_all	*all;
}					t_philo;
/* actions.c */
int					has_taken_forks(t_all *all, t_philo *philo);
int					is_eating(t_all *all, t_philo *philo);
int					is_sleeping(t_all *all, t_philo *philo);
int					is_thinking(t_all *all, t_philo *philo);
/* atoi.c */
int					ft_atoi(char *s);
/* init.c */
int					init(int argc, char **argv, t_all *all);
/* mutex.c */
int					ft_mutex_init(pthread_mutex_t *mutex);
int					ft_mutex_lock(pthread_mutex_t *mutex);
int					ft_mutex_unlock(pthread_mutex_t *mutex);
int					ft_mutex_destroy(pthread_mutex_t *mutex);
/* run.c */
int					are_done_eating(t_all *all);
int					run(t_all *all, t_philo *philo);
/* time.c */
long				get_time(void);
long				elapsed_time(long start);
/* utils.c */
int					ft_error(void);
int					print_status(t_all *all, t_philo *philo, char *s);
int					free_all(t_all *all);
void				ft_sleep(long time);

#endif
