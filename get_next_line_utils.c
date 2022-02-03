/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:24 by ekutlay           #+#    #+#             */
/*   Updated: 2022/02/02 01:29:38 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while (++i < len + 1)
	{
		if (s[i] == (char)c)
		{
			return (((void *)&((char *)s)[i]));
		}
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	ldst = dst_len;
	i = 0;
	if (size > 0 && dst_len < size - 1)
	{
		while (src[i] && dst_len < size - 1 - i)
		{
			dst[ldst] = src[i];
			i++;
			ldst++;
		}
		dst[ldst] = 0;
	}
	if (dst_len >= size)
	{
		return (size + src_len);
	}
	return (dst_len + src_len);
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
	{
		return (NULL);
	}
	ft_strlcpy(joins, s1, s1_len + 1);
	ft_strlcpy(joins + (s1_len), s2, s2_len + 1);
	return (joins);
}
