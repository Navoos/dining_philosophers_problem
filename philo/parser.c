/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:05:08 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/04/07 14:30:30 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse(t_args *args, int ac, char **av)
{
	args->n_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->n_must_eat = ft_atoi(av[5]);
	if (ac == 6 && args->n_must_eat < 0)
		return (0);
	if (args->n_philo < 0 || args->n_must_eat < 0 || args->time_to_die < 0
		|| args->time_to_eat < 0 || args->time_to_sleep < 0)
		return (0);
	return (1);
}

void	lock_mutexes(t_philo *philo)
{
	int	i;
	int	n_philo;

	n_philo = philo[0].args->n_philo;
	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_lock(&philo[i++].print_mutex);
	}
}

int	check_death_and_fullness(t_philo *philo, int i, int count)
{
	int	n_philo;

	n_philo = philo[0].args->n_philo;
	while (i < philo->args->n_philo)
	{
		if (ft_get_time() > philo[i].judgement_day)
		{
			lock_mutexes(philo);
			ft_red();
			printf ("%ld %d died\n",
				philo[i].judgement_day
				- philo[i].args->genisis, philo[i].id);
			ft_reset();
			return (1);
		}
		if (philo[i].n_meals >= philo[i].args->n_must_eat
			&& philo[i].args->n_must_eat > 0)
			count += 1;
		i += 1;
	}
	if (count == n_philo)
		return (1);
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		if (check_death_and_fullness(philo, 0, 0))
			return (0x0);
	}
}

void	ft_print_mutex(t_philo *philo, const long time, const char *str)
{
	pthread_mutex_lock(&philo->print_mutex);
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->print_mutex);
}
