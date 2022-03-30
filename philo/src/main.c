/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:59:16 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/30 17:04:25 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_debug(t_philo *p)
{
	printf("PHILOSOPHERS : %d\n", p->count);
	printf("DEATH_TIME   : %d\n", p->death_time);
	printf("EAT_TIME     : %d\n", p->eat_time);
	printf("SLEEP_TIME   : %d\n", p->sleep_time);
	printf("MIN_EAT      : %d\n", p->min_eat);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (ft_process_args(argc, argv, &philo))
		return (1);
	ft_debug(&philo);
	return (0);
}
