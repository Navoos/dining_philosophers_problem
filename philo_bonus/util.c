/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:19 by yaakoub           #+#    #+#             */
/*   Updated: 2022/03/28 15:40:32 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_safely(long time, const char *str, t_philo *philo)
{
	sem_wait(philo->info->print);
	printf("%ld %d %s\n", time - philo->info->genisis, philo->id, str);
	sem_post(philo->info->print);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i += 1;
	}
	return (i);
}

int	ft_put_str(void (*color) (), const char *msg, int ret)
{
	color();
	printf("%s\n", msg);
	ft_reset();
	return (ret);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		flag;
	int		i;

	result = 0;
	flag = 1;
	i = 0;
	if (str[i] == '-')
	{
		return (-1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || i > 11)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i += 1;
	}
	if ((flag == 1 && result > INT_MAX) || (flag == -1 && result > 2147483648))
		return (-1);
	return (result * flag);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0x0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
