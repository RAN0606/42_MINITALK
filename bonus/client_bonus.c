/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:27:06 by rliu              #+#    #+#             */
/*   Updated: 2022/03/02 17:06:26 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	ft_sendmsg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[2] && i < (int)ft_strlen(argv[2]) + 1)
	{
		j = -1;
		while (++j < 8)
		{
			if (((unsigned char)argv[2][i] >> j) % 2 == 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

void	ft_getend(int sigu)
{
	if (sigu == SIGUSR2)
	{
		write (1, "MSG Received, EOF!\n", 19);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	signal(SIGUSR2, ft_getend);
	if (argc != 3)
		exit (0);
	pid = getpid();
	while (++i < 32)
	{
		if ((pid >> i) % 2 == 1)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(100);
	}
	ft_sendmsg(argv);
	pause();
}
