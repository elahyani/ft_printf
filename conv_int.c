/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:06:08 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/18 11:14:56 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_flag(int *i, char c, t_vars *vars)
{
	while ((*i)-- > 0)
		ft_putchar(c, vars);
}

static void		ft_sign(int *j, t_vars *vars)
{
	(*j)++;
	vars->ivalue *= -1;
	ft_putchar('-', vars);
}

static void		ft_precision(int *i, int *j, t_vars *vars, int *leng)
{
	if ((vars->digit || vars->star || vars->minus || vars->zero)
	&& !vars->isnegative)
	{
		if (vars->zero && vars->prec < 0)
		{
			(vars->ivalue < 0) ? ft_sign(j, vars) : 0;
			print_flag(i, '0', vars);
		}
		else
			print_flag(i, ' ', vars);
	}
	(vars->ivalue < 0) ? ft_sign(j, vars) : 0;
	(vars->prec >= *leng) ? print_flag(j, '0', vars) : 0;
	if (vars->isnegative && vars->minus && vars->ivalue == 0
	&& vars->prec == 0)
		print_flag(i, ' ', vars);
	if (vars->prec == 0 && vars->ivalue == 0)
	{
		(vars->isnegative) ? print_flag(i, ' ', vars) : 0;
		return ;
	}
	ft_putnbr(vars->ivalue, vars);
	(vars->isnegative) ? print_flag(i, ' ', vars) : 0;
}

static void		ft_notprecision(int *i, int *j, t_vars *vars, int *leng)
{
	if (vars->ivalue < 0 && vars->zero)
	{
		vars->ivalue *= -1;
		ft_putchar('-', vars);
	}
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(i, ' ', vars);
	if (vars->zero && !vars->minus)
		print_flag(i, '0', vars);
	if (vars->ivalue < 0 && vars->prec > *leng)
		ft_sign(j, vars);
	if (vars->point)
		print_flag(j, '0', vars);
	if (vars->prec == 0 && vars->ivalue == 0)
		return ;
	ft_putnbr(vars->ivalue, vars);
	if ((vars->digit || vars->minus || vars->star) && vars->isnegative)
		print_flag(i, ' ', vars);
}

void			ft_ivalue(va_list args, t_vars *vars)
{
	int		i;
	int		leng;
	int		j;

	i = 0;
	j = 0;
	vars->ivalue = va_arg(args, int);
	leng = ft_len(vars->ivalue);
	if (vars->wdth >= 0)
	{
		(vars->ivalue == 0 && vars->prec == 0) ? leng = 0 : 0;
		i = vars->wdth - leng;
	}
	if (vars->prec >= leng)
	{
		if (vars->ivalue < 0 && vars->prec >= leng)
			i = vars->wdth - vars->prec - 1;
		else
			i = vars->wdth - vars->prec;
		j = vars->prec - leng;
	}
	if (vars->isprecision)
		ft_precision(&i, &j, vars, &leng);
	else
		ft_notprecision(&i, &j, vars, &leng);
}
