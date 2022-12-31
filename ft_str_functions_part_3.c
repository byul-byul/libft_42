/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions_part_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:43 by phelen            #+#    #+#             */
/*   Updated: 2020/11/04 14:34:14 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
