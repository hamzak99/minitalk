/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:21:49 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/30 21:48:00 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int os)
{
	int	i;
	int	rsl;

	i = 0;
	rsl = 1;
	while (i++ < os)
	{
		rsl *= 2;
	}
	return (rsl);
}

char	put_back(char *str)
{
	int	i;
	int	os;
	int	rsl;

	i = 0;
	os = 0;
	rsl = 0;
	while (i <= 7)
	{
		if (str[i] == '0')
			os++;
		else
		{
			rsl = rsl + power(os);
			os++;
		}
		i++;
	}
	return (rsl);
}

static int	space(char str)
{
	if (str == ' ' || str == '\r' || str == '\f' || str == '\v' || str == '\n'
		|| str == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rsl;

	rsl = 0;
	i = 0;
	sign = 1;
	while (space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rsl = str[i] + (rsl * 10) - '0';
		i++;
	}
	return (rsl * sign);
}

