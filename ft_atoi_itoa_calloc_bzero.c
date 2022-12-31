/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa_calloc_bzero.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:59 by phelen            #+#    #+#             */
/*   Updated: 2020/11/05 17:58:28 by phelen           ###   ########.fr       */
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
			itoa[0] = '-';
		itoa[num_len] = '\0';
		while (num)
		{
			if (num < 0)
				itoa[--num_len] = (num % 10) * -1 + '0';
			else
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_memory;

	allocated_memory = malloc(nmemb * size);
	if (allocated_memory)
		ft_bzero(allocated_memory, nmemb * size);
	return (allocated_memory);
}
