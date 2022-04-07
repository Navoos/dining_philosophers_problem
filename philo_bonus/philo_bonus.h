/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:39:50 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/03/28 15:43:20 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_info
{
	int							n_philo;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							n_must_eat;
	long						genisis;
	sem_t						*forks;
	sem_t						*print;
	sem_t						*finish;
	sem_t						*eaten_once;
	struct s_philo				*philos;	
}	t_info;

typedef struct s_philo
{
	pid_t					pid;
	int						n_meals;
	int						id;
	long					last_time_eaten;
	struct s_info			*info;
}	t_philo;

/*	COLORS   */
void	ft_red(void);
void	ft_yellow(void);
void	ft_reset(void);

/* 	UTILS		 */
int		ft_put_str(void (*color) (), const char *msg, int ret);
int		ft_atoi(const char *str);
long	ft_get_time(void);
void	print_safely(long time, const char *str, t_philo *philo);

/*	MONITOR	*/
void	*check_death(void *arg);
void	*check_fullness(void *args);
void	*ft_monitor(void *arg);

/*	PARSER	*/
int		ft_parse(t_info	*args, int ac, char **av);

#endif
