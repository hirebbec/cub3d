/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:44:37 by naqua             #+#    #+#             */
/*   Updated: 2021/10/12 16:44:39 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	lstr;
	size_t	i;

	i = 0;
	lstr = count * size;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i != lstr)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
