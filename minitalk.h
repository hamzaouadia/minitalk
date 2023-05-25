/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:51:23 by haouadia          #+#    #+#             */
/*   Updated: 2023/01/20 00:51:25 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

struct		s_character
{
	unsigned char	c;
	int				bit;
};

typedef struct s_client
{
	int	i;
	int	j;
	int	k;
}	t_var;

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	put_str(char *string, long long int nb, int size);
int		string_size(long long int nb);
char	*ft_itoa(int n);
void	kill_prog(t_var *var, char **av);

#endif