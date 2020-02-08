/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charperc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:52:48 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/02/08 18:33:35 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifperc(t_struct *f)
{
	int				nb;

	nb = f->width - 1;
	if (f->minus == 0 && f->width)
	{
		if (f->zero == 1)
			printzero(f, nb);
		else
			printspace(f, nb);
	}
	if (f->minus == 1 && f->width)
	{
		ft_putchar('%');
		printspace(f, nb);
	}
	else
		ft_putchar('%');
	f->printed++;
}

void	ifchar(t_struct *f, va_list ap)
{
	unsigned char	c;
	int				nb;

	nb = f->width - 1;
	c = (unsigned char)va_arg(ap, int);
	if (f->minus == 0 && f->width)
	{
		if (f->zero == 1)
			printzero(f, nb);
		else if (!f->zero)
			printspace(f, nb);
	}
	if (f->width && f->minus == 1)
	{
		ft_putchar(c);
		printspace(f, nb);
	}
	else
		ft_putchar(c);
	f->printed++;
}
