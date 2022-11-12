/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/11/10 16:06:52 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/11 23:08:48 by mohtakra         ###   ########.fr       */
=======
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/10 02:58:17 by mohtakra         ###   ########.fr       */
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_till_new_line(int fd, char *rest);
char	*rest_after_line(char *str);
char	*ft_line(char *str);

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*xbuffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	xbuffer = get_till_new_line(fd, rest);
	free(rest);
	rest = rest_after_line(xbuffer);
	line = ft_line(xbuffer);
	free(xbuffer);
	return (line);
}

<<<<<<< HEAD
char	*get_till_new_line(int fd, char *rest)
{
	char	*buffer;
	char	*line_rest;
	ssize_t	readbuffer;

	readbuffer = 1;
	line_rest = NULL;
	line_rest = ft_strjoin(line_rest, rest);
	if (ft_strchr(rest, '\n'))
		return (line_rest);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readbuffer)
	{
		readbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readbuffer == -1)
			return (free(buffer), NULL);
		buffer[readbuffer] = '\0';
		line_rest = ft_strjoin(line_rest, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), line_rest);
=======
char	*get_line(char *rest, char *buffer, int fd, int *readbuffer)
{
	char	*line;

	line = NULL;
	if (check_for_char(rest, '\n'))
	{
		line = ft_strjoin(line, rest);
		return (free(buffer), rest_from_last(rest, rest), line);
	}
	else
		line = ft_strjoin(line, rest);
	while (*readbuffer)
	{
		*readbuffer = read(fd, buffer, BUFFER_SIZE);
		ft_strlcpy(rest, buffer, *readbuffer + 1);
		line = ft_strjoin(line, rest);
		if (check_for_char(rest, '\n'))
		{
			rest_from_last(rest, rest);
			break ;
		}
		else if (*readbuffer == 0 || *readbuffer == -1)
			return (free(buffer), free(rest), line);
	}
	return (free(buffer), line);
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
}

char	*rest_after_line(char *str)
{
<<<<<<< HEAD
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (ft_substr(str, i, ft_strlen(str) - i + 1));
}

char	*ft_line(char *all_xbuffer)
{
	int		i;

	i = 0;
	if (!all_xbuffer)
		return (NULL);
	while (all_xbuffer[i] && all_xbuffer[i] != '\n')
		i++;
	if (all_xbuffer[i] == '\n')
		i++;
	if (all_xbuffer[0] == '\0')
		return (NULL);
	return (ft_substr(all_xbuffer, 0, i));
=======
	static char	*rest;
	char		*buffer;
	static int	readbuffer;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		readbuffer = 1;
		rest = (char *)malloc(BUFFER_SIZE);
		if (!rest)
			return (free(buffer), NULL);
		rest[0] = '\0';
	}
	return (get_line(rest, buffer, fd, &readbuffer));
>>>>>>> 9fd97f0493a9dd616b9b407b83f7c358f62917af
}
