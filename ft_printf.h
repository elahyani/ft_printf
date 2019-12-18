/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:00:41 by elahyani          #+#    #+#             */
/*   Updated: 2019/12/17 15:09:37 by elahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_vars
{
	int					isnegative;
	int					wdth;
	int					prec;
	int					zero;
	int					minus;
	int					star;
	int					digit;
	int					point;
	int					isprecision;
	unsigned int		wr_char;
	int					counter;
	long				ivalue;
	unsigned int		uvalue;
	unsigned long long	pvalue;
	int					len;
	char				type;
}						t_vars;

void					ft_putstr(char *s);
void					ft_putchar(char c, t_vars *vars);
int						ft_putnbr(long n, t_vars *vars);
unsigned int			ft_unbr(unsigned int n, t_vars *vars);
void					ft_dectohexa(long long n, t_vars *vars, int opt);
void					ft_dectohexa_p(unsigned long long n, char type,
						t_vars *vars, int opt);
size_t					ft_len(long long n);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
void					ft_pvalue(va_list args, t_vars *vars);
void					ft_cvalue(va_list args, t_vars *vars);
void					ft_xvalue(char type, va_list args, t_vars *vars);
void					ft_uvalue(va_list args, t_vars *vars);
void					ft_ivalue(va_list args, t_vars *vars);
void					ft_svalue(va_list args, t_vars *vars);
void					ft_percent(t_vars *vars);
void					flag_minus(const char **type, t_vars *vars,
						va_list args);
void					flag_width(const char **type, t_vars *vars,
						va_list args);
void					flag_star(const char **type, t_vars *vars,
						va_list args);
void					flag_zero(const char **type, t_vars *vars,
						va_list args);
void					flag_prec(const char **type, t_vars *vars,
						va_list args);
void					ft_initialisation(t_vars *vars);
int						ft_printf(const char *type, ...);
#endif
