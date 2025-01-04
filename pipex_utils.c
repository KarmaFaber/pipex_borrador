/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 14:47:58 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * 
 * 
 * @brief 
 *
 * @param 
 * @return 
 */

int perror_and_return_1 (short int ref)
{
	if (ref == 1)
	{
		perror("Error: Incorrect number of arguments\n");
	}
	else if (ref == 2)
	{
		perror("Error creating pipe.\n");
	}
	else if (ref == 3)
	{
		perror("Error creating child process\n");
	}
	return (1);
}