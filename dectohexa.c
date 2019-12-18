/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dectohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:09:27 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 12:19:23 by elahyani         ###   ########.fr       */
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

void		ft_dectohexa(long long n, t_vars *vars, int opt)
{
	unsigned int	negnum;
	static int		len;

	len = 0;
	if (n < 0)
	{
		negnum = n;
		n = negnum;
	}
	if (n / 16)
	{
		ft_dectohexa(n / 16, vars, opt);
		len++;
	}
	if (!opt)
		ft_putchar(ft_check_digit(n % 16, vars->type), vars);
	vars->counter = len + 1;
}
