#include"minitalk.h"



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

int put_back(char *str)
{
	int i = 7;
	int os = 0;
	int rsl = 0;
	while (i >= 0)
	{
		if(str[i] == '0')
			os++;
		else
		{
			rsl = rsl + power(os);
			os++;
		}
		i--;
	}
	return rsl;
}

void	handler_sv(int signal, siginfo_t *info, void *nu)
{
	static int	bit;
	static int	i;
	static int	old_pid;

	(void)nu;
	if (info->si_pid != old_pid)
		bit = 0;
	if (signal == SIGUSR1)
	{
		// write(1,"0",1);
		i = i * 10;
		i += 0;
	}
	if (signal == SIGUSR2)
	{
		// write(1,"1",1);
		i = i * 10;
		i += 0;
	}
	printf("((%d))\n",i);
	bit++;
	if (bit == 8)
	{
		// write(1, &i, 1);
		i = 0;
		bit = 0;
	}
	old_pid = info->si_pid;
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
    // signal(SIGUSR1,ft_handle);
    while(1)
	{
		signl();
        pause();
	}
    return 0;
}
