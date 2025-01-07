/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:33:40 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/07 11:59:07 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief 
 *
 * @param 
 * @return 
 */

char *find_path(char *argv_cmd, char *envp[])
{
	char **paths;
	char *path;
	char *part_path;
	int i;
	int is_inittialized;

	i = 0;
	is_inittialized = 0;
	paths = NULL;

	//path = NULL;
	
	while (envp[i] != NULL)
    {
		if ((ft_strncmp(envp[i], "PATH", 4) == 0) || (!is_inittialized))
		{
			paths = ft_split(envp[i] + 6, ':');
			is_inittialized = 1;
		}
		
		if (!paths)
		{
			perror ("error en split paths: find_path()");
			free_split_vars(paths);
			exit (EXIT_FAILURE);
		}
		i++;	
	}
	
	i=0;
	while(paths[i]!=NULL)
	{
		if (ft_strncmp(paths[i], "/bin", 4) == 0)
		{
			part_path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(part_path, argv_cmd);
			ft_printf("path en find_path(): %s \n----\n", path);
			free(part_path);
			if (access(path, F_OK | X_OK) == 0)
			{
				printf ("permisos ok\n");
				//ft_printf("%s \n", path);
				free_split_vars(paths);
				return (path);
				
			}
			else 
			{
				perror("error en los permisos");
				return NULL;
			}
			free(path);
			
		}
		i++;
	}

	free_split_vars(paths);
	return (NULL);
	
}


/**
 * @brief 
 *
 * @param 
 * @return 
 */

void execve_command(char *argv, char **envp)
{
	char **exec_argv;
	char *pathern;
	char *aux;

	
	exec_argv = ft_split(argv, 32);
	if (!exec_argv)
	{
		perror("split error in exec_argv. \n");
		free_split_vars(exec_argv);
		exit (EXIT_FAILURE);
	}

	pathern = find_path(exec_argv[0], envp);

	ft_printf("pathern en exec_command(): %s \n-----\n", pathern);

	//arreglo grep:
	if ((ft_strncmp(argv, "grep", 4) == 0))
	{	
		aux = ft_strjoin("\"", exec_argv[1]);
		exec_argv[1]=ft_strjoin(aux, "\"");
		free(aux);
	}
	
	printf("exec_argvs[0]: [%s]\n", exec_argv[0]);
	printf("exec_argvs[1]: [%s]\n", exec_argv[1]);
	
	//execve:
	if(execve(pathern, exec_argv, envp) == -1)
	{
		free(pathern);
		free_split_vars(exec_argv);
		perror_and_exit_1(3);
		//perror ("error al ejecutar execve"); // borrar
		//exit (EXIT_FAILURE); // borrar
	}

	//free stuff:
	free(pathern);
	free_split_vars(exec_argv);
}

/**
 * @brief 
 *
 * @param 
 * @return 
 */

void child_process(char *argv[], int pipfd[], char *envp[])
{
	int fd;
	
	fd = open_fd(argv[1], O_RDONLY, 0777);
	//if (fd == -1)
	//{
	//	perror_and_exit_1(1);
	//	//perror("Error opening file: child\n"); // borrar
	//	//exit (EXIT_FAILURE); // borrar
	//}

	//redifigir stdin al archivo
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		perror_and_exit_1(2);
		//perror("error al duplicar stdin");		 // borrar
		//exit (EXIT_FAILURE);							//borrar
	}
	close(fd);
	
	//redifigir stdout al pipfd[1];
	if ((dup2(pipfd[1], STDOUT_FILENO)== -1))
	{
		close(pipfd[1]);
		perror_and_exit_1(2);
		//perror("error al redirigir stdin a pipfd[1]"); // borrar
		//exit (EXIT_FAILURE);							//borrar
	}
	
	close(pipfd[0]); // Cerrar extremo de lectura del pipe en el hijo
	close(pipfd[1]);
	
	
	//exec child:
	execve_command(argv[2], envp);
	

}

/**
 * @brief 
 *
 * @param 
 * @return 
 */

void parent_process(char *argv[], int pipfd[], char *envp[])
{
	int fd;
	
	fd = open_fd(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	//if (fd ==-1)
	//{
	//	perror_and_exit_1(1);
	//	//perror("Error opening file: parent\n"); // borrar
	//	//exit (EXIT_FAILURE); // borrar
	//}
	
	//redifigir stdin al pipfd[0];
	if ((dup2(pipfd[0] ,STDIN_FILENO)== -1))
	{
		close(pipfd[0]);
		perror_and_exit_1(2);
		//perror("error al redirigir stdin a pipfd[1]");  //borrar
		//exit (EXIT_FAILURE);							//borrar
	}
	
	close(pipfd[0]);
	close(pipfd[1]); // Cerrar extremo de escritura del pipe en el padre
	
	//redifigir stdout al archivo
	if (dup2(fd, STDOUT_FILENO) == -1) 
	{
		close(fd);
        perror_and_exit_1(2);
		//perror("Error redirecting stdout"); // borrar
		//exit (EXIT_FAILURE); 		//borrar
    }
    close(fd);
	
	//execuve parent
	execve_command(argv[3], envp);	
}


int	main(int argc, char *argv[], char *envp[])
{
	int pipfd[2];
	pid_t pid;
	int status;
	
	if (argc != 5) 
		return (perror_and_return_1(1));
		
	//crear pipe
	if (pipe(pipfd) == -1)
		return (perror_and_return_1(2));

	//crear procesos hijo
	pid = fork();
	
	//printf("pid: %i\n", pid);
	
	//operaciones con procesos hijo y padre:
	if (pid == -1)
		return (perror_and_return_1(3));
	
	if (pid == 0)
	{
		//funcion con procesos hijo;
		printf("El hijo entra.\n");
		child_process(argv, pipfd, envp);
		_exit(0);	
		
	}
	
//revisar wait:!!!!!!!---------------------------
	//wait(NULL); // Espera a que el hijo termine
	waitpid(pid, &status, 0); // Espera al hijo específico
	printf("El hijo terminó con estado %d\n", WEXITSTATUS(status));
	printf("El padre entra.\n");
	parent_process(argv, pipfd, envp);
	
	return (0);
}
