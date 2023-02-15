/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamzeh <ahamzeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:16:16 by ahamzeh           #+#    #+#             */
/*   Updated: 2023/02/16 02:16:18 by ahamzeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *snt_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!snt_str[i])
		return (NULL);
	while (snt_str[i] && snt_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (snt_str[i] && snt_str[i] != '\n')
	{
		str[i] = snt_str[i];
		i++;
	}
	if (snt_str[i] == '\n')
	{
		str[i] = snt_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *snt_str)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	while (snt_str[i] && snt_str[i] != '\n')
		i++;
	if (!snt_str[i])
	{
		free(snt_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(snt_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (snt_str[i])
		str[j++] = snt_str[i++];
	str[j] = '\0';
	free(snt_str);
	return (str);
}

char	*ft_read_to_str(int fd, char *snt_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(snt_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		snt_str = ft_strjoin(snt_str, buff);
	}
	free(buff);
	return (snt_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*snt_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	snt_str[fd] = ft_read_to_str(fd, snt_str[fd]);
	if (!snt_str[fd])
		return (NULL);
	line = ft_get_line(snt_str[fd]);
	snt_str[fd] = ft_new_str(snt_str[fd]);
	return (line);
}

/* int main()
{
	int	fd;
	int	i = -1;
	while (++i < 2)
	{
		fd = open("a.txt",O_RDONLY);
		printf("%s", get_next_line(fd));
		fd = open("b.txt",O_RDONLY);
		printf("%s", get_next_line(fd));
		fd = open("c.txt",O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(6));
	}
} */
