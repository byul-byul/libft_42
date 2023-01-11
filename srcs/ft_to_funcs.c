/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:43 by phelen            #+#    #+#             */
/*   Updated: 2020/11/04 14:34:14 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int num)
{
	int		count;

	count = 1;
	if (num < 0)
		count++;
	while (1)
	{
		num /= 10;
		if (!num)
			break ;
		count++;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	char	*itoa;
	int		num_len;

	num_len = get_num_len(num);
	itoa = malloc(num_len + 1);
	if (itoa)
	{
		if (num == 0)
			itoa[0] = '0';
		else if (num < 0)
		{
			itoa[0] = '-';
			num = -num;
		}
		itoa[num_len] = '\0';
		while (num)
		{
			itoa[--num_len] = num % 10 + '0';
			num /= 10;
		}
		return (itoa);
	}
	return (NULL);
}

int	ft_atoi(const char *nptr)
{
	int		atoi;
	int		sign;

	atoi = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		atoi = atoi * 10 + (*nptr - '0');
		nptr++;
	}
	return (atoi * sign);
}

int	ft_tolower(int c)
{
	if (ft_islowercase(c))
		return (c + 32);
	else
		return (c);
}

int	ft_toupper(int c)
{
	if (ft_isuppercase(c))
		return (c - 32);
	else
		return (c);
}
