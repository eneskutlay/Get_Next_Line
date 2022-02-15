/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:24 by ekutlay           #+#    #+#             */
/*   Updated: 2022/02/16 00:12:17 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	while (s[i] != '\0')
		i++;
	return (i);
}

int	nlsearch(char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < (size - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joins;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joins = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s1 || !s2 || !joins)
		return (NULL);
	ft_strlcpy(joins, s1, s1_len + 1);
	ft_strlcpy(joins, + (s1_len), s2, s2_len + 1);
}
