/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 14:51:25 by mzolotar         ###   ########.fr       */
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

/*
	if (pid == -1) // Error en fork
        return (perror_and_return_1(3));
 // Código para el hijo (PID == 0)
    else if (pid == 0)
    {
        // Redirigir entradas y salidas
        // Primero, cierras el descriptor de lectura en el hijo porque solo necesita escribir en el pipe
        close(pipfd[0]); // Cerrar extremo de lectura del pipe en el hijo
        // Redirige stdout al pipe
        dup2(pipfd[1], STDOUT_FILENO); // Redirigir stdout al pipe
        close(pipfd[1]); // Cerrar el pipe original después de redirigir

        // Aquí pones la lógica del hijo: comando1 < archivo1
        ft_printf("Aquí va la función con procesos hijo\n");
        // Podrías ejecutar un comando con execvp (por ejemplo: "ls -l") aquí
        // execvp(argv[1], argv + 1); // Ejemplo de ejecución de un comando
    }
    // Código para el padre (PID > 0)
    else
    {
        // Redirigir la entrada estándar para leer del pipe
        close(pipfd[1]); // Cerrar extremo de escritura del pipe en el padre
        // Redirigir stdin al pipe
        dup2(pipfd[0], STDIN_FILENO); // Redirigir stdin al pipe
        close(pipfd[0]); // Cerrar el pipe original después de redirigir

        // Aquí pones la lógica del padre: comando2 > archivo2
        ft_printf("Aquí va la función con procesos padre\n");
        // Podrías ejecutar otro comando con execvp aquí
        // execvp(argv[3], argv + 3); // Ejemplo de ejecución de un comando
    }
*/
