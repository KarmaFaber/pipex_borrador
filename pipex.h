/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:37 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/04 13:16:35 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"

# include <limits.h>  //limits
# include <stdbool.h> //bollean
# include <stddef.h>  // size_t
# include <stdio.h>   //printf, perror
# include <stdlib.h>  //exit
# include <fcntl.h> // open
# include <unistd.h> // read, write, dup2, execve, dup, unlink, pipe, fork, 
# include <errno.h>	//referencias de error (errno, es f() no permitida).
# include <sys/wait.h> // wait, waitpid
#include <sys/types.h> // wait, waitpid



/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Main:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/

//pipex.c (1/5)
int	main(int argc, char *argv[], char *envp[]);

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Errors:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/



#endif