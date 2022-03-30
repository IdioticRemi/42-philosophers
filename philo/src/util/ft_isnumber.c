/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:18:10 by tjolivea          #+#    #+#             */
/*   Updated: 2022/03/30 16:18:11 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnumber(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (!ft_isdigit(*(s++)))
			return (0);
	return (1);
}
