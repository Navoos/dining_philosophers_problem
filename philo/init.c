/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:05:04 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/03/28 17:05:05 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, t_args *args, int i)
{
	while (i < args->n_philo)
	{
		if (i == args->n_philo - 1)
			philo[i].next = &philo[0].fork;
		else
			philo[i].next = &philo[i + 1].fork;
		i += 1;
	}
}

int	init_life(t_philo *philo, t_args *args, long time, int i)
{
	while (i < args->n_philo)
	{
		philo[i].args->genisis = time;
		philo[i].judgement_day = time + philo[i].args->time_to_die;
		if (pthread_create(&philo[i].core, 0x0, routine, &philo[i]))
			ft_put_str(ft_red, "ERROR : Thread could not be created\n", 0);
		i += 1;
	}
	return (1);
}

int	ft_init(t_args *args, int ac, char **av)
{
	if (!ft_parse(args, ac, av))
		return (ft_put_str(ft_red, "ERROR : invalid input\n", 0));
	return (1);
}

void	init_philos(t_philo *philo, t_args *args, int i)
{
	while (i < args->n_philo)
	{
		pthread_mutex_init(&philo->fork, NULL);
		pthread_mutex_init(&philo->print_mutex, NULL);
		philo[i].args = args;
		philo[i].id = i + 1;
		philo[i].n_meals = 0;
		philo[i].philosophers = philo;
		i += 1;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->id % 2 == 0)
			exec_even(philo);
		else
			exec_odd(philo);
		philo->n_meals += 1;
	}
	return (0x0);
}
