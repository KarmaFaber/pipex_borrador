/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:37 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/08 09:07:15 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"
# include <errno.h>     //referencias de error (errno, es f() no permitida).
# include <fcntl.h>     // open
# include <stdio.h>     //printf, perror
# include <stdlib.h>    //exit
# include <sys/types.h> // wait, waitpid
# include <sys/wait.h>  // wait, waitpid
# include <unistd.h>    // read, write, dup2, execve, dup, unlink, pipe, fork,

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Main code:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/

// pipex.c (5/5)
char	*find_path(char *argv_cmd, char *envp[]);
void	execve_command(char *argv, char **envp);
void	child_process(char *argv[], int pipfd[], char *envp[]);
void	parent_process(char *argv[], int pipfd[], char *envp[]);
int		main(int argc, char *argv[], char *envp[]);

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Utils:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/
// pipex_utils.c (5/5)
char	**get_paths_from_env(char *envp[]);
char	*find_command_in_paths(char *argv_cmd, char **paths);
void	free_split_vars(char **split_to_free);
int		open_fd(char *pathern, int flags, mode_t mode);
int		perror_and_handle(short int ref, int should_exit);

#endif