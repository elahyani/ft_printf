/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:22:19 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 15:08:43 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_flag(int *k, char c, t_vars *vars)
{
	while ((*k)-- > 0)
		ft_putchar(c, vars);
}

void		ft_putlstr(const char *svalue, int *j, t_vars *vars)
{
	while ((*j)-- > 0)
		ft_putchar(*svalue++, vars);
}

static void	ft_precision(int *i, int *j, t_vars *vars, const char *svalue)
{
	if ((vars->digit || vars->star || vars->minus) && !vars->isnegative)
	{
		if (vars->prec == 0 && vars->wdth >= vars->len)
			*i = *i + vars->len;
		else if (vars->prec == 0 && vars->wdth < vars->len)
			*i = vars->wdth;
		print_flag(i, ' ', vars);
	}
	if (vars->zero && !vars->minus)
	{
		if (vars->prec == 0 && vars->wdth >= vars->len)
			*i = *i + vars->len;
		else if (vars->prec == 0 && vars->wdth < vars->len)
			*i = vars->wdth;
		print_flag(i, '0', vars);
	}
	ft_putlstr(svalue, j, vars);
	if (vars->isnegative)
	{
		if (vars->prec == 0 && vars->wdth >= vars->len)
			*i = *i + vars->len;
		else if (vars->prec == 0 && vars->wdth < vars->len)
			*i = vars->wdth;
		print_flag(i, ' ', vars);
	}
}

static void	ft_notprecision(int *i, int *j, t_vars *vars, const char *svalue)
{
	if ((vars->digit || vars->star) && !vars->isnegative)
		print_flag(i, ' ', vars);
	if (vars->zero)
		print_flag(i, '0', vars);
	if (vars->point)
		while ((*j)-- > 0)
			ft_putchar(*svalue++, vars);
	else if (vars->prec == 0)
	{
		if (vars->isnegative)
			print_flag(i, ' ', vars);
		return ;
	}
	else
		while (*svalue)
			ft_putchar(*svalue++, vars);
	if ((vars->digit || vars->star || vars->minus) && vars->isnegative)
		print_flag(i, ' ', vars);
}

void		ft_svalue(va_list args, t_vars *vars)
{
	const char	*svalue;
	int			i;
	int			j;

	i = 0;
	j = 0;
	svalue = (const char *)va_arg(args, const char *);
	(!svalue) ? svalue = "(null)" : 0;
	vars->len = ft_strlen(svalue);
	(vars->prec < 0) ? vars->prec = vars->len : 0;
	(vars->wdth >= vars->len) ? i = vars->wdth - vars->len : 0;
	if (vars->prec >= vars->len)
	{
		vars->prec = vars->len;
		i = vars->wdth - vars->prec;
		j = vars->prec;
	}
	else if (vars->prec < vars->len && vars->prec > 0)
	{
		i = vars->wdth - vars->prec;
		j = vars->prec;
	}
	(vars->isprecision) ? ft_precision(&i, &j, vars, svalue) :
	ft_notprecision(&i, &j, vars, svalue);
}
