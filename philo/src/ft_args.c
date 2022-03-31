/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:39:07 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/30 17:01:30 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_parse_args(int argc, char **argv, t_table *table)
{
	table->philos = NULL;
	table->forks = NULL;
	table->count = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	table->min_eat = -1;
	if (argc == 6)
		table->min_eat = ft_atoi(argv[5]);
}

int	ft_process_args(int argc, char **argv, t_table *table)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (ft_error("incorrect usage", USAGE_STR));
	i = 1;
	while (i < argc && ft_isnumber(argv[i]))
		i++;
	if (i != argc)
		return (ft_error("incorrect usage", ARG_ERR_STR));
	ft_parse_args(argc, argv, table);
	return (0);
}
