/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:57:50 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/30 17:05:29 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define USAGE_STR "./philo philo_qty death_time \
eat_time sleep_time [eat_thresold]"
# define ARG_ERR_STR "arguments must be numbers and be positive"

typedef struct s_philo
{
	int	count;

	int	death_time;
	int	eat_time;
	int	sleep_time;

	int	min_eat;
}	t_philo;

// Main sources
int		ft_error(char *err, char *dsc);
int		ft_process_args(int argc, char **argv, t_philo *philo);

// Utils
size_t	ft_strlen(char *s);
int		ft_isdigit(char c);
int		ft_isnumber(char *s);
int		ft_atoi(char *nptr);

#endif