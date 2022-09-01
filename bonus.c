/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:20:22 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/01 16:19:03 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

static void	child(char **argv, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(*argv, ' ');
	path = get_path(args, envp);
	if (execve(path, args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found", 2);
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
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		child(argv, envp);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

static void	dups_function(int argc, char **argv)
{
	int	fdin;
	int	fdout;

	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		fdin = get_fd(argv[2], 0);
		fdout = get_fd(argv[argc - 1], 2);
	}
	else
	{
		fdin = get_fd(argv[1], 0);
		fdout = get_fd(argv[argc - 1], 1);
	}
	dup2(fdin, STDIN_FILENO);
	close (fdin);
	dup2(fdout, STDOUT_FILENO);
	close (fdout);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	pid;

	if (argc < 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(0);
	}
	else
	{
		if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
			i = 3;
		else
			i = 2;
		check_cmd(argc, argv, envp);
		dups_function(argc, argv);
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
		{
			while (i < (argc - 2))
				pipex(&argv[i++], envp);
			child(&argv[i], envp);
		}
		else
			wait(NULL);
	}
}
