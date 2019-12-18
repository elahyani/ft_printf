/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:25:51 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 22:13:44 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_flag(int *i, char c, t_vars *vars)
{
	while ((*i)-- > 0)
		ft_putchar(c, vars);
}

static void		ft_precision(int *i, int *j, t_vars *vars, int *leng)
{
	if ((vars->digit || vars->star || vars->minus || vars->zero)
	&& !vars->isnegative)
	{
		if (vars->pvalue == 0 && vars->wdth > *leng && vars->prec == 0)
			(*i)++;
		if (vars->zero && vars->prec >= 0)
			print_flag(i, ' ', vars);
		else if (!vars->zero)
			print_flag(i, ' ', vars);
	}
	ft_putchar('0', vars);
	ft_putchar('x', vars);
	(vars->zero && !vars->minus) ? print_flag(i, '0', vars) : 0;
	(vars->prec >= *leng) ? print_flag(j, '0', vars) : 0;
	if (vars->prec == 0 && vars->pvalue == 0)
	{
		if (vars->isnegative && vars->wdth > *leng)
		{
			(*i)++;
			print_flag(i, ' ', vars);
		}
		return ;
	}
	ft_dectohexa_p(vars->pvalue, 'x', vars, 0);
	(vars->isnegative) ? print_flag(i, ' ', vars) : 0;
}

void			ft_notprecision(int *i, int *j, t_vars *vars)
{
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(i, ' ', vars);
	ft_putchar('0', vars);
	ft_putchar('x', vars);
	(vars->zero && !vars->minus) ? print_flag(i, '0', vars) : 0;
	(vars->point) ? print_flag(j, '0', vars) : 0;
	if (vars->pvalue == 0 && vars->prec == 0)
		return ;
	ft_dectohexa_p(vars->pvalue, 'x', vars, 0);
	if ((vars->digit || vars->star || vars->minus) && vars->isnegative)
		print_flag(i, ' ', vars);
}

void			ft_pvalue(va_list args, t_vars *vars)
{
	int			i;
	int			j;
	int			leng;

	j = 0;
	i = 0;
	vars->counter = 0;
	vars->pvalue = va_arg(args, unsigned long long);
	ft_dectohexa_p(vars->pvalue, 'x', vars, 1);
	leng = vars->counter;
	if (vars->wdth > vars->counter)
		i = vars->wdth - vars->counter - 2;
	if (vars->prec >= vars->counter)
	{
		i = vars->wdth - vars->prec - 2;
		j = vars->prec - vars->counter;
	}
	if (vars->isprecision)
		ft_precision(&i, &j, vars, &leng);
	else
		ft_notprecision(&i, &j, vars);
}
