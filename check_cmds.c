/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:08:56 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/01 16:20:41 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	here_doc_condition(char **argv)
{
	int	i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		i = 3;
	else
		i = 2;
	return (i);
}

void	check_cmd(int argc, char **argv, char **envp)
{
	char	*path;
	char	**args;
	int		i;

	i = here_doc_condition(argv);
	while (i <= (argc - 2))
	{
		args = ft_split(argv[i], ' ');
		path = get_path(args, envp);
		if (!path)
		{
			free(path);
			ft_putstr_fd("Invalid command : ", 2);
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
