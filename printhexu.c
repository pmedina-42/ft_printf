/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:02:01 by pmedina-          #+#    #+#             */
/*   Updated: 2020/11/10 13:56:15 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	transformhxmay(unsigned long x)
{
	char	c;

	if (x >= 16)
		transformhxmay(x / 16);
	x %= 16;
	c = (x < 10) ? (x + '0') : (x + 55);
	write(1, &c, 1);
}

void		printhexu(t_printf *j, unsigned long x)
{
	int		space;
	int		zero;
	int		len;

	len = hxlen(x);
	j->precision = (j->precision < 0) ? len : j->precision;
	space = j->width - ((j->precision <= len) ? len : j->precision);
	space += (x == 0 && j->precision == 0 && j->dot == '.') ? 1 : 0;
	zero = (j->precision > len) ? j->precision - len : 0;
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, (j->zero_space != '0' || (j->dot == '.' &&
						j->precision >= 0) ? " " : "0"), 1);
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	(j->precision == 0 && x == 0 && j->dot == '.')
		? 0 : transformhxmay(x);
	j->lenstr += len;
	if (j->tab == '-')
	{
		space++;
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
	if (x == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}
