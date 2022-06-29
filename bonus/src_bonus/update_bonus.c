/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:58:33 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/28 21:44:56 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	map_update_p(t_info *game)
{
	int	x;
	int	y;

	x = game->x_pos;
	y = game->y_pos;
	if (game->player_direction == 'w')
		put_image(game, game->img->player_w, x, y);
	else if (game->player_direction == 'a')
		put_image(game, game->img->player_a, x, y);
	else if (game->player_direction == 's')
		put_image(game, game->img->player_s, x, y);
	else if (game->player_direction == 'd')
		put_image(game, game->img->player_d, x, y);
	game->x_pos = x;
	game->y_pos = y;
}

void	update_direction(int player_direction, t_info *move)
{
	if (player_direction == KEY_W)
		move->player_direction = 'w';
	else if (player_direction == KEY_A)
		move->player_direction = 'a';
	else if (player_direction == KEY_S)
		move->player_direction = 's';
	else if (player_direction == KEY_D)
		move->player_direction = 'd';
	else
		return ;
}

void	map_update(t_info *new_map)
{
	int	y;

	y = 0;
	while (y < new_map->line_height)
	{
		map_and_put_bridge(new_map, 0, y);
		y++;
	}
}

void	map_and_put_bridge(t_info *new_map, int x, int y)
{
	while (x < new_map->line_width)
	{
		if (new_map->map[y][x] == '0')
			put_image(new_map, new_map->img->background, x, y);
		else if (new_map->map[y][x] == '1')
		{
			put_image(new_map, new_map->img->background, x, y);
			put_image(new_map, new_map->img->wall, x, y);
		}
		else if (new_map->map[y][x] == 'E')
		{
			put_image(new_map, new_map->img->background, x, y);
			put_image(new_map, new_map->img->exit, x, y);
		}
		else if (new_map->map[y][x] == 'C')
		{
			put_image(new_map, new_map->img->background, x, y);
			put_image(new_map, new_map->img->egg, x, y);
		}
		x++;
	}
}

int	key_press(int keycode, t_info *data)
{
	int		d;

	d = 0;
	if (keycode == KEY_W)
		d = char_move_top(data);
	if (keycode == KEY_A)
		d = char_move_left(data);
	if (keycode == KEY_S)
		d = char_move_down(data);
	if (keycode == KEY_D)
		d = char_move_right(data);
	if (keycode == 53)
		exit_game(data, 0);
	print_screen(data);
	map_update_p(data);
	if (d)
		exit_game(data, 0);
	return (keycode);
}
