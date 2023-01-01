/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:43 by phelen            #+#    #+#             */
/*   Updated: 2020/11/04 14:34:14 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = s;
		s++;
	}
	if (*s == (char)c)
		result = s;
	return ((char *)result);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s) + 1;
	result = (char *)malloc(size);
	if (result)
		ft_memcpy(result, s, size);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result)
	{
		ft_memcpy(result, s1, s1_len);
		ft_memcpy(result + s1_len, s2, s2_len + 1);
	}
	return (result);
}

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

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	str_len;

	if (!str)
		return (NULL);
	if (!set)
		return ((char *)str);
	while (*str && ft_strchr(set, *str))
		str++;
	str_len = ft_strlen(str);
	while (str_len-- && ft_strchr(set, str[str_len]))
		;
	return (ft_substr(str, 0, ++str_len));
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		return (ft_strdup(""));
	str_len -= start;
	str += start;
	if (len >= str_len)
		return (ft_strdup(str));
	result = malloc(len + 1);
	if (result)
	{
		ft_memcpy(result, str, len);
		result[len] = '\0';
	}
	return (result);
}
