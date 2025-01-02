/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:02 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:42:39 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of a linked list to
 *        create a new list with the results. Handles errors by
 *        freeing allocated nodes using a deletion function.
 *
 * @param lst A pointer to the first node of the original linked list.
 * @param f A pointer to a function that takes a void pointer and
 *          returns a new void pointer for the transformed node content.
 * @param del A pointer to a function used to free memory of nodes
 *            if an error occurs during the list creation.
 *
 * @return A pointer to the first node of the new linked list with
 *         transformed elements. Returns NULL if the list is NULL
 *         or if memory allocation fails.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			(del)(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
