/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:19:19 by yaakoub           #+#    #+#             */
/*   Updated: 2022/04/07 14:38:21 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_args
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_must_eat;
	long			genisis;
}	t_args;

typedef struct s_philo
{
	int					id;
	pthread_t			core;
	pthread_mutex_t		fork;
	pthread_mutex_t		*next;
	t_args				*args;
	struct s_philo		*philosophers;
	long				judgement_day;
	int					n_meals;
	pthread_mutex_t		print_mutex;
}	t_philo;

typedef struct s_info
{
	t_philo	philo;
	t_philo	*philos;
}	t_info;

/*	colors	*/
void			ft_red(void);
void			ft_yellow(void);
void			ft_reset(void);
void			ft_green(void);
void			ft_blue(void);

/*	utils	*/
unsigned int	ft_strlen(const char *str);
int				ft_put_str(void (*color)
					(), const char *msg, int ret);
int				ft_atoi(const char *str);
long			ft_get_time(void);
void			ft_print_mutex(t_philo *philo,
					const long time, const char *str);
void			ft_usleep(long t_eat, long start_time);

/*	genisis	*/
int				ft_create_philos(t_args *args);

/*	parser	*/
int				ft_parse(t_args *args, int ac, char **av);
void			*ft_monitor(void *arg);

/*	init	*/
void			init_forks(t_philo *philo, t_args *args, int i);
int				init_life(t_philo *philo, t_args *args, long time, int i);
int				ft_init(t_args *args, int ac, char **av);
void			init_philos(t_philo *philo, t_args *args, int i);

/*	main	*/
void			*routine(void *arg);
void			exec_odd(t_philo *philo);
void			exec_even(t_philo *philo);
int				ft_create_philos(t_args *args);
#endif
