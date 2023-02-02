/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:16:47 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/02 17:15:07 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct variable
{
	int		pid;
	int		bit;
	int		i;
	int		j;
	char	str[9];
	char	buff[3];
	char	c;
}			t_var;

int		ft_atoi(const char *str);
int		cntnmb(long n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
char	put_back(char *str);
void	printer(const char *buff, int *i);

#endif