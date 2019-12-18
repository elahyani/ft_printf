/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:18:53 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/18 10:45:04 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_flag(int *i, char c, t_vars *vars)
{
	while ((*i)-- > 0)
		ft_putchar(c, vars);
}

void		ft_cvalue(va_list args, t_vars *vars)
{
	char	cvalue;
	int		i;

	i = 0;
	cvalue = (char)va_arg(args, int);
	i = vars->wdth - 1;
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(&i, ' ', vars);
	if (vars->zero && !vars->minus)
		print_flag(&i, '0', vars);
	ft_putchar(cvalue, vars);
	if ((vars->digit || vars->star || vars->minus) && vars->isnegative)
		print_flag(&i, ' ', vars);
}
