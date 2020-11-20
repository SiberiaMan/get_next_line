/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:49 by dchani            #+#    #+#             */
/*   Updated: 2020/11/20 20:22:15 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 		*pop_front(char *stack)
{
	int 	i;
	char 	*ptr;

	i = 0;
	while(stack && stack[i])
		i++;
	if (stack[i + 1])
		ptr = ft_strdup(&stack[i + 1]);
	if (!ptr)
		return (0);
	free(stack);
	return (ptr);
}

int 		stack_front(char **stack, char **line)
{
	int i;

	i = 0;
	while ((*stack)[i] != '\n')
	{
		if ((*stack)[i++] == '\0')
			return(0);
	}

}

int			get_next_line(int fd, char **line)
{
	static char	*stack[FD_MAX];

	if (!line || !(*line) || read(fd, 0, 0) == -1)
		return (-1);
	if (stack[fd] && stack_front(&stack[fd], line))
		return (1);
}