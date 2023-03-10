/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:57:52 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 18:57:53 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line_bonus.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free (buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[1234];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}

// #include<stdio.h>
// int main()
// {
// 	int fd1, fd2;
// /* 	fd = open("dosya.m",O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s",get_next_line(fd)); */
// 	fd1 = open("d1", O_RDONLY);
// 	fd2 = open("d2", O_RDONLY);
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// 	printf("%s\n", get_next_line(fd1));
// 	printf("%s\n", get_next_line(fd2));
// }