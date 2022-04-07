/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:29:03 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/04/07 15:06:24 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitor(void	*arg)
{
	t_philo		*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->info->print);
		if (ft_get_time() > philo->last_time_eaten)
		{
			ft_red();
			printf("%ld %d died\n", philo->last_time_eaten
				- philo->info->genisis, philo->id);
			ft_reset();
			sem_post(philo->info->finish);
			return (0x0);
		}
		sem_post(philo->info->print);
	}
	return (0x0);
}

void	*check_fullness(void *args)
{
	t_info	*info;
	int		i;

	info = args;
	i = 0;
	while (i < info->n_philo)
	{
		sem_wait(info->eaten_once);
		i += 1;
	}
	sem_post(info->finish);
	return (0x0);
}

void	*check_death(void *arg)
{
	t_info	*info;
	int		i;

	info = arg;
	sem_wait(info->finish);
	i = 0;
	while (i < info->n_philo)
	{
		kill(info->philos[i].pid, SIGTERM);
		i += 1;
	}
	return (0x0);
}
