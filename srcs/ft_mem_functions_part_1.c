/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functions_part_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:59 by phelen            #+#    #+#             */
/*   Updated: 2020/11/05 17:58:28 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char		*src_ptr;
	unsigned char			*dst_ptr;

	src_ptr = src;
	dst_ptr = dest;
	while (n--)
	{
		*dst_ptr = *src_ptr;
		if (*src_ptr == (unsigned char)c)
			return ((void *)(dst_ptr + 1));
		dst_ptr++;
		src_ptr++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s_ptr;

	s_ptr = s;
	while (n--)
	{
		if (*s_ptr == (unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	if (dest == src)
		return (dest);
	src_ptr = src;
	dest_ptr = dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	if (dest == src)
		return (dest);
	src_ptr = src;
	dest_ptr = dest;
	if (dest_ptr < src_ptr)
		while (n--)
			*dest_ptr++ = *src_ptr++;
	else
	{
		dest_ptr += n - 1;
		src_ptr += n - 1;
		while (n--)
			*dest_ptr-- = *src_ptr--;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
