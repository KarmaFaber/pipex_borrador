/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout_to_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:50:19 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/03 18:53:11 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdout_to_file(char *file_name, void (*funcion_x)(void))
{
	int	fd;
	int	saved_stdout;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);  // Abrir archivo para redirigir stdout
	if (fd == -1)
		return ;
	saved_stdout = dup(STDOUT_FILENO); // Guardar stdout original
	if (saved_stdout == -1)
	{
		close(fd);
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) == -1) // Redirigir stdout al archivo
	{
		close(fd);
		close(saved_stdout);
		return ;
	}
	close(fd);
	if (funcion_x)   // Ejecutar la función proporcionada
		funcion_x();
	if (dup2(saved_stdout, STDOUT_FILENO) == -1) // Restaurar stdout original
		perror("Error al restaurar stdout");
	close(saved_stdout);
}


/*
// Rename function to redirect_stdout_to_file
void redirect_stdout_to_file(char *file_name, void (*func_to_execute)(void)) {
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) {
        perror("Error duplicating stdout");
        close(fd);
        return;
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Error redirecting stdout");
        close(fd);
        close(saved_stdout);
        return;
    }
    close(fd);

    if (func_to_execute) {
        func_to_execute();
    }

    if (dup2(saved_stdout, STDOUT_FILENO) == -1) {
        perror("Error restoring stdout");
    }
    close(saved_stdout);
}

// Call example
void sample_function() {
    printf("This will go into the file!\n");
}

int main() {
    redirect_stdout_to_file("output.txt", sample_function);
    return 0;
}

*/