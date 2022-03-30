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

static void	ft_parse_args(int argc, char **argv, t_philo *philo)
{
	philo->count = ft_atoi(argv[1]);
	philo->death_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	philo->min_eat = -1;
	if (argc == 6)
		philo->min_eat = ft_atoi(argv[5]);
}

int	ft_process_args(int argc, char **argv, t_philo *philo)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (ft_error("incorrect usage", USAGE_STR));
	i = 1;
	while (i < argc && ft_isnumber(argv[i]))
		i++;
	if (i != argc)
		return (ft_error("incorrect usage", ARG_ERR_STR));
	ft_parse_args(argc, argv, philo);
	return (0);
}
