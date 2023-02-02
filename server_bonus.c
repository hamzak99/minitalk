/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:43 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/02 17:14:30 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>

// //////////////////////////////////

void	renistialize(int *bit, int *i, int *j)
{
	*bit = 0;
	*i = 0;
	*j = 0;
}

void	checker(siginfo_t *info, t_var *vars, int signal)
{
	(void)info;
	if (vars->pid != info->si_pid)
		renistialize(&vars->bit, &vars->i, &vars->j);
	if (signal == SIGUSR1)
		vars->str[vars->i] = '0';
	if (signal == SIGUSR2)
		vars->str[vars->i] = '1';
}

void	handler_sv(int signal, siginfo_t *info, void *nu)
{
	static t_var	vars;

	(void)nu;
	checker(info, &vars, signal);
	vars.i++;
	vars.bit++;
	if (vars.bit == 8)
	{
		vars.str[8] = '\0';
		vars.c = put_back(vars.str);
		if (vars.c >= 0 && vars.c <= 127)
			write(1, &vars.c, 1);
		else
		{
			vars.buff[vars.j++] = vars.c;
			if (vars.j == 4)
				printer(vars.buff, &vars.j);
		}
		vars.i = 0;
		vars.bit = 0;
	}
	vars.pid = info->si_pid;
}

void	signl(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = &handler_sv;
	sign.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
}

int	main(void)
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
