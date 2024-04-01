#ifndef MINITALK_H
#define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

void	client(int pid, unsigned char msg);
void server(int signal);
int	ft_atoi(const char *str);
void ft_putnbr(int n);
void ft_putchar(char s);

#endif