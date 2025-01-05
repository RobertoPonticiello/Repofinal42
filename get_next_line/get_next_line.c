/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:34:56 by rpontici          #+#    #+#             */
/*   Updated: 2025/01/05 20:37:03 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clearindex(t_fdata *index)
{
	if (index)
		free(index);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

t_fdata	*ft_newindex(void)
{
	t_fdata	*result;

	result = malloc(sizeof(t_fdata));
	if (!result)
		return (NULL);
	result->start = 0;
	result->end = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_fdata	*fd_index[1024];
	char			*line;

	line = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fd_index[fd])
	{
		fd_index[fd] = ft_newindex();
		if (!fd_index[fd])
			return (NULL);
	}
	while (1)
	{
		fd_index[fd] = ft_updateindex(fd_index[fd], fd);
		if (!fd_index[fd])
		{
			free(line);
			return (NULL);
		}
		if (fd_index[fd]->end == 0 && (line == NULL || line[0] == '\0'))
		{
			free(line);
			return (NULL);
		}
		line = ft_readline(line, fd_index[fd]);
		if (line && ft_strlen(line) > 0 && (line[ft_strlen(line) - 1] == '\n'
				|| fd_index[fd]->end == 0))
			break ;
	}
	return (line);
}

int	main(void)
{
	int fd_file;
	char *line;
	int count = 1;

	fd_file = open("file.txt", O_RDONLY);
	if (fd_file < 0)
		return (1);

	while ((line = get_next_line(fd_file)) != NULL)
	{
		printf("%d) %s", count, line);
		free(line);
		count++;
	}
	close(fd_file);
	return (0);
}

/*int	main(void)
{
	char *fd;

	int i = open("file.txt", O_RDONLY);
	fd = get_next_line(i);
	printf("1) %s", fd);
	fd = get_next_line(i);
	printf("2) %s", fd);
	fd = get_next_line(i);
	printf("3) %s", fd);
	fd = get_next_line(i);
	printf("4) %s", fd);
	fd = get_next_line(i);
	printf("5) %s", fd);
	fd = get_next_line(i);
	printf("6) %s", fd);
	fd = get_next_line(i);
	printf("7) %s", fd);
	fd = get_next_line(i);
	printf("8) %s", fd);
	fd = get_next_line(i);
	printf("9) %s", fd);
	free(fd);
	return (0);
}*/
