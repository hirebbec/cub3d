/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:52:38 by naqua             #+#    #+#             */
/*   Updated: 2022/07/04 20:07:15 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s2 == 0)
		return ((char *)s1);
	else if (s1 == 0)
		return ((char *)s2);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s2 == 0)
		return ((char *)s1);
	else if (s1 == 0)
		return ((char *)s2);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s2);
	return (str);
}

char	*ft_strjoin_free1(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s2 == 0)
		return ((char *)s1);
	else if (s1 == 0)
		return ((char *)s2);
	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strjoin_free_all(char *s1, char *s2, int i)
{
	char	*str;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s2 == 0)
		return ((char *)s1);
	else if (s1 == 0)
		return ((char *)s2);
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
