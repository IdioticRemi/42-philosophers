/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:51:40 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/31 21:14:03 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    ft_action_eat(t_philo *philo)
{
    int right;
    int left;

    left = philo->id;
    right = (philo->id + 1) % philo->table->count;
    pthread_mutex_lock(&philo->table->mutex[left]);
    ft_print(philo, "has taken a fork.");
    pthread_mutex_lock(&philo->table->mutex[right]);
    ft_print(philo, "is eating.");
    philo->times_ate++;
    philo->last_meal = ft_get_ms();
    ft_sleep(philo->table->eat_time);
    pthread_mutex_unlock(&philo->table->mutex[left]);
    pthread_mutex_unlock(&philo->table->mutex[right]);
}

static void    ft_action_sleep(t_philo *philo)
{
    ft_print(philo, "is sleeping.");
    ft_sleep(philo->table->sleep_time);
}

static void    ft_action_think(t_philo *philo)
{
    ft_print(philo, "is thinking.");
}

void    *ft_philo_main(void *philo_ptr)
{
    t_philo *philo;

    philo = philo_ptr;
    philo->last_meal = ft_get_ms();
    ft_action_think(philo);
    ft_sleep(philo->id % 2);
    while (1)
    {
        ft_action_eat(philo);
        ft_action_sleep(philo);
        ft_action_think(philo);
    }
    return (NULL);
}
