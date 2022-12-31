/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions_part_1.c                          :+:      :+:    :+:   */
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
