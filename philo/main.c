/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:16:41 by yaakoub           #+#    #+#             */
/*   Updated: 2022/04/07 14:30:37 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exec_even(t_philo *philo)
{
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is thinking");
	pthread_mutex_lock(&philo->fork);
	ft_print_mutex(philo, ft_get_time()
		- philo->args->genisis, "has taken a fork");
	pthread_mutex_lock(philo->next);
	ft_print_mutex(philo, ft_get_time()
		- philo->args->genisis, "has taken a fork");
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is eating");
	ft_usleep(philo->args->time_to_eat, ft_get_time());
	philo->judgement_day = ft_get_time() + philo->args->time_to_die;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next);
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is sleeping");
	ft_usleep(philo->args->time_to_sleep, ft_get_time());
}

void	exec_odd(t_philo *philo)
{
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is thinking");
	pthread_mutex_lock(philo->next);
	ft_print_mutex(philo, ft_get_time()
		- philo->args->genisis, "has taken a fork");
	pthread_mutex_lock(&philo->fork);
	ft_print_mutex(philo, ft_get_time()
		- philo->args->genisis, "has taken a fork");
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is eating");
	ft_usleep(philo->args->time_to_eat, ft_get_time());
	philo->judgement_day = ft_get_time() + philo->args->time_to_die;
	pthread_mutex_unlock(philo->next);
	pthread_mutex_unlock(&philo->fork);
	ft_print_mutex(philo, ft_get_time() - philo->args->genisis, "is sleeping");
	ft_usleep(philo->args->time_to_sleep, ft_get_time());
}

int	ft_create_philos(t_args *args)
{
	t_philo		*philo;
	pthread_t	monitor;
	int			i;

	philo = malloc(sizeof(t_philo) * args->n_philo);
	if (!philo)
		ft_put_str(ft_red, "ERROR : Malloc failed\n", 0);
	init_philos(philo, args, 0);
	init_forks(philo, args, 0);
	init_life(philo, args, ft_get_time(), 0);
	pthread_create(&monitor, 0x0, ft_monitor, philo);
	pthread_join(monitor, 0);
	i = 0;
	while (i < args->n_philo)
	{
		pthread_detach(philo[i].core);
		i += 1;
	}
	free(philo);
	return (1);
}

int	main(int ac, char **av)
{
	static t_args	args;

	if (ac != 5 && ac != 6)
		return (ft_put_str(ft_red, "ERROR : invalid arguments\n", 1));
	if (!ft_init(&args, ac, av))
		return (1);
	if (!ft_create_philos(&args))
		return (1);
	return (0);
}
