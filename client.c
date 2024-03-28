#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <limits.h>

void	client(int pid, unsigned char msg)
{
	int i = 8;

	unsigned char tmp;
	
	while (i-- > 0)
	{
		tmp = msg >> i;
		if(tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
		    kill(pid, SIGUSR1);
		usleep(40);
	}
}
	
	
int main(int ac,char *av[]) 
{
	int i = 0;
	if(ac != 3)
		printf("\e[31mUSAGE %s [PID] [TXT]\e[0m",av[0]);
	else
		while (av[2][i])
			client(atoi(av[1]),av[2][i++]);
		client(atoi(av[1]),'\0');
}