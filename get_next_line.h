/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:30:14 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/06 22:45:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE  10
// #endif

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
/*utile files*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_for_char(char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif