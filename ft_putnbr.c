/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:51:17 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 13:55:11 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(long n, t_vars *vars)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', vars);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, vars);
		ft_putchar(nb % 10 + '0', vars);
	}
	else
	{
		ft_putchar(nb + '0', vars);
	}
	return (nb);
}
