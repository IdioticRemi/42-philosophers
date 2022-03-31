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
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>

# define USAGE_STR "./table philo_qty death_time \
eat_time sleep_time [eat_thresold]"
# define ARG_ERR_STR "arguments must be numbers and be positive"

# define USED	0
# define UNUSED	1

struct s_philo;

typedef struct s_table
{
	int	count;

	int	death_time;
	int	eat_time;
	int	sleep_time;

	int	min_eat;
	pthread_mutex_t printlock;

	uint64_t		start;
	struct s_philo	*philos;
	pthread_t		*pthreads;
	pthread_mutex_t	*mutex;
}	t_table;

typedef struct s_philo
{
	int			id;
	int			times_ate;
	uint64_t	last_meal;
	t_table		*table;
}	t_philo;

// Main sources
int			ft_error(char *err, char *dsc);
int			ft_process_args(int argc, char **argv, t_table *table);
int			ft_init_forks(t_table *table);
int 		ft_init_philos(t_table *table);
void 		ft_wait_pthreads(t_table *table);
int			ft_create_pthreads(t_table *table);
void    	*ft_philo_main(void *philo_ptr);
uint64_t    ft_get_ms();
void    	ft_print(t_philo *philo, char *action);
void    	ft_sleep(long ms);

// Utils
size_t		ft_strlen(char *s);
int			ft_isdigit(char c);
int			ft_isnumber(char *s);
int			ft_atoi(char *nptr);

#endif