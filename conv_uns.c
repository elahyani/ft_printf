/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:23:16 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/18 11:14:33 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_flag(int *k, char c, t_vars *vars)
{
	while ((*k)-- > 0)
		ft_putchar(c, vars);
}

static void		ft_precision(int *i, int *j, t_vars *vars, int *leng)
{
	if ((vars->digit || vars->star || vars->minus || vars->zero)
	&& !vars->isnegative)
	{
		if (vars->zero && vars->prec < 0)
			print_flag(i, '0', vars);
		else
			print_flag(i, ' ', vars);
	}
	if (vars->prec >= *leng)
		print_flag(j, '0', vars);
	if (vars->isnegative && vars->uvalue == 0 && vars->prec == 0)
		print_flag(i, ' ', vars);
	if (vars->prec == 0 && vars->uvalue == 0)
		return ;
	ft_unbr(vars->uvalue, vars);
	if (vars->isnegative)
		print_flag(i, ' ', vars);
}

static void		ft_notprecision(int *i, int *j, t_vars *vars)
{
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(i, ' ', vars);
	if (vars->zero && !vars->minus)
		print_flag(i, '0', vars);
	if (vars->point)
		print_flag(j, '0', vars);
	if (vars->prec == 0 && vars->uvalue == 0)
		return ;
	ft_unbr(vars->uvalue, vars);
	if ((vars->digit || vars->minus || vars->star) && vars->isnegative)
		print_flag(i, ' ', vars);
}

void			ft_uvalue(va_list args, t_vars *vars)
{
	int		leng;
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->uvalue = va_arg(args, unsigned int);
	leng = ft_len(vars->uvalue);
	if (vars->wdth >= 0)
	{
		if (vars->uvalue == 0 && vars->prec == 0)
			leng = 0;
		i = vars->wdth - leng;
	}
	if (vars->prec >= leng)
	{
		i = vars->wdth - vars->prec;
		j = vars->prec - leng;
	}
	if (vars->isprecision)
		ft_precision(&i, &j, vars, &leng);
	else
		ft_notprecision(&i, &j, vars);
}
