/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:20 by mzolotar          #+#    #+#             */
/*   Updated: 2024/11/09 18:43:05 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * This function iterates through the linked list and increments
 * a counter for each node it encounters. The total count is then
 * returned as the size of the list.
 *
 * @param lst Pointer to the first node of the linked list.
 *
 * @return The total number of nodes in the linked list.
 */

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
