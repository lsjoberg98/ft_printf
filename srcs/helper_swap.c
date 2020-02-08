/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:16:23 by lsjoberg          #+#    #+#             */
/*   Updated: 2020/02/08 18:33:53 by lsjoberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*swap_plus_minus(char *joint, char c, int i)
{
	while (joint[i] != '+' && joint[i] != '-' && joint[i])
		i++;
	if (joint[i] == '+' || joint[i] == '-')
	{
		c = joint[i];
		joint[i] = '0';
		joint[0] = c; 
	}
	return (joint);
}

char	*swap_zero_x_l(char *joint, char c, int i)
{
	while (joint[i] != 'x' && joint[i] != 'X' && joint[i])
		i++;
	if (joint[i] == 'x' || joint[i] == 'X')
	{
		c = joint[i];
		joint[i] = '0';
		joint[1] = c; 
	}
	return (joint);
}

char	*swap_zero_x_r(char *joint, char c, int i)
{
	while (joint[i] != 'x' && joint[i] != 'X' && joint[i])
		i++;
	if (joint[i] == 'x' || joint[i] == 'X')
	{
		c = joint[i];
		joint[i] = '0';
		i = 0;
		while (joint[i] == ' ' || joint[i] == '\t' || joint[i] == '\n')
			i++;
		joint[i + 1] = c;
	}
	return (joint);
}

char	*swap_space(char *joint, char c, int i)
{
	while (joint[i] != ' ' && joint[i])
		i++;
	if (joint[i] == ' ')
	{
		c = joint[i];
		joint[i] = '0';
		joint[0] = c;
	}
	return (joint);
}
