#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <limits.h>
// include <threads.h>
static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
void	client(int pid, unsigned char msg)
{
	int i = 8;

	unsigned char tmp;
	if (pid <= 1 || pid > INT_MAX)
	{
		write(2,"\e[31mINVALID PID\e[0m",22);
		exit(1);
	}
	while (i-- > 0)
	{
		tmp = msg >> i;
		if(tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
		    kill(pid, SIGUSR1);
		usleep(400);
	}
}
	
	
int main(int ac,char *av[]) 
{
	int i = 0;
	if(ac != 3)
	{
		write(2,"\e[31mUSAGE ",12);
		write(2 , av[0],ft_strlen(av[0]));
		 write(2 ," [PID] [TXT]\e[0m",17);
		exit(1);
	}
	else
	{
		while (av[2][i])
			client(atoi(av[1]),av[2][i++]);
		client(atoi(av[1]),'\0');
	    write(1, "\033[0;32msent successfully !\e[0m",34);
	}
}