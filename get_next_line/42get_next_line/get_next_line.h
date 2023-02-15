/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamzeh <ahamzeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:16:41 by ahamzeh           #+#    #+#             */
/*   Updated: 2023/02/16 02:16:42 by ahamzeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_to_str(int fd, char *snt_str);
char	*ft_get_line(char *snt_str);
char	*ft_new_str(char *snt_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *snt_str, char *buff);
size_t	ft_strlen(const char *s);
#endif
