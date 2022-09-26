/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:53:39 by naqua             #+#    #+#             */
/*   Updated: 2021/10/12 16:53:40 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	sym;

	str = (char *)s;
	sym = (char)c;
	str += ft_strlen(s);
	while (str >= s)
	{
		if (*str == sym)
			return (str);
		str--;
	}
	return (0);
}
