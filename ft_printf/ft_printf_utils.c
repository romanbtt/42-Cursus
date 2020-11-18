/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:52 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/17 19:32:07 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !(ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ullitoa_base(unsigned long long int nb, int base)
{
	unsigned long long int tmp;
	int size;
	char *str;

	tmp = nb;
	size = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb /= base)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (tmp > 0)
	{
		if ((tmp % base) < 10)
			str[size--] = (tmp % base) + 48;
		else
			str[size--] = (tmp % base) + 55;
		tmp /= base;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ptr_s1;
	unsigned char *ptr_s2;

	if (n == 0)
		return (0);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (*ptr_s1 && *ptr_s2 && (*ptr_s1 == *ptr_s2) && --n)
	{
		ptr_s1++;
		ptr_s2++;
	}
	return (*ptr_s1 - *ptr_s2);
}

size_t	ft_countsize(int n)
{
	size_t count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

int		ft_isneg(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char			*ft_itoa(int n)
{
	int		neg;
	size_t	i;
	char	*str;
	long	nbr;

	nbr = n;
	i = 0;
	neg = ft_isneg(nbr);
	if (neg == -1)
		i = 1;
	nbr *= neg;
	i += ft_countsize(nbr);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == -1)
		str[i] = '-';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && c != *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
		c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int neg;
	int nb;

	neg = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (*nptr - '0') + (nb * 10);
		nptr++;
	}
	return (nb * neg);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	if (s == NULL || !(ptr = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (start < len_s && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	void	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!(ptr = malloc(len * sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}