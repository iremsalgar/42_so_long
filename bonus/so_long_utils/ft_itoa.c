/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:31:39 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/15 13:31:44 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	ft_digitnum(int n)
{
	int		count;

	count = !n;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	sign = n < 0;
	len = ft_digitnum(n) + sign;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (sign)
	{
		result[0] = '-';
		result[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		result[len] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
