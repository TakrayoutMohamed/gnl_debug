/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/07 19:26:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rest_from_last(char *str, char *buffer)
{
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
}
int	print_tell_null_term(char *str)
{
	if (str)
	{
		if (*str)
		{
			return (1);
		}
	}
	return (0);
}
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*resultline;
	static char	str[BUFFER_SIZE];
	static int			read_file = 1;

	resultline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_file)
	{
		if (check_for_char(str, '\n'))
		{
			resultline = ft_strjoin(resultline, str);
			rest_from_last(str, str);
			return (resultline);
		}
		else
			resultline = ft_strjoin(resultline, str);
	}
	while (read_file)
	{
		read_file = read(fd, buffer, BUFFER_SIZE);
		ft_strlcpy(str, buffer, read_file + 1);
		resultline = ft_strjoin(resultline, str);
		if (check_for_char(str, '\n'))
		{
			rest_from_last(str, str);
			break ;
		}
	}
	return (resultline);
}
int main()
{
    int fd = open("test.txt",O_RDONLY, 777);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));

	close(fd);
}