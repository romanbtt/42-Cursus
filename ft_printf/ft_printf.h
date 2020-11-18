/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:02:05 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/17 19:32:16 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//to delete
#include <stdio.h>

//real header
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

//Structure
typedef struct	s_flags
{

	int		idx;
	int		count;
	bool	dot;
	int		zero;
	bool	minus;
	int		width;
	int		precision;
	va_list	args;
}				t_flags;

//array pointer of functions
typedef void (*t_array_func_flag)(const char *, t_flags *);
typedef void (*t_array_func_conv)(t_flags *);



void	select_conversion(const char *format, t_flags *x);
void	parsing_format(const char *format, t_flags *x);
int		ft_printf(const char *format, ...);

void 	padding(int width, int lenght, t_flags *x);
void 	print(char *str, int size, t_flags *x);

int	ft_tolower(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ullitoa_base(unsigned long long int nb, int base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		ft_isspace(const char c);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
int		ft_isneg(int n);
size_t	ft_countsize(int n);


void	format_char(t_flags *x);
void	format_string(t_flags *x);
void	format_pointer(t_flags *x);
void	format_int(t_flags *x);
void	format_unsigned_int(t_flags *x);;
void	format_low_hex(t_flags *x);
void	format_up_hex(t_flags *x);
void	format_percent(t_flags *x);

void	flag_digit(const char *format, t_flags *x);
void	flag_dot(const char *format, t_flags *x);
void	flag_zero(const char *format, t_flags *x);
void	flag_wildcard(const char *format, t_flags *x);
void	flag_minus(const char *format, t_flags *x);


#endif