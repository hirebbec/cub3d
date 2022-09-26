/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:50:23 by naqua             #+#    #+#             */
/*   Updated: 2021/10/12 16:50:24 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*str;

	dest = (char *)dst;
	str = (const char *)src;
	if (n == 0)
		return (dst);
	if (dst == 0 && src == 0)
		return (0);
	while (n--)
		dest[n] = str[n];
	return (dst);
}
