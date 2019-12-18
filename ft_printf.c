/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:02:10 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 00:07:44 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags_check(const char **format, t_vars *vars, va_list args)
{
	if (ft_isdigit(**format) && **format != '0')
	{
		vars->digit = 1;
		flag_width(format, vars, args);
	}
	if (**format == '0')
	{
		vars->zero = 1;
		flag_zero(format, vars, args);
	}
	if (**format == '-')
	{
		vars->minus = 1;
		flag_minus(format, vars, args);
	}
	if (**format == '*')
	{
		vars->star = 1;
		flag_star(format, vars, args);
	}
	if (**format == '.')
	{
		vars->point = 1;
		flag_prec(format, vars, args);
	}
}

static void		ft_convertions(const char *format, va_list args, t_vars *vars)
{
	if (*format == 'd' || *format == 'i')
		ft_ivalue(args, vars);
	else if (*format == 'c')
		ft_cvalue(args, vars);
	else if (*format == 's')
		ft_svalue(args, vars);
	else if (*format == 'u')
		ft_uvalue(args, vars);
	else if (*format == 'x' || *format == 'X')
		ft_xvalue(*format, args, vars);
	else if (*format == 'p')
		ft_pvalue(args, vars);
	else if (*format == '%')
		ft_percent(vars);
}

void			ft_initialisation(t_vars *vars)
{
	vars->wdth = -1;
	vars->prec = -1;
	vars->isnegative = 0;
	vars->digit = 0;
	vars->minus = 0;
	vars->zero = 0;
	vars->star = 0;
	vars->point = 0;
	vars->isprecision = 0;
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_vars		vars;

	vars.wr_char = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_initialisation(&vars);
			format++;
			ft_flags_check(&format, &vars, args);
			ft_convertions(format, args, &vars);
		}
		else
			ft_putchar(*format, &vars);
		format++;
	}
	va_end(args);
	return (vars.wr_char);
}
