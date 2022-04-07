/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhoudr <yakhoudr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:31:01 by yakhoudr          #+#    #+#             */
/*   Updated: 2022/03/28 15:40:35 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_parse(t_info	*args, int ac, char **av)
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
