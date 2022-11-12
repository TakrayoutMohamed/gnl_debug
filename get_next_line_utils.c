/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/11/10 20:17:46 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/11 22:27:19 by mohtakra         ###   ########.fr       */
=======
/*   Created: 2022/11/04 18:37:39 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/10 02:52:04 by mohtakra         ###   ########.fr       */
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
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
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = *s;
		s++;
		i++;
	}
<<<<<<< HEAD
	str[i] = 0;
=======
	if (*s == '\n')
	{
		str[i] = *s;
		i++;
	}
	str[i] = '\0';
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

int	ft_strchr(char *s, char c)
{
	char	*str;

	if (s)
	{
		str = s;
		while (*str && *str != c)
			str++;
		if (*str == c)
			return (1);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

<<<<<<< HEAD
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len > ft_strlen(s) - start)
		len = ft_strlen(s) - (size_t)start;
	i = (size_t)start;
	substr = (char *) malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (i < len + (size_t)start)
=======
	if (!dst || !src)
		return (0);
	src_size = ft_strlen_nl(src);
	i = 0;
	if (dstsize != 0)
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
	{
		substr[i - (size_t)start] = s[i];
		i++;
	}
	substr[i - (size_t)start] = '\0';
	return (substr);
}
