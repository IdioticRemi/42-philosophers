/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:48:24 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/31 18:52:41 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t    ft_get_ms()
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    ft_sleep(long ms)
{
    uint64_t    start;

    start = ft_get_ms();
    while (ft_get_ms() < start + ms)
        usleep(100);
}

void    ft_print(t_philo *philo, char *action)
{
    pthread_mutex_lock(&philo->table->printlock);
    printf("[ %6llu ] %d %s\n", ft_get_ms() - philo->table->start, philo->id, action);
    pthread_mutex_unlock(&philo->table->printlock);
}
