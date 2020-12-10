/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:58 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/02 08:25:17 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define STR_CONV "cspdiuxX%"

/*
** The const char* is created to store a string of converters (see STR_CONV).
** t_array_func_conv is an array of pointers of functions which store all the
** the functions needed to process the program results.
** We use a loop to compare format[x->idx] to STR_CONV.
** If the character fotmat[x->idx] is different from conversions[i],
** we increment "i" index until is the same or '\0' is reached.
** When the character is identical :
** If conversions[i] is different than '\0', we call the corresponding function
** using the index 'i'.
** If not, we print a '%' character, then decrement x->idx.
*/

void	select_conversion(const char *format, t_flags *x)
{
	const char					*conversions;
	int							i;
	static t_array_func_conv	func_conv[9] = {format_char, format_string,
		format_pointer, format_int, format_int, format_unsigned_int,
		format_low_hex, format_up_hex, format_percent};

	conversions = STR_CONV;
	i = 0;
	while (format[x->idx] != conversions[i] && conversions[i])
		i++;
	if (conversions[i])
		(*func_conv[i])(x);
	else
	{
		output("%", 1, x);
		x->idx--;
	}
}

/*
** We start to increment the x->idx by one to access the flags.
** If format[x->idx] is an '-', then we call flag_minus().
** If format[x->idx] is an '0', then we call flag_zero().
** We call flag_wildcard() to get the width value.
** If format[x->idx] is an '.', then we call flag_dot().
** Each incrementation of x->idx is done inside the functions of flags.
** Finally, we call select_conversion() to select the conversion's function.
*/

void	parsing_format(char *format, t_flags *x)
{
	x->idx++;
	if (format[x->idx] == '-')
		flag_minus(format, x);
	if (format[x->idx] == '0')
		flag_zero(format, x);
	flag_wildcard(format, x);
	if (format[x->idx] == '.')
		flag_dot(format, x);
	select_conversion(format, x);
}

/*
** First, the format string is copied into the str variable.
** The x structure is set to 0.
** x.idx is the index of the format string.
** x.count is the number of characters printed by the program.
** x.dot is a boolean when the "." flag is in the format string.
** x.zero is a boolean when the "0" flag is in the format string.
** x.minus is a boolean when the "-" flag is in the format string.
** x.precision is an int to store the precision value.
** x.width is an int to store the width value when the "-" flag or number
** is set.
** The arguments of the variadic variable are launched and stored in the
** x.args.
** While str[x.idx], we check if str[x.idx] == '%'.
** If yes, we call parsing_format to store all the information and process
** formatting. When we come back, the structure is set to 0 except for
** for the variables idx, count and args for which we keep the same values.
** If not, the character is printed.
** str is freed and x.args is terminated before returning x.count.
*/

int		ft_printf(const char *format, ...)
{
	t_flags	x;
	char	*str;

	str = ft_strdup(format);
	x = (t_flags) {0};
	va_start(x.args, format);
	while (str[x.idx])
	{
		if (str[x.idx] == '%')
		{
			parsing_format(str, &x);
			x = (t_flags) {x.idx, x.count, 0, 0, 0, 0, 0,
				{{x.args->gp_offset, x.args->fp_offset,
				x.args->overflow_arg_area, x.args->reg_save_area}}};
		}
		else
			output(str + x.idx, 1, &x);
		x.idx++;
	}
	free(str);
	va_end(x.args);
	return (x.count);
}
