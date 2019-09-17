/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:35:06 by bpole             #+#    #+#             */
/*   Updated: 2019/09/17 17:54:06 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*first;
	t_list	*temp;
	t_list	*create;
	t_list  *prev;

	first = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp = f(lst);
		if (!(create = ft_lstnew(temp->content, temp->content_size)))
		{
			//ft_lstdel(&first, ft_bzero);
			return (NULL);
		}
		if (!first)
		{
			first = create;
			prev = create;
		}
		else
			prev->next = create;
		lst = lst->next;
	}
	return (first);
}
