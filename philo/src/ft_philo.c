/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:51:40 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/02 00:20:05 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_action_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	ft_print(philo, "has taken a fork.");
	if (philo->count == 1)
	{
		pthread_mutex_unlock(philo->lfork);
		ft_sleep(philo->death_time + 10);
		return ;
	}
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(philo->security);
	philo->times_ate++;
	philo->last_meal = ft_get_ms();
	pthread_mutex_unlock(philo->security);
	ft_print(philo, "is eating.");
	ft_sleep(philo->eat_time);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

static void	ft_action_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping.");
	ft_sleep(philo->sleep_time);
}

static void	ft_action_think(t_philo *philo)
{
	ft_print(philo, "is thinking.");
}

void	*ft_philo_main(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	pthread_mutex_lock(philo->security);
	philo->last_meal = ft_get_ms();
	pthread_mutex_unlock(philo->security);
	ft_action_think(philo);
	while (1)
	{
		pthread_mutex_lock(philo->security);
		if (*philo->end == 1)
		{
			pthread_mutex_unlock(philo->security);
			break ;
		}
		pthread_mutex_unlock(philo->security);
		ft_action_eat(philo);
		ft_action_sleep(philo);
		ft_action_think(philo);
	}
	return (NULL);
}
