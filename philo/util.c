/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:19 by yaakoub           #+#    #+#             */
/*   Updated: 2022/02/26 13:48:09 by yaakoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int	result;
	int	flag;

	result = 0;
	flag = 1;
	if (*str == '-')
	{
		flag *= -1;
		str += 1;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		result *= 10;
		result += *str++ - '0';
	}
	return (result * flag);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0x0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
