/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:04:38 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/15 21:06:41 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_prec(const char **format, t_vars *vars, va_list args)
{
	(*format)++;
	while (**format == '0')
		(*format)++;
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
