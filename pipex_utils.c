/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/07 11:46:38 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief 
 *
 * @param 
 * @return 
 */

void free_split_vars(char **split_to_free)
{
	int i;
	
	i=0;
	if (!split_to_free)
		return ;
	while(split_to_free[i])
	{
		free(split_to_free[i]);
		i++;
	}
	free(split_to_free);
	split_to_free = NULL;
}


/**
 * @brief 
 *
 * @param 
 * @return 
 */

// revisar si el return exir(1) esta ok!!!

int open_fd(char *pathern, int flags, mode_t mode)
{
	int fd;
	
	fd = open (pathern, flags, mode);
	if (fd == -1)
	{
		perror_and_exit_1(1);
		//perror("Error opening file open_fd\n");
		//exit (EXIT_FAILURE);
	}
	return (fd);
}

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
		perror("Error: Incorrect number of arguments");
	}
	else if (ref == 2)
	{
		perror("Error creating pipe");
	}
	else if (ref == 3)
	{
		perror("Error creating child process");
	}
	return (1);
}


/**
 * @brief Prints an error message based on the provided reference value.
 *
 * This function handles different error cases and prints an appropriate error 
 * message using `perror`. It is used to centralize error handling for specific 
 * scenarios in the program. 
 *
 * @param ref A short integer used to select the error case. 
 *            1: Error opening file
 *            2: dup2 error
 *            3: execve error
 * @return exit (EXIT_FAILURE).
 */

void perror_and_exit_1 (short int ref)
{
	if (ref == 1)
	{
		perror("Error opening file");
	}
	else if (ref == 2)
	{
		perror("Error: dup2 error");
	}
	else if (ref == 3)
	{
		perror("Error: execve error");
	}
	exit (EXIT_FAILURE);
}
