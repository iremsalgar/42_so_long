/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:34:07 by isalgar           #+#    #+#             */
/*   Updated: 2022/01/16 17:28:13 by isalgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dstc = (unsigned char *) dst;
	srcc = (unsigned char *) src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
