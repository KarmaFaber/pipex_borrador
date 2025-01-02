/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:48 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:42:07 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of a linked list.
 *
 * This function iterates over each node in the linked list and applies
 * the provided function to the data contained in each node. The function
 * is called once for each node, allowing the caller to modify or inspect
 * the node's data.
 *
 * @param lst Pointer to the first node of the linked list.
 * @param f Pointer to a function that takes a void pointer and returns void.
 *          This function will be applied to the data of each node.
 *
 * @return This function does not return a value.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
