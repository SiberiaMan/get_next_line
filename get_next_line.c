/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:49 by dchani            #+#    #+#             */
/*   Updated: 2020/11/21 21:03:58 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*q_pop(char **queue)
{
	int		i;
	char	*ptr;

	ptr = 0;
	i = 0;
	while (queue && (*queue)[i] != '\n')
		i++;
	if ((*queue)[i + 1])
		ptr = ft_strdup(&((*queue)[i + 1]));
	free(*queue);
	*queue = 0;
	return (ptr);
}

int			line_assign(char **queue, char **line)
{
	int i;

	i = 0;
	while ((*queue)[i] != '\n')
		if ((*queue)[i++] == '\0')
			return (0);
	(*queue)[i] = '\0';
	*line = ft_strdup(*queue);
	(*queue)[i] = '\n';
	*queue = q_pop(queue);
	return (1);
}

int			q_push(char **buffer, char **queue, int fd, char **line)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while ((cnt = read(fd, *buffer, BUFFER_SIZE)))
	{
		(*buffer)[cnt] = '\0';
		*queue = ft_strjoin(*queue, *buffer);
		if (!line_assign(queue, line))
			continue ;
		else
			break ;
	}
	free(*buffer);
	*buffer = 0;
	return (cnt);
}

int			get_next_line(int fd, char **line)
{
	static char		*queue_arr[FD_MAX];
	char			*buffer;

	if (!line || read(fd, 0, 0) == -1
	|| (!(buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	if (queue_arr[fd] && line_assign(&queue_arr[fd], line))
	{
		free(buffer);
		buffer = 0;
		return (1);
	}
	if (!q_push(&buffer, &queue_arr[fd], fd, line))
	{
		if (queue_arr[fd])
		{
			*line = ft_strdup(queue_arr[fd]);
			free(queue_arr[fd]);
			queue_arr[fd] = 0;
		}
		else
			*line = ft_strdup("");
		return (0);
	}
	return (1);
}
