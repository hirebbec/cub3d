/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:51:31 by naqua             #+#    #+#             */
/*   Updated: 2022/07/04 20:03:14 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *str, char c)
{
	int	i;
	int	counter;
	int	inword;

	inword = 0;
	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && inword == 0)
		{
			counter++;
			inword = 1;
		}
		else if (str[i] == c)
			inword = 0;
		i++;
	}
	return (counter);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char	**ft_free(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free (result);
	return (NULL);
}

static char	**splitter(int words_count, char const *s, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*s == c)
			s++;
		result[i] = (char *)malloc(sizeof(char) * (word_len(s, c) + 1));
		if (!result)
			return (ft_free(result, i));
		j = 0;
		while (*s != c && *s != '\0')
		{
			result[i][j] = *s;
			j++;
			s++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		words_count;
	char	**result;

	if (!s)
		return (NULL);
	words_count = words_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	return (splitter(words_count, s, c, result));
}
