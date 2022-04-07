/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaakoub <yaakoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:34:52 by yaakoub           #+#    #+#             */
/*   Updated: 2022/02/25 16:28:51 by yaakoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_red(void)
{
	printf("\033[1;31m");
}

void	ft_yellow(void)
{
	printf("\033[1;33m");
}

void	ft_reset(void)
{
	printf("\033[0m");
}

void	ft_green(void)
{
	printf("\033[0;32m");
}

void	ft_blue(void)
{
	printf("\033[0;34m");
}
