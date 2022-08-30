/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:20:22 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/30 16:16:15 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

static void	child1(int *fd, char **argv, char **envp)
{
	int		fd_infile;
	char	**args;
	char	*path;

	close(fd[0]);
	fd_infile = get_fd(argv[1], 0);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	args = ft_split(argv[2], ' ');
	path = get_path(args, envp);
	if (execve(path, args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found:", 2);
		ft_putendl_fd(args[0], 2);
		ft_free(args);
		free(path);
		exit(0);
	}
}

static void	child2(int *fd, char **argv, char **envp)
{
	int		fd_outfile;
	char	**args;
	char	*path;

	close(fd[1]);
	fd_outfile = get_fd(argv[4], 1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	args = ft_split(argv[3], ' ');
	path = get_path(args, envp);
	if (execve(path, args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found:", 2);
		ft_putendl_fd(args[0], 2);
		ft_free(args);
		free(path);
		exit(0);
	}
}

void	pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
		child1(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
			child2(fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(0);
	}
	check_cmd(argc, argv, envp);
	pipex(argv, envp);
	return (0);
}
