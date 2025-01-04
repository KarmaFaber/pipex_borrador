/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 14:56:23 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prints an error message based on the provided reference value.
 *
 * This function handles different error cases and prints an appropriate error 
 * message using `perror`. It is used to centralize error handling for specific 
 * scenarios in the program. The function returns 1 to indicate an error.
 *
 * @param ref A short integer used to select the error case. 
 *            1: Incorrect number of arguments.
 *            2: Error creating pipe.
 *            3: Error creating child process.
 * @return Returns 1 to indicate an error.
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