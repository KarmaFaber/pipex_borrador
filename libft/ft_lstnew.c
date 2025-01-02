/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:10 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:42:53 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new node for a linked list.
 *
 * This function allocates memory for a new node, initializes the node's
 * content with the provided value, and sets the next pointer to NULL.
 *
 * @param content Pointer to the data that will be stored in the new node.
 *
 * @return t_list* Pointer to the newly created node, or NULL if allocation
 * fails.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
