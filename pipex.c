/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/07 14:03:59 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief
 *
 * @param
 * @return
 */

char	*find_path(char *argv_cmd, char *envp[])
{
	char	**paths;
	char	*path;

	paths = get_paths_from_env(envp);
	if (!paths)
		return (NULL);
	path = find_command_in_paths(argv_cmd, paths);
	free_split_vars(paths); // Liberar las rutas si no se encontró el binario
	return (path);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	execve_command(char *argv, char **envp)
{
	char	**exec_argv;
	char	*path;

	exec_argv = ft_split(argv, ' ');
	if (!exec_argv)
    {
        perror("Error: Memory allocation failed for exec_argv");
        exit(EXIT_FAILURE);
    }
	path = find_path(exec_argv[0], envp);
	if (!path)
	{
		free_split_vars(exec_argv);
		perror("Error with path");
		exit(EXIT_FAILURE);
	}
	if (execve(path, exec_argv, envp) == -1)
	{
		free(path);
		free_split_vars(exec_argv);
		perror("Error with execve");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	child_process(char *argv[], int pipfd[], char *envp[])
{
	int	fd;

	fd = open_fd(argv[1], O_RDONLY, 0777);
	// redifigir stdin al archivo
	dup2(fd, STDIN_FILENO);
	// redifigir stdout al pipfd[1];
	dup2(pipfd[1], STDOUT_FILENO);
	close(fd);
	close(pipfd[0]); // Cerrar extremo de lectura del pipe en el hijo
	close(pipfd[1]);
	// exec child:
	execve_command(argv[2], envp);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	parent_process(char *argv[], int pipfd[], char *envp[])
{
	int	fd;

	fd = open_fd(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	// redifigir stdin al pipfd[0];
	dup2(pipfd[0], STDIN_FILENO);
	// redifigir stdout al archivo
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipfd[0]);
	close(pipfd[1]); // Cerrar extremo de escritura del pipe en el padre
	// execuve parent
	execve_command(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipfd[2];
	pid_t	pid;

	if (argc != 5)
		return (perror_and_handle(1, 0));
	// crear pipe
	if (pipe(pipfd) == -1)
		return (perror_and_handle(2, 0));
	// crear procesos hijo
	pid = fork();
	// operaciones con procesos hijo y padre:
	if (pid == -1)
		return (perror_and_handle(3, 0));
	if (pid == 0)
	{
		child_process(argv, pipfd, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, pipfd, envp);
	}
	return (0);
}
