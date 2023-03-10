/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:09:42 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/02 17:12:34 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	hexa_byt(int n, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (n % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		n = n / 2;
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	int	pid_s;
	int	j;

	j = 0;
	if (ac < 2)
		return (0);
	pid_s = ft_atoi(av[1]);
	while (av[2][j] != '\0')
	{
		hexa_byt(av[2][j], pid_s);
		j++;
	}
	return (0);
}
