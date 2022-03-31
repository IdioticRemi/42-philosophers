/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:34:28 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/31 21:01:41 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_create_pthreads(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->count)
        pthread_create(&table->pthreads[i], NULL, &ft_philo_main, 
                (void *) &table->philos[i]);
    return (0);
}

static int  ft_everyone_finished(t_table *table)
{
    int i;

    if (table->min_eat < 0)
        return (0);
    i = -1;
    while (++i < table->count)
        if ((&table->philos[i])->times_ate < table->min_eat)
            return (0);
    return (1);
}

void ft_wait_pthreads(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->count)
        pthread_detach(table->pthreads[i]);
    while (1)
    {
        i = -1;
        while (++i < table->count)
        {
            if (ft_everyone_finished(table))
            {
                pthread_mutex_lock(&table->printlock);
                printf("\x1b[32m[ %6llu ] everyone ate at least %d times.\n\x1b[0m", ft_get_ms() - table->start, table->min_eat);
                i = -2;
                break ;
            }
            if ((&table->philos[i])->last_meal + table->death_time <= ft_get_ms())
            {
                pthread_mutex_lock(&table->printlock);
                printf("\x1b[31m[ %6llu ] %d died.\n\x1b[0m", ft_get_ms() - table->start, i);
                i = -2;
                break ;
            }
        }
        if (i == -2)
            break ;
    }
}
