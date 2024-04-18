#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>

void	client(int pid, unsigned char msg);
void server(int signal);
int	ft_atoi(const char *str);
void ft_putnbr(int n);
void ft_putchar(char s);

#endif