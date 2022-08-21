/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:39:20 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/08/21 20:42:06 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

static int	ft_len(const char *str, char c)
{
	int	count;

	count = -1;
	while (str[++count] != '\0')
	{
		if (str[count] == c)
			return (count);
	}
	return (count);
}

char	*ft_strjoin(char *str, char *tmp)
{
	char	*s;
	int		i;
	int		j;

	if (!str)
	{
		str = malloc(1);
		*str = '\0';
	}
	s = (char *)malloc(ft_len(str, 0) + ft_len(tmp, 0) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (tmp[j])
		s[i++] = tmp[j++];
	free (str);
	s[i] = '\0';
	return (s);
}
