/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functions_part_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:59 by phelen            #+#    #+#             */
/*   Updated: 2020/11/05 17:58:28 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1_ptr;
	const unsigned char		*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (n--)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}
