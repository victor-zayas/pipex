/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:25:00 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/25 12:31:03 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

static char	**make_path(char **args, char **envp)
{
	char	**path;
	char	*aux;
	int		i;

	path = NULL;
	aux = NULL;
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	aux = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	path = ft_split(aux, ':');
	free(aux);
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], args[0]);
		i++;
	}
	return (path);
}

//execve(ft_strjoin(path[i], argv[1]), &argv[1], envp);

char	*get_path(char **args, char **envp)
{
	int		i;
	char	**aux;
	char	*path;

	i = -1;
	aux = make_path(args, envp);
	while (aux[++i])
	{
		if (!access(aux[i], F_OK))
		{
			path = ft_substr(aux[i], 0, ft_strlen(aux[i]));
			ft_free(aux);
			return (path);
		}
	}
	ft_free(aux);
	return (NULL);
}

int	get_fd(char *file, int n)
{
	int	fd;

	if (n == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			ft_putstr_fd("Invalid or missing input file\n", 2);
			exit(0);
		}
		return (fd);
	}
	else
	{
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		return (fd);
	}
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	check_cmd(int argc, char **argv, char **envp)
{
	char	*path;
	char	**args;
	int		i;

	i = 2;
	while (i <= (argc - 2))
	{
		args = ft_split(argv[i], ' ');
		path = get_path(args, envp);
		if (!path)
		{
			free(path);
			ft_putstr_fd("Invalid command: ", 2);
			ft_putendl_fd(args[0], 2);
			ft_free(args);
			exit(0);
		}
		else
		{
			ft_free(args);
			free(path);
		}
		i++;
	}
}
