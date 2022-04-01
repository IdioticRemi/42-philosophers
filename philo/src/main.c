/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:59:16 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/01 23:12:20 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_uint64	get_start(void)
{
	static t_uint64	start = 0;

	if (!start)
		start = ft_get_ms();
	return (start);
}

static int	cleanse(t_table *table)
{
	int	i;

	if (table->mutex)
	{
		i = -1;
		while (++i < table->count)
			pthread_mutex_destroy(&table->mutex[i]);
		free(table->mutex);
	}
	free(table->philos);
	free(table->pthreads);
	pthread_mutex_destroy(&table->security);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (ft_process_args(argc, argv, &table))
		return (1);
	if (ft_init_forks(&table))
		return (1);
	if (ft_init_philos(&table))
		return (cleanse(&table) + 1);
	if (ft_create_pthreads(&table))
		return (cleanse(&table) + 1);
	ft_wait_pthreads(&table);
	return (cleanse(&table));
}
