/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:17:24 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/11 22:17:31 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unbr(unsigned int n, t_vars *vars)
{
	if (n > 9)
	{
		ft_unbr(n / 10, vars);
		ft_putchar(n % 10 + '0', vars);
	}
	else
		ft_putchar(n + '0', vars);
	return (n);
}
