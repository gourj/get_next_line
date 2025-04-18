/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:32:34 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/18 10:40:01 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		line_num;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line_num = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line %d: %s", line_num, line);
		free(line);
		line_num++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
