/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:56:58 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/13 11:57:00 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

void	handler_s1(int sig)
{
	static struct s_character	var;

	if (sig == SIGUSR1)
		var.c |= 1 << var.bit;
	var.bit++;
	if (var.bit == 8)
	{
		write(1, &var.c, 1);
		var.bit = 0;
		var.c = 0;
	}
}

int	main(int ac, char **av)
{
	char	*pid;

	(void)ac;
	(void)av;
	pid = ft_itoa(getpid());
	signal(SIGUSR1, handler_s1);
	signal(SIGUSR2, handler_s1);
	if (!pid)
		return (1);
	ft_putstr("This is the PID of the server :   ");
	ft_putstr(pid);
	ft_putstr("\n");
	while (1)
		pause();
	return (0);
}
