#include "minitalk.h"
#include <unistd.h>
#include <stdio.h>

void	server(int signal)
{
	static char current;
	static int bits;
	current |= (signal == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (current == '\0')
			printf("\n");			
		else
		{
			write(1, &current ,1);
		}
		bits = 0;
		current = 0;
	}
	else
		current <<= 1;
}
int main()
{

	write(1 ,"\033[0;32myour server pid is : ", 38);
	ft_putnbr(getpid());
	signal(SIGUSR1,server);
	signal(SIGUSR2,server);
	printf("\n");
	while (1)
	{
		pause();
	}
}