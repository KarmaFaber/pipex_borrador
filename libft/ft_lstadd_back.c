/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:14 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:40:15 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new node to the end of a linked list.
 *
 * This function appends the given new node to the end of the list.
 * If the list is empty, the new node becomes the head of the list.
 * If the list is not empty, the function traverses to the last node
 * and updates its `next` pointer to point to the new node.
 *
 * @param lst A pointer to the pointer of the head node of the list.
 *            This allows the function to modify the head if the list
 *            is empty and the new node is the first node.
 * @param new The node to be added at the end of the list. This node
 *            should be properly allocated and initialized before being
 *            passed to this function.
 *
 * @return This function does not return a value.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
