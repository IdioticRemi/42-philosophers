/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:34:28 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/02 16:23:07 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_everyone_finished(t_table *table)
{
	int	i;

	if (table->min_eat < 0)
		return (0);
	i = -1;
	pthread_mutex_lock(&table->security);
	while (++i < table->count)
	{
		if (table->philos[i].times_ate < table->min_eat)
		{
			pthread_mutex_unlock(&table->security);
			return (0);
		}
	}
	return (1);
}

static int	ft_has_ended(t_table *table, int i)
{
	if (ft_everyone_finished(table))
	{
		printf(FMT_NICE, ft_get_ms() - get_start(), table->min_eat);
		table->end = 1;
		pthread_mutex_unlock(&table->security);
		return (1);
	}
	pthread_mutex_lock(&table->security);
	if ((&table->philos[i])->last_meal + table->death_time <= ft_get_ms())
	{
		printf(FMT_DEAD, ft_get_ms() - get_start(), i + 1);
		table->end = 1;
		pthread_mutex_unlock(&table->security);
		return (1);
	}
	pthread_mutex_unlock(&table->security);
	return (0);
}

void	*ft_monitor(void *_table)
{
	t_table	*table;
	int		i;

	table = _table;
	while (1)
	{
		i = -1;
		while (++i < table->count)
		{
			if (ft_has_ended(table, i))
			{
				i = -2;
				break ;
			}
		}
		ft_sleep(3);
		if (i == -2)
			break ;
	}
	return (NULL);
}

int	ft_create_pthreads(t_table *table)
{
	int	i;

	get_start();
	i = -1;
	while (++i < table->count)
	{
		if (i % 2 == 0)
			pthread_create(&table->pthreads[i], NULL, &ft_philo_main,
				(void *) &table->philos[i]);
	}
	ft_sleep(table->count / 4);
	i = -1;
	while (++i < table->count)
	{
		if (i % 2 == 1)
			pthread_create(&table->pthreads[i], NULL, &ft_philo_main,
				(void *) &table->philos[i]);
	}
	pthread_create(&table->monitor_thread, NULL, &ft_monitor, (void *) table);
	return (0);
}

void	ft_wait_pthreads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->count)
		pthread_join(table->pthreads[i], NULL);
	pthread_join(table->monitor_thread, NULL);
}
