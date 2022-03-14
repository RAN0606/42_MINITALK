/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:52:59 by rliu              #+#    #+#             */
/*   Updated: 2022/03/01 13:50:44 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*ft_straddc(char c, char *str)
{
	size_t	len;
	char	*stra;
	int		i;

	stra = 0;
	if (!str)
		len = 1;
	else
		len = ft_strlen(str) + 1;
	stra = (char *)malloc(sizeof(char) * (len + 1));
	if (!stra)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		stra[i] = str[i];
		i++;
	}
	stra[i] = c;
	stra[++i] = '\0';
	if (str)
		free(str);
	return (stra);
}

void	action_usr(int sigu)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str;

	if (sigu == SIGUSR1)
		c = c | (1 << i);
	if (i == 7)
	{
		str = ft_straddc(c, str);
		if (c == 0 && str)
		{
			ft_putstr_fd(str, 1);
			free(str);
			str = 0;
		}
		i = -1;
		c = 0;
	}
	i++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, action_usr);
	signal(SIGUSR2, action_usr);
	while (1)
		pause();
	return (0);
}
