/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:03:01 by msumset           #+#    #+#             */
/*   Updated: 2022/07/27 14:03:02 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t len)
{
	char	*d;
	char	*s;

	if (dst == src || len == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}
