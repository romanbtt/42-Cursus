/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:08:36 by robitett          #+#    #+#             */
/*   Updated: 2020/10/06 02:52:53 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FILE 4096

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>


# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


int		get_next_line(int fd, char **line);
int		process_line(char **remainder, char **line, int ret);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);

#endif