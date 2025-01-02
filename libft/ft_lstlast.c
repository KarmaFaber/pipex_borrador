/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:55 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:42:22 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the last node of a linked list.
 *
 * This function traverses the linked list starting from the
 * given node, and returns a pointer to the last node in the list.
 *
 * @param lst Pointer to the first node of the linked list.
 *
 * @return Pointer to the last node of the list, or NULL if empty.
 */

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
