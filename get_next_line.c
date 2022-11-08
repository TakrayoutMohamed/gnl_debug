/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/08 04:02:41 by mohtakra         ###   ########.fr       */
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

void	allocat_and_free(char *strtofill, char *strtofree)
{
	int		i;

	i = 0;
	if (!strtofree)
		return ;
	strtofill = (char *) malloc(sizeof(char) * ft_strlen(strtofree) + 1);
	if (!strtofill)
		return ;
	while (*strtofree)
	{
		strtofill[i] = strtofree[i];
		i++;
	}
	strtofill[i] = '\0';
	if (ft_strlen(strtofree) > 0)
		free(strtofree);
}

char	*get_last_result_and_rest(char *line, char *str, int *readfile, int *fd)
{
	char	buffer[BUFFER_SIZE];

	if (check_for_char(str, '\n'))
	{
		line = ft_strjoin(line, str);
		return (rest_from_last(str, str), line);
	}
	else
		line = ft_strjoin(line, str);
	while (*readfile)
	{
		*readfile = read(*fd, buffer, BUFFER_SIZE);
		if (*readfile == -1)
			return (NULL);
		ft_strlcpy(str, buffer, *readfile + 1);
		line = ft_strjoin(line, str);
		if (check_for_char(str, '\n'))
		{
			rest_from_last(str, str);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*result;
	char		*resultline;
	static char	str[BUFFER_SIZE];
	int			readfile;

	result = NULL;
	resultline = NULL;
	readfile = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_last_result_and_rest(result, str, &readfile, &fd));
}
