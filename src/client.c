/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:27:52 by rliu              #+#    #+#             */
/*   Updated: 2022/03/01 13:46:52 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc != 3)
		exit (0);
	while (argv[2] && i < (int)ft_strlen(argv[2]) + 1)
	{
		j = -1;
		while (++j < 8)
		{
			if (((unsigned char)argv[2][i] >> j) % 2 == 1)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(50);
		}
		i++;
	}
}
