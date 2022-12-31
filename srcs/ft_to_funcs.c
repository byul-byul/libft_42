/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:43 by phelen            #+#    #+#             */
/*   Updated: 2020/11/04 14:34:14 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
