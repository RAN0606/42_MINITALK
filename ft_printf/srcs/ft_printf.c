/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:40:44 by rliu              #+#    #+#             */
/*   Updated: 2022/01/15 18:31:32 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkprint(char c, va_list arglist)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (c == 'c')
		len = pt_char(va_arg(arglist, int));
	else if (c == 's')
		len = pt_str(va_arg(arglist, char *));
	else if (c == 'p')
		len = pt_p(va_arg(arglist, void *));
	else if (c == 'd' || c == 'i')
		len = pt_di(va_arg(arglist, int));
	else if (c == 'u')
		len = pt_u(va_arg(arglist, unsigned int));
	else if (c == 'x')
		len = pt_x(va_arg(arglist, int));
	else if (c == 'X')
		len = pt_xmaj(va_arg(arglist, int));
	else
		len = pt_char(c);
	return (len);
}

int	ft_printf(const	char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_checkprint(str[i + 1], arg);
			i++;
		}	
		else
			len += pt_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
