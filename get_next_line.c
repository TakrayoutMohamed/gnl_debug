/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/09 21:49:44 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rest_from_last(char *str, char *buffer)
{
	char	*tmp;

	tmp = str;
	while (*buffer && *buffer != '\n')
		buffer++;
	buffer++;
	while (*buffer)
	{
		*str = *buffer;
		buffer++;
		str++;
	}
	*str = '\0';
	str = tmp;
}

char	*get_last_result_and_rest(char *line, char *rest, char *buffer, int fd)
{
	int		readedbuffer = 1;

	readedbuffer = 1;
	if (check_for_char(rest, '\n'))
	{
		line = ft_strjoin(line, rest);
		return (free(buffer), rest_from_last(rest, rest), line);
	}
	else
		line = ft_strjoin(line, rest);
		// printf("readedbuffer = **%d**",readedbuffer);
	while (readedbuffer)
	{
		readedbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readedbuffer == -1)
			return (free(buffer), NULL);
		ft_strlcpy(rest, buffer, readedbuffer + 1);
		line = ft_strjoin(line, rest);
		if (check_for_char(rest, '\n'))
		{
			rest_from_last(rest, rest);
			break ;
		}	
	}
	printf("[%s]\n", line);
	// printf("buffer1 : =%s=%zu",buffer,strlen(buffer));
	// exit(0);
	return (free(buffer),line);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*rest;
	char	*buffer;

	buffer =(char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		rest = (char *)malloc(BUFFER_SIZE + 1);
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	return (get_last_result_and_rest(result, rest, buffer, fd));
}
