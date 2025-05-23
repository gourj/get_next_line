/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:00:11 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/18 10:16:41 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_trim(char *str)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = (char *)ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
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
	while (str[i] && str[i] != '\n')
		i++;
	the_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!the_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		the_line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		the_line[i++] = '\n';
	the_line[i++] = '\0';
	return (the_line);
}

char	*ft_append(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (!result)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	free(s1);
	return (result);
}

char	*ft_read_fd(int fd, char *read_into)
{
	ssize_t	bytes_read;
	char	*chunk;

	if (!read_into)
		return (NULL);
	chunk = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!chunk)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[bytes_read] = 0;
		read_into = ft_append(read_into, chunk);
		if (ft_strchr(chunk, '\n'))
			break ;
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
	if (!combined_chunks)
	{
		combined_chunks = (char *)ft_calloc(1, sizeof(char));
		if (!combined_chunks)
			return (NULL);
	}
	combined_chunks = ft_read_fd(fd, combined_chunks);
	if (!combined_chunks)
	{
		free(combined_chunks);
		return (NULL);
	}
	line = ft_extract_line(combined_chunks);
	if (!line)
	{
		free(combined_chunks);
		return (NULL);
	}
	combined_chunks = ft_line_trim(combined_chunks);
	return (line);
}
