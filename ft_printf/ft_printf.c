/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:58 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/17 21:35:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_conversion(const char *format, t_flags *x)
{
	const char					*conversions;
	int							i;
	static t_array_func_conv	func_conv[9] = {format_char, format_string,
		format_pointer, format_int, format_int, format_unsigned_int,
		format_low_hex, format_up_hex, format_percent};

	conversions = "cspdiuxX%";
	i = 0;
	while (format[x->idx] != conversions[i])
		i++;
	(*func_conv[i])(x);
}

void	parsing_format(const char *format, t_flags *x)
{
	const char					*flags;
	int							i;
	static t_array_func_flag	func_flags[4] = {flag_zero, flag_wildcard,
		flag_dot, flag_minus};

	i = -1;
	flags = "0*.-";
	while (format[++x->idx] && !ft_strchr("cspdiuxX%", format[x->idx]))
	{
		while (flags[++i])
		{
			if (flags[i] == format[x->idx])
				(*func_flags[i])(format, x);
		}
		i = 0;
		if (ft_isdigit(format[x->idx]))
			flag_digit(format, x);
	}
	if (ft_strchr("cspdiuxX%", format[x->idx]))
		select_conversion(format, x);
}

int		ft_printf(const char *format, ...)
{
	t_flags x;

	x = (t_flags) {0, 0, 0, 0, 0, 0, 0, {{0}}};
	va_start(x.args, format);
	while (format[x.idx])
	{
		if (format[x.idx] == '%')
		{
			parsing_format(format, &x);
			x = (t_flags) {x.idx, x.count, 0, 0, 0, 0, 0,
				{{x.args->gp_offset, x.args->fp_offset,
				x.args->overflow_arg_area, x.args->reg_save_area}}};
		}
		else
		{
			ft_putchar_fd(format[x.idx], 1);
			x.count++;
		}
		x.idx++;
	}
	va_end(x.args);
	return (x.count);
}
/*

int main(void)
{
	void *a01;
	void *a02;
	void *a03;
	void *a04;
	void *a05;
	void *a06;
	void *a07;
	void *a08;
	void *a09;
	void *a10;
	void *a11;
	void *a12;

	int a;
	int b;
	a = ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");
	b = printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");
	printf("%d", a);
	printf("\n");
	printf("%d", b);
}

*/