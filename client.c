#include "minitalk.h"
#include<string.h>



// int power(int os)
// {
// 	int i;

// 	i = 0;
// 	int rsl = 1;
// 	while (i++ < os)
// 	{
// 		rsl *= 2;
// 	}
// 	return rsl;
// }
// int put_back(char *str)
// {
// 	int i = 7;
// 	int os = 0;
// 	int rsl = 0;
// 	while (i >= 0)
// 	{
// 		if(str[i] == '0')
// 			os++;
// 		else
// 		{
// 			rsl = rsl + power(os);
// 			os++;
// 		}
// 		i--;
// 	}
// 	return rsl;
// }
// char *hexa_byt(int n,int pid)
// {
// 	char *str;
// 	str = malloc(8);
// 	int i = 7;

// 	while (i >= 0)
// 	{
// 		str[i] = n % 2 + '0';
// 		i--;
// 		n = n / 2;
// 	}
// 	str[i] = '\0';
// 	return str;
// }
char *hexa_byt(int n,int pid)
{
	char *str;
	str = malloc(8);
	int i = 7;

	while (i >= 0)
	{
        str[i] = n % 2 + '0';
		if(n % 2 == 0)
        {
            // write(1,"0",1);
            kill(pid, SIGUSR1);
        }
        else    
        {
            // write(1,"1",1);
            kill(pid, SIGUSR2);
        }
		i--;
		n = n / 2;
        usleep(100);
	}
	str[i] = '\0';
    // write(1,"\n",1);
	return str;
}
void sen_msg(char c,int pid_s)
{
    kill(pid_s,SIGUSR1);
}

int main(int ac, char *av[])
{
    int pid_s;
    int i = 0, j = 0;
    char *str;
    if(ac < 2)
        return 0;
    pid_s = atoi(av[1]);
    while (av[2][j] != '\0')
    {
        i = 0;
        str = hexa_byt(av[2][j],pid_s);
        j++;
    }
    printf("\n\n%d",getpid());
    return 0;
}
