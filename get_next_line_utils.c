/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:37 by dchani            #+#    #+#             */
/*   Updated: 2020/11/20 20:21:43 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*bptr;

	if (!(ptr = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	bptr = ptr;
	while (s1 && *s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	while (s2 && *s2)
	{
		*ptr = *s2;
		ptr++;
		s2++;
	}
	*ptr = '\0';
	return (bptr);
}

char		*ft_strdup(const char *s1)
{
	char *ptr;
	char *bptr;

	if (!(ptr = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	bptr = ptr;
	while (*s1)
	{
		*ptr = *s1;
		s1++;
		ptr++;
	}
	*ptr = *s1;
	return (bptr);
}
