/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dectohexa_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:40:36 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/15 18:47:18 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_check_digit(long long n, char c)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else
	{
		if (c == 'X')
			return (n + 55);
		else if (c == 'x')
			return (n + 87);
	}
	return (0);
}

void		ft_dectohexa_p(unsigned long long n, char tp, t_vars *vars, int opt)
{
	static int	len;

	len = 0;
	if (n / 16)
	{
		ft_dectohexa_p(n / 16, tp, vars, opt);
		len++;
	}
	if (!opt)
		ft_putchar(ft_check_digit(n % 16, tp), vars);
	vars->counter = len + 1;
}
