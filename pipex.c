/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/09 20:24:03 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Finds the executable path for a given command.
 *
 * @param argv_cmd The command to locate.
 * @param envp The environment variables array.
 * @return A string containing the executable path or NULL on failure.
 */

char	*find_path(char *argv_cmd, char *envp[])
{
	char	**paths;
	char	*path;

	paths = get_paths_from_env(envp);
	if (!paths)
		return (NULL);
	path = find_command_in_paths(argv_cmd, paths);
	return (path);
}

/**
 * @brief Executes a command using execve.
 *
 * @param argv The command string with arguments.
 * @param envp The environment variables array.
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
 * @brief Executes the child process logic for a pipeline.
 *
 * @param argv The array of command-line arguments.
 * @param pipfd The file descriptors for the pipe.
 * @param envp The environment variables array.
 */

void	child_process(char *argv[], int pipfd[], char *envp[])
{
	int	fd;

	fd = open_fd(argv[1], O_RDONLY, 0777);
	dup2(fd, STDIN_FILENO);
	dup2(pipfd[1], STDOUT_FILENO);
	close(fd);
	close(pipfd[0]);
	close(pipfd[1]);
	execve_command(argv[2], envp);
}

/**
 * @brief Executes the parent process logic for a pipeline.
 *
 * @param argv The array of command-line arguments.
 * @param pipfd The file descriptors for the pipe.
 * @param envp The environment variables array.
 */

void	parent_process(char *argv[], int pipfd[], char *envp[])
{
	int	fd;

	fd = open_fd(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(pipfd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipfd[0]);
	close(pipfd[1]);
	execve_command(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipfd[2];
	pid_t	pid;

	if (argc != 5)
		return (perror_and_handle(1, 0));
	if (pipe(pipfd) == -1)
		return (perror_and_handle(2, 0));
	pid = fork();
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
