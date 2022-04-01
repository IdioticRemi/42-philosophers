/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:44:51 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/02 00:12:50 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_uint64	ft_get_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(long ms)
{
	t_uint64	start;

	start = ft_get_ms();
	while (ft_get_ms() < start + ms)
		usleep(100);
}

void	ft_print(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->security);
	if (*philo->end == 0)
		printf("%llu %d %s\n", ft_get_ms() - get_start(), philo->id, action);
	pthread_mutex_unlock(philo->security);
}
