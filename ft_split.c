/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:13:08 by phelen            #+#    #+#             */
/*   Updated: 2020/11/15 18:08:25 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_part_count(const char *str, char c)
{
	int		number;
	int		index;

	index = 0;
	number = 0;
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		while (str[index] && str[index] != c)
			index++;
		if (str[index - 1] != c)
			number++;
	}
	return (number);
}

static int	get_substr_len(const char *str, char c)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*get_substr(char **arr, char c)
{
	char	*str;
	int		len;

	len = get_substr_len(*arr, c);
	str = ft_substr(*arr, 0, len);
	*arr += len;
	return (str);
}

static char	**free_array(char **array)
{
	int		index;

	index = -1;
	while (array[++index])
		free(array[index]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *arr, char c)
{
	char	**result;
	char	*str;
	int		part_count;
	int		index;

	if (!arr)
		return (NULL);
	str = (char *)arr;
	part_count = get_part_count(str, c);
	result = malloc(sizeof(char *) * (part_count + 1));
	if (!result)
		return (NULL);
	result[part_count] = NULL;
	index = 0;
	while (index < part_count)
	{
		while (*str == c)
			str++;
		result[index] = get_substr(&str, c);
		if (!result[index])
			return (free_array(result));
		index++;
	}
	return (result);
}
