/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_csdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:44:52 by rliu              #+#    #+#             */
/*   Updated: 2021/12/22 13:51:09 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pt_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pt_str(char *s)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		pt_char(s[i]);
		i++;
	}
	return (i);
}

int	pt_di(int d)
{
	int	i;

	i = 0;
	if (d < 0)
	{
		if (d == -2147483648)
		{
			pt_str("-2147483648");
			return (11);
		}
		else
		{
			d = -d;
			pt_char('-');
			i++;
		}
	}
	if (d >= 10)
		i = i + pt_di(d / 10);
	pt_char(d % 10 + 48);
	i++;
	return (i);
}

int	pt_u(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 10)
		i = i + pt_u(u / 10);
	pt_char(u % 10 + 48);
	i++;
	return (i);
}
