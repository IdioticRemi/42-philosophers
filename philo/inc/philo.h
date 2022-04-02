/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:57:50 by tjolivea          #+#    #+#             */
/*   Updated: 2022/04/02 00:02:21 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define USAGE_STR "./table philo_qty death_time \
eat_time sleep_time [eat_thresold]"
# define ARG_ERR_STR "arguments must be numbers and be positive"
# define FMT_NICE "\x1b[32m%llu everyone ate at least %d times.\n\x1b[0m"
# define FMT_DEAD "\x1b[31m%llu %d died.\n\x1b[0m"

typedef unsigned long long	t_uint64;

typedef struct s_philo
{
	int				id;
	int				*end;
	int				count;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				times_ate;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*security;
	t_uint64		last_meal;
}	t_philo;

typedef struct s_table
{
	int				count;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				min_eat;
	int				end;
	t_philo			*philos;
	pthread_t		monitor_thread;
	pthread_t		*pthreads;
	pthread_mutex_t	security;
	pthread_mutex_t	*mutex;
}	t_table;

// Main sources
t_uint64	get_start(void);
int			ft_error(char *err, char *dsc);
int			ft_process_args(int argc, char **argv, t_table *table);
int			ft_init_forks(t_table *table);
int			ft_init_philos(t_table *table);
void		ft_wait_pthreads(t_table *table);
int			ft_create_pthreads(t_table *table);
void		*ft_philo_main(void *philo_ptr);
t_uint64	ft_get_ms(void);
void		ft_print(t_philo *philo, char *action);
void		ft_print2(t_philo *philo, char *a1, char *a2);
void		ft_sleep(long ms);

// Utils
size_t		ft_strlen(char *s);
int			ft_isdigit(char c);
int			ft_isnumber(char *s);
int			ft_atoi(char *nptr);

#endif
