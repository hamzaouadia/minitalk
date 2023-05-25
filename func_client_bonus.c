/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:50:04 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/20 00:50:08 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		if (nbr > LONG_MAX && signe > 0)
			return (-1);
		if (nbr > LONG_MAX && signe < 0)
			return (0);
		i++;
	}
	return (nbr * signe);
}
