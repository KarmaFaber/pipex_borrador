/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:37 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/03 22:41:49 by mzolotar         ###   ########.fr       */
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
# include <unistd.h> // read, write, dup2, execve, dup, unlink, pipe, 
# include <errno.h>	//referencias de error (errno, es f() no permitida).


/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Main:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/

//pipex.c (1/5)
int main(void);

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Errors:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/



#endif