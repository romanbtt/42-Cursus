/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:02:05 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/29 22:48:44 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct	s_flags
{
	int		idx;
	int		count;
	bool	dot;
	bool	zero;
	bool	minus;
	int		width;
	int		precision;
	va_list	args;
}				t_flags;

typedef void	(*t_array_func_conv)(t_flags *);

int				ft_printf(const char *format, ...);
void			select_conversion(const char *format, t_flags *x);
void			parsing_format(char *format, t_flags *x);

void			padding(int width, int lenght, bool is_zero, t_flags *x);
void			output(char *str, int size, t_flags *x);

void			format_char(t_flags *x);
void			format_string(t_flags *x);
void			format_pointer(t_flags *x);
void			format_int(t_flags *x);
void			format_unsigned_int(t_flags *x);
void			format_low_hex(t_flags *x);
void			format_up_hex(t_flags *x);
void			format_percent(t_flags *x);

void			flag_dot(const char *format, t_flags *x);
void			flag_zero(const char *format, t_flags *x);
void			flag_wildcard(const char *format, t_flags *x);
void			flag_minus(const char *format, t_flags *x);

#endif
