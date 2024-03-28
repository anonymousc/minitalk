#include "minitalk.h"


void sighn(int signum)
{
	printf("test siginturrpt %d", signum);
}
int main()
{
	while (1)
	{
	signal(SIGINT,sighn);
		sleep(1);
	}
	
}