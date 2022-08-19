/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:34:16 by amarzana          #+#    #+#             */
/*   Updated: 2022/07/11 09:56:51 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>

char	*ft_make_word(char const *s, char c, int i)
{
	char	*word;
	int		count;

	count = i;
	if (s[count++] == 39)
	{
		while (s[count] && s[count] != 39)
			count++;
		word = ft_substr(s, i + 1, count - i - 1);
	}
	else
	{
		while (s[count] && s[count] != c)
			count++;
		word = ft_substr(s, i, count - i);
	}
	return (word);
}

char	*ft_get_word(char const *s, char c, int row)
{
	int		i;
	int		count;
	char	*word;

	word = NULL;
	i = -1;
	count = -1;
	while (++i < (int)ft_strlen(s) && s[i])
	{
		if (s[i] != c)
			count++;
		if (count == row && s[i] != c)
		{
			word = ft_make_word(s, c, i);
			if (!word)
				return (NULL);
		}
		while (s[i] && s[i] != c)
			if (s[i++] == 39)
				while (s[i] && s[i] != 39)
					i++;
	}
	return (word);
}

int	ft_coincidences(char const *s, char c)
{
	int	coin;
	int	i;

	i = 0;
	coin = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != 39)
			coin++;
		while (s[i] && (s[i] != c || s[i] == 39))
		{
			if (s[i] == 39)
			{
				coin++;
				i++;
				while (s[i] && s[i] != 39)
					i++;
			}
			i++;
		}
		if (s[i])
			i++;
	}
	return (coin);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		coin;
	int		i;

	if (!s)
		return (NULL);
	coin = ft_coincidences(s, c);
	if (c == '\0' && ft_strlen(s) > 0)
		coin = 1;
	split = (char **)malloc((coin + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < coin)
	{
		split[i] = ft_get_word(s, c, i);
		if (split[i] == NULL)
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
