/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_functions_part_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:59 by phelen            #+#    #+#             */
/*   Updated: 2020/11/05 17:58:28 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_islowercase(int c)
{
	return ((c >= 65 && c <= 90));
}

int	ft_isuppercase(int c)
{
	return ((c >= 97 && c <= 122));
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isalpha(int c)
{
	return (ft_islowercase(c) || ft_isuppercase(c));
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
