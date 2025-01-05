/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpontici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:55:51 by rpontici          #+#    #+#             */
/*   Updated: 2025/01/05 19:28:03 by rpontici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdata	*ft_updateindex(t_fdata *index, int fd)
{
	ssize_t	bytes_read;

	if (index->start >= index->end)
	{
		bytes_read = read(fd, index->buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			index->start = 0;
			index->end = 0;
			return (index);
		}
		index->start = 0;
		index->end = bytes_read;
	}
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	if (s1)
		free(s1);
	return (result);
}

size_t	set_i(t_fdata *index)
{
	size_t	i;

	i = 0;
	while (index->start + i < index->end && index->buffer[index->start
			+ i] != '\n')
		i++;
	return (i);
}

char	*ft_readline(char *str, t_fdata *index)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = set_i(index);
	j = 0;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	while (j < i)
	{
		temp[j] = index->buffer[index->start + j];
		j++;
	}
	if (index->start + i < index->end && index->buffer[index->start
			+ i] == '\n')
		temp[j++] = '\n';
	temp[j] = '\0';
	index->start += i + (index->start + i < index->end
			&& (index->buffer[index->start + i] == '\n'));
	str = ft_strjoin(str, temp);
	free(temp);
	return (str);
}
