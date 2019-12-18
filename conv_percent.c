/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:01:44 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/18 10:45:24 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_flag(int *i, char c, t_vars *vars)
{
	while ((*i)-- > 0)
		ft_putchar(c, vars);
}

void		ft_percent(t_vars *vars)
{
	int		i;

	i = vars->wdth - 1;
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(&i, ' ', vars);
	if (vars->zero && !vars->minus)
		print_flag(&i, '0', vars);
	ft_putchar('%', vars);
	if ((vars->digit || vars->star || vars->minus) && vars->isnegative)
		print_flag(&i, ' ', vars);
}
