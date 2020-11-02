/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:44:14 by pmedina-          #+#    #+#             */
/*   Updated: 2020/10/31 14:02:05 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pst(t_printf *j, char *str, size_t len)
{
	j->lenstr += write(1, str, ((j->dot == '.' &&
					j->precision == 0) ? 0 : len));
}

void	printstring(t_printf *j, char *str)
{
	int		space;
	int		zero;
	size_t	len;

	str = (str == NULL) ? "(null)" : str;
	len = ft_strlen(str);
	len -= (j->precision != 0 && j->precision < len) ? (len - j->precision) : 0;
	len -= (j->precision == 0 && j->dot == '.' && j->width == 0) ? len : 0;
	len -= (j->precision == 0 && j->dot == '.' && j->width > 0
			&& j->zero_space == ' ') ? len : 0;
	space = (j->width > 0) ? j->width - len : 0;
	zero = (j->tab != '-' && j->zero_space == '0') ? j->width - len : 0;
	while (zero-- > 0 && j->tab != '-')
	{
		j->lenstr += write(1, "0", 1);
		space = 0;
	}
	while (space-- > 0 && j->tab != '-')
		j->lenstr += write(1, " ", 1);
	(j->precision == 0 && j->dot == '.' && str == 0) ? 0 : pst(j, str, len);
	if (j->tab == '-' && ++space)
	{
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
}
