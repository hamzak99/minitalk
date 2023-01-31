#include "minitalk.h"
#include <signal.h>

// //////////////////////////////////
// static int	cntnmb(long n)
// {
// 	int	cnt;

// 	cnt = 0;
// 	if (n < 0)
// 		n *= (-1);
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		cnt++;
// 	}
// 	return (cnt);
// }

// static char	*ifcheck(int cnt, long n)
// {
// 	char	*t;

// 	if (n == 0)
// 	{
// 		t = malloc(2 * sizeof(char));
// 		t[0] = '0';
// 		t[1] = '\0';
// 	}
// 	if (n < 0)
// 	{
// 		t = malloc((cnt + 2) * sizeof(char));
// 		t[0] = '-';
// 		t[cnt + 1] = '\0';
// 	}
// 	else if (n > 0)
// 	{
// 		t = malloc((cnt + 1) * sizeof(char));
// 		t[cnt] = '\0';
// 	}
// 	return (t);
// }

// static char	*fill(char *tab, int cnt, long nb)
// {
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		while (cnt > 0)
// 		{
// 			tab[cnt--] = nb % 10 + '0';
// 			nb /= 10;
// 		}
// 	}
// 	else if (nb > 0)
// 	{
// 		cnt--;
// 		while (cnt >= 0)
// 		{
// 			tab[cnt--] = nb % 10 + '0';
// 			nb /= 10;
// 		}
// 	}
// 	return (tab);
// }

// char	*ft_itoa(int n)
// {
// 	char	*tab;
// 	long	nb;
// 	int		cnt;

// 	nb = n;
// 	cnt = cntnmb(nb);
// 	tab = ifcheck(cnt, n);
// 	if (!tab)
// 		return (NULL);
// 	tab = fill(tab, cnt, nb);
// 	return (tab);
// }
// //////////////////////////////////

// int	power(int os)
// {
// 	int	i;
// 	int	rsl;

// 	i = 0;
// 	rsl = 1;
// 	while (i++ < os)
// 	{
// 		rsl *= 2;
// 	}
// 	return (rsl);
// }

// char	put_back(char *str)
// {
// 	int	i;
// 	int	os;
// 	int	rsl;

// 	i = 0;
// 	os = 0;
// 	rsl = 0;
// 	while (i <= 7)
// 	{
// 		if (str[i] == '0')
// 			os++;
// 		else
// 		{
// 			rsl = rsl + power(os);
// 			os++;
// 		}
// 		i++;
// 	}
// 	return (rsl);
// }
// void	freestr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 8)
// 		str[i++] = 0;
// }
int	cnt_many1(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			cnt++;
		i++;
	}
	return (cnt);
}
void	renistialize(int *bit, int *i, int *j)
{
	*bit = 0;
	*i = 0;
	*j = 0;
}
void printer(const char *buff,int *i)
{
	write(1, &buff[0], 1);
	write(1, &buff[1], 1);
	write(1, &buff[2], 1);
	write(1, &buff[3], 1);
	*i = 0;
}
void	handler_sv(int signal, siginfo_t *info, void *nu)
{
	static var vars;
	// static int	pid;
	// static int	bit;
	// static int	i;
	// static int	j;
	// static char	str[9];
	// static char	buff[3];
	// char		c;

	if (info->si_pid != vars.pid)
		renistialize(&vars.bit, &vars.i, &vars.j);
	if (signal == SIGUSR1)
		vars.str[vars.i] = '0';
	if (signal == SIGUSR2)
		vars.str[vars.i] = '1';
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
				printer(vars.buff,&vars.j);
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
