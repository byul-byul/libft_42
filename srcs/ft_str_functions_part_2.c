/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions_part_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:43 by phelen            #+#    #+#             */
/*   Updated: 2020/11/04 14:34:14 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;

	dst_size = ft_strlen(dst);
	if (dst_size >= size)
		return (ft_strlen(src) + size);
	ft_strlcpy(dst + dst_size, src, size - dst_size);
	return (dst_size + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (!dst)
		return (0);
	index = 0;
	while (src[index] && index + 1 < size)
	{
		dst[index] = src[index];
		index++;
	}
	if (size != 0)
		dst[index] = '\0';
	return (ft_strlen(src));
}

char	*ft_strmapi(char const *str, char (*f) (unsigned int, char))
{
	char	*result;
	int		index;

	if (!str)
		return (NULL);
	result = ft_strdup(str);
	if (result)
	{
		index = 0;
		while (result[index])
		{
			result[index] = f(index, result[index]);
			index++;
		}
	}
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	if (*s1 && *s2)
	{
		while (s1[index] && --n)
		{
			if (s1[index] != s2[index])
				break ;
			index++;
		}
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2_len;

	if (!(*s2))
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	if (ft_strlen(s1) < s2_len)
		return (NULL);
	while (len-- >= s2_len)
	{
		if (!ft_strncmp(s1, s2, s2_len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
