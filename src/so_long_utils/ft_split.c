/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 05:57:22 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/21 01:18:01 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	word_count(const char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (word);
		while (*s != c && *s)
			s++;
		word++;
	}	
	return (word);
}

static int	char_count(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**wordgroup;
	int		word;

	if (!s)
		return (0);
	word = 0;
	wordgroup = malloc(sizeof(char *) * word_count(s, c) + 1);
	if (!wordgroup)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		wordgroup[word] = ft_substr(s, 0, char_count(s, c));
		word++;
		s = s + char_count(s, c);
	}
	wordgroup[word] = NULL;
	return (wordgroup);
}
