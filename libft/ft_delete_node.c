/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:22:10 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:22:12 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a specified node from a linked list.
 *
 * This function removes a node from a linked list. It handles the case
 * where the node to be deleted is the head of the list, as well as
 * the case where it is a middle or last node. After the node is removed,
 * the memory allocated for the node is freed.
 *
 * @param head Pointer to the pointer to the head of the linked list.
 * @param node_to_delete Pointer to the node that needs to be deleted.
 *
 * @return None.
 */

void	ft_delete_node(t_list **head, t_list *node_to_delete)
{
	t_list	*current;
	t_list	*prev;

	if (head == NULL || *head == NULL || node_to_delete == NULL)
		return ;
	if (*head == node_to_delete)
	{
		*head = (*head)->next;
		free(node_to_delete);
		return ;
	}
	current = *head;
	while (current != NULL && current->next != node_to_delete)
	{
		current = current->next;
	}
	if (current != NULL)
	{
		prev = current;
		prev->next = node_to_delete->next;
		free(node_to_delete);
	}
}
