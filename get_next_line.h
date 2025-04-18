/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:04:26 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/16 22:39:45 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *read_into);
char	*ft_append(char *s1, char *s2);
char	*ft_extract_line(char *str);
char	*ft_line_trim(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int ch);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);

#endif
