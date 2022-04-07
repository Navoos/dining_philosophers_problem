/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:41:23 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/04/07 14:45:38 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>

void	ft_usleep(long t_eat, long start_time)
{
	usleep(t_eat * 1000 * 0.95);
	while (ft_get_time() - start_time < t_eat)
	{
	}
}

static int	exec_life(t_philo *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, 0x0, ft_monitor, philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->info->time_to_eat, ft_get_time());
	while (1)
	{
		sem_wait(philo->info->forks);
		print_safely(ft_get_time(), "has taken a fork", philo);
		sem_wait(philo->info->forks);
		print_safely(ft_get_time(), "has taken a fork", philo);
		print_safely(ft_get_time(), "is eating", philo);
		philo->last_time_eaten = ft_get_time() + philo->info->time_to_die;
		ft_usleep(philo->info->time_to_eat, ft_get_time());
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		print_safely(ft_get_time(), "is sleeping", philo);
		ft_usleep(philo->info->time_to_sleep, ft_get_time());
		print_safely(ft_get_time(), "is thinking", philo);
		philo->n_meals += 1;
		if (philo->n_meals == philo->info->n_must_eat)
			sem_post(philo->info->eaten_once);
	}
	return (1);
}

static int	create_philos(t_info *info, int i)
{
	while (i < info->n_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].n_meals = 0;
		info->philos[i].info = info;
		info->genisis = ft_get_time();
		info->philos[i].last_time_eaten = info->genisis + info->time_to_die;
		info->philos[i].pid = fork();
		if (info->philos[i].pid == 0)
			return (exec_life(&info->philos[i]));
		else if (info->philos[i].pid < 0)
		{
			ft_put_str(ft_red, "failed to create process", 0);
			exit(1);
		}
		i += 1;
	}
	return (1);
}

static int	ft_init(t_info *info, int ac, char **av)
{
	if (!ft_parse(info, ac, av))
		return (ft_put_str(ft_red, "ERROR : invalid input", 0));
	info->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, info->n_philo);
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	info->finish = sem_open("finish", O_CREAT | O_EXCL, 0644, 0);
	info->eaten_once = sem_open("eaten once", O_CREAT | O_EXCL, 0644, 0);
	if (info->forks == SEM_FAILED \
			|| info->print == SEM_FAILED || info->finish == SEM_FAILED)
		return (ft_put_str(ft_red, "ERROR : semaphore creation failed", 0));
	info->philos = malloc(sizeof(t_philo) * info->n_philo);
	if (!info->philos)
		return (ft_put_str(ft_red, "ERROR : malloc failed", 0));
	create_philos(info, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_info		info;
	pthread_t	monitor_thread;
	int			status;
	int			i;

	memset(&info, 0, sizeof(info));
	if (ac != 5 && ac != 6)
		return (ft_put_str(ft_red, "ERROR : invalid arguments\n", 1));
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("eaten once");
	ft_init(&info, ac, av);
	pthread_create(&monitor_thread, 0x0, check_death, &info);
	if (info.n_must_eat > 0)
		pthread_create(&monitor_thread, 0x0, check_fullness, &info);
	i = 0;
	while (i < info.n_philo)
		waitpid(info.philos[i++].pid, &status, 0);
	sem_close(info.forks);
	sem_close(info.print);
	sem_close(info.finish);
	sem_close(info.eaten_once);
	free(info.philos);
	return (0);
}
