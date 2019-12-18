/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:20:18 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 12:29:19 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_flag(int *k, char c, t_vars *vars)
{
	while ((*k)-- > 0)
		ft_putchar(c, vars);
}

static void	ft_precision(int *i, int *j, long long *xvalue, t_vars *vars)
{
	if ((vars->digit || vars->star || vars->minus || vars->zero)
	&& !vars->isnegative)
	{
		if (*xvalue == 0 && !vars->prec && vars->wdth >= vars->len)
			(*i)++;
		print_flag(i, ' ', vars);
	}
	if (vars->prec >= vars->len)
		print_flag(j, '0', vars);
	if (*xvalue == 0 && !vars->prec)
	{
		if (*xvalue == 0 && !vars->prec && vars->wdth >= vars->len
		&& vars->isnegative)
			(*i)++;
		print_flag(i, ' ', vars);
		return ;
	}
	ft_dectohexa(*xvalue, vars, 0);
	if (vars->isnegative)
		print_flag(i, ' ', vars);
}

static void	ft_notprecision(int *i, int *j, long long *xvalue, t_vars *vars)
{
	if ((vars->digit || vars->star) && !vars->isnegative)
	{
		if (*xvalue == 0 && !vars->prec)
			(*i)++;
		print_flag(i, ' ', vars);
	}
	if (vars->zero && !vars->minus)
		print_flag(i, '0', vars);
	if (vars->point)
		print_flag(j, '0', vars);
	if (*xvalue == 0 && !vars->prec)
		return ;
	ft_dectohexa(*xvalue, vars, 0);
	if ((vars->digit || vars->star || vars->minus) && vars->isnegative)
		print_flag(i, ' ', vars);
}

void		ft_xvalue(char type, va_list args, t_vars *vars)
{
	long long	xvalue;
	int			i;
	int			j;

	j = 0;
	i = 0;
	vars->counter = 0;
	vars->type = type;
	xvalue = (long long)va_arg(args, int);
	ft_dectohexa(xvalue, vars, 1);
	vars->len = vars->counter;
	if (vars->wdth > vars->counter)
		i = vars->wdth - vars->counter;
	if (vars->prec >= vars->counter)
	{
		i = vars->wdth - vars->prec;
		j = vars->prec - vars->counter;
	}
	if (vars->isprecision)
		ft_precision(&i, &j, &xvalue, vars);
	else
		ft_notprecision(&i, &j, &xvalue, vars);
}
