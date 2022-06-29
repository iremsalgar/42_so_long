/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:03:19 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/20 21:25:38 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen((char *)s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
