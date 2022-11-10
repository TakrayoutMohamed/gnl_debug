/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/10 02:01:17 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rest_from_last(char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i])
	{
		str[j] = buffer[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

char	*get_line(char *line, char *rest, char *buffer, int fd, int *readedbuffer)
{
	if (check_for_char(rest, '\n'))
	{
		line = ft_strjoin(line, rest);
		return (free(buffer), rest_from_last(rest, rest), line);
	}
	else
		line = ft_strjoin(line, rest);
	while (*readedbuffer)
	{
		*readedbuffer = read(fd, buffer, BUFFER_SIZE);
		if (*readedbuffer == -1)
			return (free(buffer), free(rest), NULL);
		ft_strlcpy(rest, buffer, *readedbuffer + 1);
		line = ft_strjoin(line, rest);
		if (check_for_char(rest, '\n'))
		{
			rest_from_last(rest, rest);
			break ;
		}
		else if (*readedbuffer == 0)
			return (free(buffer), free(rest), line);
	}
	return (free(buffer),line);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*rest;
	char		*buffer;
	static int	readedbuffer;

	buffer =(char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		readedbuffer = 1;
		rest = (char *)malloc(BUFFER_SIZE);
		if (!rest)
			return (free(buffer), NULL);
		rest[0] = '\0';
	}
	
	return (get_line(result, rest, buffer, fd, &readedbuffer));
}
