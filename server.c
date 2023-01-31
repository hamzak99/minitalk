/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:09:14 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/30 22:09:15 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

// // //////////////////////////////////

// // //////////////////////////////////

void	renistialize(int *bit, int *i)
{
	*bit = 0;
	*i = 0;
}

void	handler_sv(int signal, siginfo_t *info, void *nu)
{
	static int	pid;
	static int	bit;
	static int	i;
	static char	str[9];
	char		c;

	if (info->si_pid != pid)
		renistialize(&bit, &i);
	if (signal == SIGUSR1)
		str[i] = '0';
	if (signal == SIGUSR2)
		str[i] = '1';
	i++;
	bit++;
	if (bit == 8)
	{
		str[8] = '\0';
		c = put_back(str);
		write(1, &c, 1);
		renistialize(&bit, &i);
	}
	pid = info->si_pid;
}

void	signl(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = &handler_sv;
	sign.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
}

int	main(int argc, char const *argv[])
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	while (1)
	{
		signl();
		pause();
	}
	return (0);
}
