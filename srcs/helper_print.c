/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:31:05 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/02/02 16:34:52 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printspace(t_struct *f, int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
		f->printed++;
	}
}

void	printzero(t_struct *f, int nb)
{
	while (nb > 0)
	{
		ft_putchar('0');
		nb--;
		f->printed++;
	}
}

void	widthstar(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width *= -1;
		}
		while (format[f->i] == '*')
			f->i++;
	}
}
