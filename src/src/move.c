/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:13:00 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/23 02:49:36 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	char_move_left(t_info *move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y;
	if (move->map[y][x - 1] == '0' || move->map[y][x - 1] == 'C')
	{
		if (move->map[y][x - 1] == 'C')
			move->img->eggadd--;
		update_direction(KEY_A, move);
		move->map[y][x] = '0';
		move->map[y][x - 1] = 'P';
		mlx_clear_window(move->mlx, move->mlx_window);
		map_update(move);
		put_image(move, move->img->background, x - 1, y);
		put_image(move, move->img->player_a, x - 1, y);
		move->move++;
		move->p_x--;
	}
	if (move->map[y][x - 1] == 'E' && move->img->eggadd == 0)
		return (move->move++);
	return (0);
}

int	char_move_right(t_info *move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y;
	if (move->map[y][x + 1] == '0' || move->map[y][x + 1] == 'C')
	{
		if (move->map[y][x + 1] == 'C')
			move->img->eggadd--;
		update_direction(KEY_D, move);
		move->map[y][x] = '0';
		move->map[y][x + 1] = 'P';
		mlx_clear_window(move->mlx, move->mlx_window);
		map_update(move);
		put_image(move, move->img->background, x + 1, y);
		put_image(move, move->img->player_d, x + 1, y);
		move->move++;
		move->p_x++;
	}
	if (move->map[y][x + 1] == 'E' && move->img->eggadd == 0)
		return (move->move++);
	return (0);
}

int	char_move_down(t_info *move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y;
	if (move->map[y + 1][x] == '0' || move->map[y + 1][x] == 'C')
	{
		if (move->map[y + 1][x] == 'C')
			move->img->eggadd--;
		update_direction(KEY_S, move);
		move->map[y][x] = '0';
		move->map[y + 1][x] = 'P';
		mlx_clear_window(move->mlx, move->mlx_window);
		map_update(move);
		put_image(move, move->img->background, x, y + 1);
		put_image(move, move->img->player_s, x, y + 1);
		move->move++;
		move->p_y++;
	}
	if (move->map[y + 1][x] == 'E' && move->img->eggadd == 0)
		return (move->move++);
	return (0);
}

int	char_move_top(t_info *move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y ;
	if (move->map[y - 1][x] == '0' || move->map[y - 1][x] == 'C')
	{
		if (move->map[y -1][x] == 'C')
			move->img->eggadd--;
		update_direction(KEY_W, move);
		move->map[y][x] = '0';
		move->map[y - 1][x] = 'P';
		mlx_clear_window(move->mlx, move->mlx_window);
		map_update(move);
		put_image(move, move->img->background, x, y - 1);
		put_image(move, move->img->player_w, x, y - 1);
		move->move++;
		move->p_y--;
	}
	if (move->map[y - 1][x] == 'E' && move->img->eggadd == 0)
		return (move->move++);
	return (0);
}
