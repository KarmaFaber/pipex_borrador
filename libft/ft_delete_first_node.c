/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_first_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:21:44 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:21:46 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes the first node of a linked list and updates the head pointer.
 *
 * This function removes the first node of a linked list and frees its memory.
 * If the node contains dynamically allocated content,
	it also frees the content.
 * The head pointer is updated to point to the next node in the list.
 * If the list is empty (head is NULL), the function does nothing.
 *
 * @param head Double pointer to the head of the linked list.
 *
 * @return void. The function does not return a value.
 */

#include "libft.h"

void	ft_delete_first_node(t_list **head)
{
	t_list	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	if (temp->content)
		free(temp->content);
	free(temp);
}
