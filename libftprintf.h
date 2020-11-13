/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:16:23 by pmedina-          #+#    #+#             */
/*   Updated: 2020/11/13 13:10:28 by pmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	char		*str;
	char		tab;
	char		dot;
	int			precision;
	int			lenstr;
	int			width;
	char		zero_space;
	va_list		args;
}				t_printf;

int				ft_printf(const char *s, ...);
void			initstruct(t_printf *j);
void			printchar(t_printf *j, int c);
void			printstring(t_printf *j, char *str);
void			printint(t_printf *j, int num);
void			printuns(t_printf *j, unsigned int num);
size_t			intlen(long num);
void			printhx(t_printf *j, unsigned int x);
void			printhexu(t_printf *j, unsigned int x);
void			printdir(t_printf *j, unsigned long dp);
int				hxlen(unsigned long nb);

#endif
