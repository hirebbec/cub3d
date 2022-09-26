/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:53:48 by naqua             #+#    #+#             */
/*   Updated: 2021/10/12 16:53:49 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_check(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	stop;
	char	*str;

	if (!s1)
		return (0);
	begin = 0;
	stop = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	while (ft_char_check(s1[begin], set) == 1)
		begin++;
	if (begin == ft_strlen(s1))
	{
		str = ft_strdup("");
		if (!str)
			return (0);
		else
			return (str);
	}
	while (ft_char_check(s1[stop - 1], set) == 1)
		stop--;
	str = ft_substr(s1, begin, stop - begin);
	return (str);
}

/*char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1)
		return (0);
	i = ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (i && ft_strchr(set, *s1))
		i--;
	return (ft_substr(s1, 0, i + 1));
}*/
