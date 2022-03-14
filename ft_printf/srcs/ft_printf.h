/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:36:58 by rliu              #+#    #+#             */
/*   Updated: 2022/01/15 18:32:27 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <libc.h>
# include <stdarg.h>

int	pt_char(char c);
int	pt_str(char *s);
int	pt_di(int d);
int	pt_u(unsigned int u);
int	pt_p(void *p);
int	pt_x(int x);
int	pt_xmaj(int x);
int	ft_printf(const char *str, ...);

#endif
