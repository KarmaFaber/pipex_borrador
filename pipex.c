/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 14:45:41 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int pipfd[2];
	pid_t pid;
	
	if (argc != 5) 
		return (perror_and_return_1(1));
		
	//crear pipe
	if (pipe(pipfd) == -1)
		return (perror_and_return_1(2));

	//crear procesos hijo
	pid = fork();
	
	//operaciones con procesos hijo y padre:
	if (pid == -1)
		return (perror_and_return_1(3));
	else if (pid == 0)
	{
		ft_printf("aqui va funcion con procesos hijo");
		//	< archivo1 comando1
		//	< infile ls -l
		//	< argv[1] argv[2]
	}
	else
	{
		ft_printf("aqui va funcion con procesos padre");
		//	comando2 > archivo2
		//	wc -l > outfile
		//	argv[3] > argv[4]
	}
	return (0);
}
