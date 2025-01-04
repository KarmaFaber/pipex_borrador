/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 13:29:32 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int pipfd[2];
	pid_t pid;
	
	if (argc != 5)
		ft_printf("aqui va fucnion handle_exit");
		
	//crear pipe
	if (pipe(pipfd) == -1)
	{
		perror("Error creating pipe.\n");
		return (1);
	}

	//crear procesos hijo
	pid = fork();
	
	//operaciones con procesos hijo y padre:
	if (pid == -1)
	{
		perror("Error creating child process\n");
		return (1);
	}
	else if (pid == 0)
	{
		ft_printf("aqui va funcion con procesos hijo");
	}
	else
	{
		ft_printf("aqui va funcion con procesos padre");
	}
	return (0);
}

