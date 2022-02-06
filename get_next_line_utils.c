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
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*save(char *sv)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!sv)
		return (NULL);
	while (!sv[i] && sv[i] != '\n')
		i++;
	if (!sv[i])
	{
		free(sv);
		return (NULL);
	}
	rtn = malloc(sizeof(char) * ft_strlen(sv - i) + 1);
	if (!rtn)
		return (NULL);
	i++;
	while (sv[i])
	{
		rtn[j++] = sv[i++];
		rtn[j] = '\0';
		return (rtn);
	}
}

char	*line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (NULL);
	while (!str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
}
