/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:20:22 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/19 12:15:13 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>

void	parent_p(f2, cmd2)
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
	exit(EXIT_FAILURE);
}

int	execve(const char *path, char *const argv[], char *envp[]);

void	pipex(int f1, int f2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("fork: "));
	if (!parent)
		child_p(f1, cmd1);
	else
		parent_p(f2, cmd2);
}

int	main(int ac, char **ag, char **envp)
{
	int	f1;
	int	f2;
	f1 = open(ag[1], O_RDONLY);
	f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, ag, envp);
	return (0);
}

/* int	main(void)
{
	printf("hola");
} */
