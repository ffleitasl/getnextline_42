/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:44 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/20 20:52:39 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 40
# endif

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif