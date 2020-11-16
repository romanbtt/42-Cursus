/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 10:08:26 by robitett          #+#    #+#             */
/*   Updated: 2020/11/16 09:39:51 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void select_conversion(const char *format, t_flags *x)
{
	static t_array_func_conv func_conv[9] = {format_char, format_string,
		format_pointer, format_int, format_int, format_unsigned_int,
		format_low_hex, format_up_hex, format_percent};
	const char *conversions;
	int i;
	
	conversions = "cspdiuxX%";
	i = 0;
	while (format[x->idx] != conversions[i])
		i++;
	(*func_conv[i]) (x);
}

void	parsing_format(const char *format, t_flags *x)
{
	const char *flags;
	int i;

	i = -1;
	flags = "0*.-";
	static t_array_func_flag func_flags[4] = {flag_zero, flag_wildcard,
	 flag_dot, flag_minus};

	while (format[++x->idx] && !ft_strchr("cspdiuxX%", format[x->idx]))
	{
		while (flags[++i])
		{
			if (flags[i] == format[x->idx])
				(*func_flags[i]) (format, x);
		}
		i = 0;
		if (ft_isdigit(format[x->idx]))
			flag_digit(format, x);
	}
	if (ft_strchr("cspdiuxX%", format[x->idx]))
		select_conversion(format, x);
}

int	ft_printf(const char *format, ...)
{
	t_flags x;

	x = (t_flags) {0, 0, 0, 0, 0, 0, -1};
	va_start(x.args, format);
	while (format[x.idx])
	{
		if (format[x.idx] == '%')
			parsing_format(format, &x);
		else
		{
			ft_putchar_fd(format[x.idx], 1);
			x.count++;
		}
		x.idx++;
	}
	return (x.count);
}
/*
int main()
{
	ft_printf("%c", '\0');
}
*/

/*

int	main(void)
{
	
	int ret;
	char *str;

	ft_printf("1.%*c.\n",12, 'c');
    printf("\n");
    ft_printf("2.%*c.\n",-12, 'c');
    printf("\n");
    ft_printf("3.%-12c.\n", 'c');
    printf("\n");
    ft_printf("4.%.c.\n", 'c');
    printf("\n");
    ft_printf("5.%0c.\n", 'c');
    printf("\n");
    ft_printf("6.%*c.\n",0, 'c');
    printf("\n");
    ft_printf("7.%-0c.\n", 'c');
    printf("\n");
    ft_printf("8.%-12c.\n", 'c');
    printf("\n");

	printf("1.%*c.\n",12, 'c');
    printf("\n");
    printf("2.%*c.\n",-12, 'c');
    printf("\n");
    printf("3.%-12c.\n", 'c');
    printf("\n");
    printf("4.%.c.\n", 'c');
    printf("\n");
    printf("5.%0c.\n", 'c');
    printf("\n");
    printf("6.%*c.\n",0, 'c');
    printf("\n");
    printf("7.%-0c.\n", 'c');
    printf("\n");
    printf("8.%-12c.\n", 'c');
    printf("\n");



	ft_printf(".%.c.", 'c');
	ft_printf("\n");
	printf(".%c.", 'c');

	ret = printf(".%+-5d.",0);
	printf("\n%d\n", ret);
	ret = ft_printf(".%+-5d.",0);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf(".%+-5d.",-7);
	printf("\n%d\n", ret);
	ret = ft_printf(".%+-5d.",-7);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",0);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",0);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",-7);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",-7);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",1560133635);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",1560133635);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;

	ret = printf("%+05d",-2035065302);
	printf("\n%d\n", ret);
	ret = ft_printf("%+05d",-2035065302);
	printf("\n%d\n", ret);
	printf("\n");
	g_count = 0;
	return (0);
}

*/