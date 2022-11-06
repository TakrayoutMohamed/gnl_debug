/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:29:34 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/05 20:17:19 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rest_from_last(char *str, char *buffer)
{
	int	i;

	i = 0;
	while (*buffer && *buffer != '\n')
		buffer++;
	buffer++;
	ft_strlcpy(str,buffer,ft_strlen(buffer) + 1);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*resultline;
	static char	str[BUFFER_SIZE];
	char		c;

	resultline = NULL;
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (resultline == NULL)
			resultline = ft_strjoin(resultline, str);
		ft_strlcpy(str,buffer,BUFFER_SIZE + 1);
		resultline = ft_strjoin(resultline, str);
		if (check_for_char(str, '\n'))
		{
			rest_from_last(str,str);
			break ;
		}
	}
	return (resultline);
}

int main()
{
    int fd = open("test.txt",O_RDONLY, 777);
    // char *line = get_next_line(fd);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	close(fd);
}