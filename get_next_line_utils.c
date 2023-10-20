/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:22:29 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/20 20:58:54 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	result = malloc (count * size);
	if (!result)
	{
		return (NULL);
	}
	else
	{
		ft_bzero (result, (count * size));
	}
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i ++;
	}
}
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if(!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)str + i);
		}
		i ++;
	}
	if (str[i] == (char)c)
	{
		return ((char *)str + i);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s || start >= ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[j] = s[start + i];
			j ++;
		i ++;
	}
	sub[j] = '\0';
	return (sub);
}
