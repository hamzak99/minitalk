/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:35:29 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/30 22:35:30 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac < 2)
		return (0);
	pid_s = ft_atoi(av[1]);
	while (av[2][j] != '\0')
	{
		i++;
		hexa_byt((unsigned char)av[2][j++], pid_s);
	}
	if (i == strlen(av[2]))
		printf("\n------recerved------\n");
	printf("\n\n%d", getpid());
	return (0);
}
