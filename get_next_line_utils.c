/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agurdzhi <agurdzhi@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:54:18 by agurdzhi          #+#    #+#             */
/*   Updated: 2025/04/09 01:11:43 by agurdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str)
{
	size_t	indx;

	indx = 0;
	while (str[indx] != '\0')
		indx++;
	return (indx);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = '\0';
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
