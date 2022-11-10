/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:37:39 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/10 02:52:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc(sizeof(char) * ft_strlen_nl(s) + 1);
	if (!str)
		return (NULL);
	while (*s && *s != '\n')
	{
		str[i] = *s;
		s++;
		i++;
	}
	if (*s == '\n')
	{
		str[i] = *s;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if ((!s1 && !s2) || (ft_strlen_nl(s1) == 0 && ft_strlen_nl(s2) == 0))
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	str = (char *)malloc(ft_strlen_nl(s1) + ft_strlen_nl(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 && *s2 != '\n')
		str[i++] = *s2++;
	if (*s2 == '\n')
		str[i++] = *s2;
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

int	check_for_char(char *str, char c)
{
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				return (1);
			str++;
		}
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	if (!dst || !src)
		return (0);
	src_size = ft_strlen_nl(src);
	i = 0;
	if (dstsize != 0)
	{
		while (*src && i < dstsize - 1)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
	}
	return (src_size);
}
