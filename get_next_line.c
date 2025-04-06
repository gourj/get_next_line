/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:00:11 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/06 23:45:03 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*line;

	read_into = (char *)malloc(sizeof(char));
	if (!read_into)
		return (NULL);
	*read_into = '\0';
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		line = '\0';
		read_into = ft_append(read_into, line);
		if (ft_strchr(line, '\n')
			break;
	}
	free(line);
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
	combined_chinks = ft_line_trim(combined_chunks);
	return (line);
}
