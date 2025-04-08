/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:00:11 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/09 00:40:42 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_trim(char *str)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!result)
		return (NULL);
	j = 0;
	i++;
	while (str[i + j] != '\0')
	{
		result[j] = str[i + j];
		j++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_extract_line(char *str)
{
	char	*the_line;
	size_t	i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
	the_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!the_line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		the_line[i] = str[i];
		i++;
	}
	the_line[i] = '\n';
	return (the_line);
}

char	*ft_append(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*ft_read_fd(int fd, char *read_into)
{
	ssize_t	bytes_read;
	char	*chunk;

	read_into = (char *)malloc(sizeof(char));
	if (!read_into)
		return (NULL);
	*read_into = '\0';
	chunk = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!chunk)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[bytes_read] = '\0';
		read_into = ft_append(read_into, chunk);
		if (ft_strchr(chunk, '\n')
			break;
	}
	free(chunk);
	return (read_into);
}

char	*get_next_line(int fd)
{
	static char	*combined_chunks;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	combined_chunks = ft_read_fd(fd, combined_chunks);
	if (!combined_chunks)
		return (NULL);
	line = ft_extract_line(combined_chunks);
	combined_chunks = ft_line_trim(combined_chunks);
	return (line);
}
