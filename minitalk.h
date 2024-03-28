#ifndef MINITALK_H
#define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>


// #define SIGUSR1 10
// #define SIGUSR2 12


void	client(int pid, unsigned char msg);
void server(int signal);

#endif