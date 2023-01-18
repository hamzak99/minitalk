#include"minitalk.h"

// //////////////////////////////////
static int	cntnmb(long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ifcheck(int cnt, long n)
{
	char	*t;

	if (n == 0)
	{
		t = malloc(2 * sizeof(char));
		t[0] = '0';
		t[1] = '\0';
	}
	if (n < 0)
	{
		t = malloc((cnt + 2) * sizeof(char));
		t[0] = '-';
		t[cnt + 1] = '\0';
	}
	else if (n > 0)
	{
		t = malloc((cnt + 1) * sizeof(char));
		t[cnt] = '\0';
	}
	return (t);
}

static char *fill(char *tab,int cnt, long nb)
{
    if (nb < 0)
	{
		nb *= -1;
		while (cnt > 0)
		{
			tab[cnt--] = nb % 10 + '0';
			nb /= 10;
		}
	}
	else if (nb > 0)
	{
		cnt--;
		while (cnt >= 0)
		{
			tab[cnt--] = nb % 10 + '0';
			nb /= 10;
		}
	}
    return tab;
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nb;
	int		cnt;

	nb = n;
	cnt = cntnmb(nb);
	tab = ifcheck(cnt, n);
	if(!tab)
		return NULL;
    tab = fill(tab, cnt, nb);
	return (tab);
}
// //////////////////////////////////


int power(int os)
{
	int i;

	i = 0;
	int rsl = 1;
	while (i++ < os)
	{
		rsl *= 2;
	}
	return rsl;
}

char put_back(char *str)
{
	int i = 0;
	int os = 0;
	int rsl = 0;
	while (i <= 7)
	{
		if(str[i] == '0')
			os++;
		else
		{
			rsl = rsl + power(os);
			os++;
		}
		i++;
	}
	// printf("%c",rsl);
	return rsl;
}
#include<string.h>
void	handler_sv(int signal, siginfo_t *info, void *nu)
{
	static int	bit;
	static int	i;
	char *str;
	char c;

	if (signal == SIGUSR1)
	{
		// write(1,"0",1);
		// str[7 - i] = '0';
		// write(1,&str[7 - i], 1);
		// write(1, ft_itoa(7 - i),1);
		i = i * 10;
		i += 0;
	}
	if (signal == SIGUSR2)
	{
		// write(1,"1",1);
		// str[7 - i] = '1';
		// write(1,&str[7 - i], 1);
		// write(1,ft_itoa(7 - i),1);
		i = i * 10;
		i += 1;
	}
	// write(1, &str[0], 1);
	// write(1, str, 9);
	// write(1, "\n",1);
	// str[7] = '\0';
	// write(1,&i,1);
	// write(1,"\n",1);
	// write(1,&bit,1);
	// write(1,ft_itoa(i),9);
	// i++;
	bit++;
	if (bit == 8)
	{
		c = 0;
		str = NULL;
		str = ft_itoa(i);
		c = put_back(str);
		write(1,&c,1);
		i = 0;
		bit = 0;
	}
}
void ft_handle()
{
    printf("sss -> %d\n",c);
}

void signl(void)
{
	struct sigaction sign;

	sign.sa_sigaction = &handler_sv;
	sign.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sign, NULL) == -1)
		printf("Failed in SIGUSR1\n");
	if (sigaction(SIGUSR2, &sign, NULL) == -1)
		printf("Failed in SIGUSR2\n");
}

int main(int argc, char const *argv[])
{
    int pid = getpid();
    printf("%d\n",pid);
    while(1)
	{
		signl();
        pause();
	}
    return 0;
}

// int main(int argc, char const *argv[])
// {
// 	char *str = "10000110";
// 	char c = put_back(str);
// 	write(1,&c,1);
// 	return 0;
// }
