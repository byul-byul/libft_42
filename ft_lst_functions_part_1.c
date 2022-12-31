/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions_part_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:59 by phelen            #+#    #+#             */
/*   Updated: 2020/11/05 17:58:28 by phelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_item;

	new_item = malloc(sizeof(t_list));
	if (new_item)
	{
		new_item->content = content;
		new_item->next = NULL;
	}
	return (new_item);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	**ending;

	lst_new = NULL;
	ending = &lst_new;
	while (lst)
	{
		*ending = ft_lstnew(f(lst->content));
		if (!*ending)
		{
			ft_lstclear(&lst_new, del);
			break ;
		}
		ending = &(*ending)->next;
		lst = lst->next;
	}
	return (lst_new);
}
