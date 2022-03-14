/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_pxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:47:23 by rliu              #+#    #+#             */
/*   Updated: 2022/01/18 13:45:18 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pt_hex(unsigned long unb, char *base)
{
	int	i;

	i = 0;
	if (unb >= 16)
		i = i + pt_hex(unb / 16, base);
	pt_char(base[unb % 16]);
	i++;
	return (i);
}

int	pt_p(void *p)
{
	unsigned long	nb;
	int				i;

	nb = (unsigned long)p;
	write(1, "0x", 2);
	i = 2;
	i = i + pt_hex(nb, "0123456789abcdef");
	return (i);
}

int	pt_x(int x)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = (unsigned int) x;
	i = pt_hex(nb, "0123456789abcdef");
	return (i);
}

int	pt_xmaj(int x)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = (unsigned int) x;
	i = pt_hex(nb, "0123456789ABCDEF");
	return (i);
}
