/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:53:30 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/10 03:56:28 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		sstr = (char *)malloc((len + 1) * sizeof(char));
	else
		sstr = (char *)malloc((strlen - start + 1) * sizeof(char));
	ft_strlcpy(sstr, (s + start), (len + 1));
	return (sstr);
}
