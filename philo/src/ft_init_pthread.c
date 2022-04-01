/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pthread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:13:15 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/02 00:18:01 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_forks(t_table *table)
{
	int	i;

	table->mutex = malloc(sizeof(pthread_mutex_t) * table->count);
	if (!table->mutex)
		return (1);
	i = -1;
	while (++i < table->count)
		pthread_mutex_init(&table->mutex[i], NULL);
	pthread_mutex_init(&table->security, NULL);
	return (0);
}

int	ft_init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->count);
	table->pthreads = malloc(sizeof(pthread_t) * table->count);
	if (!table->philos || !table->pthreads)
		return (1);
	i = -1;
	while (++i < table->count)
	{
		table->philos[i].id = i;
		table->philos[i].end = &table->end;
		table->philos[i].count = table->count;
		table->philos[i].death_time = table->death_time;
		table->philos[i].sleep_time = table->sleep_time;
		table->philos[i].eat_time = table->eat_time;
		table->philos[i].lfork = &table->mutex[i % table->count];
		table->philos[i].rfork = &table->mutex[(i + 1) % table->count];
		table->philos[i].security = &table->security;
		table->philos[i].times_ate = 0;
		table->philos[i].last_meal = ft_get_ms();
	}
	return (0);
}
