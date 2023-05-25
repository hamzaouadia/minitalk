/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:10 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/16 21:14:43 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_prog(t_var *var, char **av)
{
	int	failure;
	int	pid;

	failure = 0;
	pid = ft_atoi(av[1]);
	var->i = 0;
	var->j = 0;
	while (var->i < 8)
	{
		var->j = av[2][var->k] & 1 << var->i ;
		if (var->j != 0)
			failure = kill(pid, SIGUSR1);
		else
			failure = kill(pid, SIGUSR2);
		if (failure < 0)
		{
			write(2, "(WARNING) : error occurred with kill function\n", 47);
			exit(EXIT_FAILURE);
		}
		usleep(300);
		var->i++;
	}
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac != 3)
		return (0);
	var.k = 0;
	while (av[2][var.k])
	{
		kill_prog(&var, av);
		var.k++;
	}
	return (0);
}
