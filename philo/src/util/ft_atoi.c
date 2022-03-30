/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:14:50 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/30 16:15:57 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *nptr)
{
	int	x;
	int	sign;

	if (!nptr)
		return (0);
	x = 0;
	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr && !ft_isdigit(*nptr))
	{
		sign *= ((*nptr == '+') * 1) + ((*nptr == '-') * -1);
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
		x = x * 10 + (*nptr++ - '0');
	return (sign * x);
}
