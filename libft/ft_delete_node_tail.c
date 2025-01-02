/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node_tail.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:22:00 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:22:02 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes the last node of a singly linked list.
 *
 * @param head Double pointer to the head of the linked list.
 *
 * @return void
 */

void	ft_delete_node_tail(t_list **head)
{
	t_list	*temp;
	t_list	*prev;

	if (*head == NULL)
		return ;
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	prev = temp;
	temp = temp->next;
	prev->next = NULL;
	free(temp);
}
