#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

typedef struct variable
{
	int	pid;
	int	bit;
	int	i;
	int	j;
	char	str[9];
	char	buff[3];
	char		c;
} var;

int	ft_atoi(const char *str);
char	put_back(char *str);

#endif