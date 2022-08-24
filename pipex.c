/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:20:22 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/24 14:30:42 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int __attribute__((unused))argc, char __attribute__((unused))**argv, char **envp)
{
	char	**path;
	char	*aux;
	int		i;

	path = NULL;
	aux = NULL;
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			aux = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			path = ft_split(aux, ':');
			free(aux);
			break ;
		}
		i++;
	}
	i = 0;

	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		execve(ft_strjoin(path[i], argv[1]), &argv[1], envp);
		//printf("%s\n", path[i]);
		i++;
	}
	//return (path);
}

/* void	parent_p(f2, cmd2)
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1])
	close(f2);
	exit(EXIT_FAILURE);
}

void	child_p(int f1, char *cmd1)
{
	dup2(f1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	exit(EXIT_FAILURE);
}

int	execve(const char *path, char *const argv[], char *envp[]);

void    pipex(int f1, int f2, char *cmd1, char *cmd 2)
{
    int   end[2];
    int   status;
    pid_t child1;
    pid_t child2;
	
    pipe(end);
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(f1, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_two(f2, cmd2);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argv, envp);
	return (0);
} */
