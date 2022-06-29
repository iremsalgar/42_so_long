/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:51:52 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/27 20:01:20 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_other_walls(t_info *map, int i, int x)
{
	int	len_length;

	while (map->map[0][i] != '\0' && map->map[0][i] != '\n')
		i++;
	len_length = i;
	i = -1;
	while (++i <= map->line_height - 1)
		if (map->map[i][0] != '1')
			exit_game(map, 3);
	i = -1;
	while (++i != map->line_height)
		if (map->map[i][len_length - 1] != '1')
			exit_game(map, 2);
	while (x <= map->line_height - 1)
	{
		i = 0;
		while (map->map[x][i] != '\0')
			i++;
		if (i != len_length)
			exit_game(map, 2);
		x++;
	}
	detect_component(map);
}

void	check_first_last_wall(t_info *map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map->map[0][++x] != '\0')
		if (map->map[0][x] != '1')
			exit_game(map, 2);
	while (++y <= map->line_height - 1)
		if (map->map[map->line_height - 1][y] != '1')
			exit_game(map, 2);
	check_other_walls(map, 0, 0);
}

void	map_length_widht(t_info *map)
{
	int	i;
	int	line_height;
	int	line_width;

	line_height = 0;
	i = -1;
	while (map->map[++i])
		;
	line_height = i;
	i = 0;
	while (map->map[0][i] != '\n' && map->map[0][i] != '\0')
		i++;
	line_width = i;
	map->line_width = line_width;
	map->line_height = line_height;
	check_first_last_wall(map);
}

void	check_ber(char *s)
{
	int	i;

	i = 0;
	if (!s)
		exit(0);
	while (s[i] != '\0')
		i++;
	if (s[i - 1] != 'r' && s[i - 2] != 'e'
		&& s[i - 3] != 'b' && s[i - 4] != '.')
	{
		write(1, "Name is false", 13);
		exit(0);
	}
}

void	read_map(t_info *map, char *ber_file)
{
	int		fd;
	char	*line;
	char	*result;

	check_ber(ber_file);
	fd = open(ber_file, O_RDONLY);
	if (fd < 0)
		exit(0);
	result = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = ft_strjoin(result, line);
		free(line);
	}
	map->map = ft_split(result, '\n');
	free(result);
	map_length_widht(map);
}
