/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pthread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:13:15 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/31 20:30:45 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_forks(t_table *table)
{
    int i;
    
    table->mutex = malloc(sizeof(pthread_mutex_t) * table->count);
    table->forks = malloc(sizeof(int) * table->count);
    if (!table->mutex || !table->forks)
        return (1);
    i = -1;
    while (++i < table->count)
    {
        pthread_mutex_init(&table->mutex[i], NULL);
        table->forks[i] = UNUSED;
    }
    pthread_mutex_init(&table->printlock, NULL);
    return (0);
}

int ft_init_philos(t_table *table)
{
    int i;

    table->philos = malloc(sizeof(t_philo) * table->count);
    table->pthreads = malloc(sizeof(pthread_t) * table->count);
    if (!table->philos || !table->pthreads)
        return (1);
    i = -1;
    while (++i < table->count)
    {
        (&table->philos[i])->id = i;
        (&table->philos[i])->times_ate = 0;
        (&table->philos[i])->last_meal = ft_get_ms();
        (&table->philos[i])->table = table;
    }
    return (0);
}
