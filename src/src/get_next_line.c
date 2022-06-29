/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:03:11 by isalgar           #+#    #+#             */
/*   Updated: 2022/05/26 02:46:30 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
#include<stdio.h>

int	getline2(int fd, t_list *y)
{
	char	*str;
	int		rd;

	rd = 1;
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	while (rd > 0 && ft_chk(y->x, 1, '\n') == 1)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return (0);
		}
		str[rd] = 0;
		y->x = ft_strjoin(y->x, str);
	}
	free(str);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*y;
	t_list			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(y);
		return (NULL);
	}
	if (!y)
		y = ft_lstnew();
	if (!getline2(fd, y))
		return (NULL);
	line = ft_controller (y->x, '\n', y);
	tmp = y->next;
	free(y);
	y = tmp;
	if (!*line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

t_list	*ft_lstnew(void)

{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->x = NULL;
	new->next = 0;
	return (new);
}
/*
#include<fcntl.h>
#include<stdio.h>
int main()
{
	char *line;
	int fd = open("a.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("1.%s", line);
	free(line);
	line = get_next_line(fd);
	printf("2.%s", line);
	free(line);
}*/
