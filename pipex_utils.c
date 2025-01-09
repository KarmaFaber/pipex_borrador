/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:14:26 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/09 20:30:39 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Retrieves PATH directories from the environment variables.
 *
 * @param envp The environment variables array.
 * @return A string array of directories or NULL if PATH is missing.
 */

char	**get_paths_from_env(char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				perror("Error: ft_split failed to allocate memory");
			break ;
		}
		i++;
	}
	if (!paths)
		perror("Error: PATH variable not found");
	return (paths);
}

/**
 * @brief Searches for a command in the given PATH directories.
 *
 * @param argv_cmd The command to locate.
 * @param paths The array of PATH directories.
 * @return The full executable path or NULL if not found.
 */

char	*find_command_in_paths(char *argv_cmd, char **paths)
{
	char	*path;
	char	*full_path;
	int		i;

	i = 0;
	path = NULL;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			break ;
		path = ft_strjoin(full_path, argv_cmd);
		free(full_path);
		if (!path)
			break ;
		if (access(path, F_OK | X_OK) == 0)
		{
			free_split_vars(paths);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

/**
 * @brief Frees a dynamically allocated array of strings.
 *
 * @param split_to_free The array of strings to free.
 */

void	free_split_vars(char **split_to_free)
{
	int	i;

	if (!split_to_free)
		return ;
	i = 0;
	while (split_to_free[i])
	{
		free(split_to_free[i]);
		i++;
	}
	free(split_to_free);
}

/**
 * @brief Opens a file with the specified flags and mode.
 *
 * @param pathern The file path to open.
 * @param flags The flags used for opening the file.
 * @param mode The file mode for creation (if applicable).
 * @return The file descriptor or an error code on failure.
 */

int	open_fd(char *pathern, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathern, flags, mode);
	if (fd == -1)
		return (perror_and_handle(4, 1));
	return (fd);
}

/**
 * @brief Prints an error message based on the provided reference value.
 *
 * This function handles different error cases and prints an appropriate error
 * message using `perror`. It can either return `1` to indicate an error or
 * terminate the program by calling `exit(EXIT_FAILURE)`.
 *
 * @param ref A short integer used to select the error case:
 *            1: Incorrect number of arguments.
 *            2: Error creating pipe.
 *            3: Error creating child process.
 *            4: Error opening file.
 *            5: Error with dup2.
 * @param should_exit If `1`,
 * 					the function exits the program with `EXIT_FAILURE`.
 * @param should_exit If `0`, it simply returns `1`.
 *
 * @return Returns `1` if `should_exit` is `0`. Otherwise, it exits the program.
 */

int	perror_and_handle(short int ref, int should_exit)
{
	if (ref == 1)
		perror("Error: Incorrect number of arguments");
	else if (ref == 2)
		perror("Error creating pipe");
	else if (ref == 3)
		perror("Error creating child process");
	else if (ref == 4)
		perror("Error opening file");
	else if (ref == 5)
		perror("Error with dup2");
	if (should_exit)
		exit(EXIT_FAILURE);
	return (1);
}
