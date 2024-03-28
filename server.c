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
		printf("test");
		if (current == '\0')
			printf("\n");			
		else
			printf("%c\n", current);
		bits = 0;
		current = 0;
	}
	else 
		current <<= 1;
	
}
int main()
{
	printf("%d",getpid());
	// printf("test");
	signal(SIGUSR1,server);
	signal(SIGUSR2,server);
	printf("\n");
	while (1)
	{
		pause();
	}
	
}