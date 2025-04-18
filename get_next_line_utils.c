/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:54:18 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/18 10:17:05 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	indx;

	indx = 0;
	while (str[indx])
		indx++;
	return (indx);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	res = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int ch)
{
	size_t			indx;
	unsigned char	chr;

	indx = 0;
	chr = (unsigned char)ch;
	while (str[indx] != '\0')
	{
		if (str[indx] == chr)
			return ((char *)&str[indx]);
		indx++;
	}
	if (str[indx] == '\0' && chr == '\0')
		return ((char *)&str[indx]);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}
