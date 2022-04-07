/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genisis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:48:42 by yaakoub           #+#    #+#             */
/*   Updated: 2022/04/07 14:38:05 by yakhoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long t_eat, long start_time)
{
	usleep(t_eat * 1000 * 0.95);
	while (ft_get_time() - start_time < t_eat)
	{
	}
}
