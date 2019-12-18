/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:03:13 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/15 21:06:57 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_width(const char **format, t_vars *vars, va_list args)
{
	vars->wdth = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		(*format)++;
		vars->isprecision = 1;
		if (ft_isdigit(**format))
		{
			vars->prec = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			vars->prec = va_arg(args, int);
			(*format)++;
		}
		else
			vars->prec = 0;
		if (vars->prec < 0)
			vars->prec = -1;
	}
}
