/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:23 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:40:56 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
	DESCRIPTION :
	The function ft_lstadd_front adds a new node to the front of a list:
		[NEW]->[.]->[.]->[.]->[NULL]

	RETURN VALUE : None.
*/

/**
 * @brief Adds a new node at the beginning of a linked list.
 *
 * This function checks if the list is empty. If it is, the new node
 * becomes the first and only node. If the list is not empty, the new
 * node is linked to the current first node, and then it becomes the
 * new head of the list.
 *
 * @param lst A pointer to the head of the list.
 * @param new The new node to be added at the beginning of the list.
 *
 * @return void
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
