/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessadik <aessadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:02:31 by aessadik          #+#    #+#             */
/*   Updated: 2024/08/19 10:17:36 by aessadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"


void	server(int signal)
{
	static char current;
	static int bits;
	current |= (signal == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (current == '\0')
			ft_putchar('\n');			
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
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
}