/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:20:51 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:20:55 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Inserts a new node at the beginning of the linked list.
 *
 * This function creates a new node with the given content and inserts it
 * at the head of the list. The new node becomes the new head of the list,
 * and its next pointer points to the previous head node.
 *
 * @param head A double pointer to the head of the linked list. This allows
 *             modification of the head pointer itself.
 * @param content A pointer to the content to be stored in the new node.
 *                If the content is NULL, it will still create a node, but
 *                the node's content pointer will be NULL.
 *
 * @return void
 */

void	ft_add_node_front(t_list **head, void *content)
{
	t_list	*new_node;

	if (!content)
		return ;
	new_node = ft_lstnew(content);
	if (new_node)
	{
		new_node->next = *head;
		*head = new_node;
	}
}
