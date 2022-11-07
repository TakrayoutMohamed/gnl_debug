/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/08 00:19:53 by mohtakra         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char		*resultline;
	static char	str[BUFFER_SIZE];
	int			read_file;

	resultline = NULL;
	read_file = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_file && check_for_char(str, '\n'))
	{
		resultline = ft_strjoin(resultline, str);
		rest_from_last(str, str);
		return (resultline);
	}	
	else if (read_file )
		resultline = ft_strjoin(resultline, str);
	while (read_file)
	{
		// printf("here");
		read_file = read(fd, buffer, BUFFER_SIZE);
		if (read_file == -1)
			return (NULL);
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
// int main()
// {
// char str[] = "/Users/mohtakra/Desktop/RepoGetnextline/gnlTester/files/alternate_line_nl_with_nl";
//     int fd = open(str,O_RDONLY, 777);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
// 	close(fd);
// }