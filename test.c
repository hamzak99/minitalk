#include "minitalk.h"

char *hexa_byt(int n)
{
	char *str;
	str = malloc(8);
	int i = 7;

	while (i >= 0)
	{
		str[i] = n % 2 + '0';
		i--;
		n = n / 2;
	}
	str[i] = '\0';
	
	return str;
}

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
	// printf("()");
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

// int main(int ac, char *av[])
// {
// 	int i = 1;
// 	int j = 0;
// 	int n;
// 	// char *str = "hello";
// 	while (av[i][j] != '\0')
// 	{
// 		printf("%s\t",hexa_byt(av[i][j]));
// 		printf(" c-> %c\n",put_back(hexa_byt(av[i][j++])));
// 	}
// 	return 0;
// }
void sig_handler(int signum){

  //Return type of the handler function should be void
  printf("\nInside handler function\n");
}
int main()
{
   kill(pid_t)
    return 0;
}