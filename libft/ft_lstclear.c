/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:31 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:41:32 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and all subsequent nodes.
 *
 * @param lst Address of a pointer to the first node of the list.
 * @param del Function pointer to delete the content of each node.
 *
 * @return None, the list is cleared and the pointer is set to NULL.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (!*lst)
		return ;
	head = *lst;
	while (head)
	{
		temp = head->next;
		(*del)(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}
