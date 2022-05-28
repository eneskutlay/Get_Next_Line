/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <ekutlay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:25:40 by ekutlay           #+#    #+#             */
/*   Updated: 2022/05/28 05:52:23 by ekutlay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
  size_t  i;
  
  i = 0;
  while (s != '\0')
    i++;
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
	return (NULL);
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
	ft_strlcat(joins + (s1_len), s2, s2_len + 1);
	return (joins);
}

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

