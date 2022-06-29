/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:53:22 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/21 01:13:34 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	put_image(t_info *img, void *img_type, int x, int y)
{
	mlx_put_image_to_window
		(img->mlx, img->mlx_window, img_type, x * 64, y * 64);
}

void	for_image(t_info *img)
{
	img->img = ft_calloc(sizeof(t_info), 1);
	img->img->wall = mlx_xpm_file_to_image
		(img->mlx, WALL, &img->x_pos, &img->y_pos);
	img->img->background = mlx_xpm_file_to_image
		(img->mlx, BACKGROUND, &img->x_pos, &img->y_pos);
	img->img->player_w = mlx_xpm_file_to_image
		(img->mlx, PLAYER_W, &img->x_pos, &img->y_pos);
	img->img->player_s = mlx_xpm_file_to_image
		(img->mlx, PLAYER_S, &img->x_pos, &img->y_pos);
	img->img->player_a = mlx_xpm_file_to_image
		(img->mlx, PLAYER_A, &img->x_pos, &img->y_pos);
	img->img->player_d = mlx_xpm_file_to_image
		(img->mlx, PLAYER_D, &img->x_pos, &img->y_pos);
	img->img->egg = mlx_xpm_file_to_image
		(img->mlx, EGG, &img->x_pos, &img->y_pos);
	img->img->exit = mlx_xpm_file_to_image
		(img->mlx, EXIT, &img->x_pos, &img->y_pos);
}

int	take_image(t_info *info_img)
{
	int	y;
	int	x;

	y = 0;
	while (y < info_img->line_height)
	{
		x = 0;
		while (x < info_img->line_width)
		{	
			if (info_img->map[y][x] == '0')
				put_image(info_img, info_img->img->background, x, y);
			take_and_put_bridge(info_img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	take_and_put_bridge(t_info *info_img, int x, int y)
{
	if (info_img->map[y][x] == 'P')
	{
		put_image(info_img, info_img->img->background, x, y);
		put_image(info_img, info_img->img->player_s, x, y);
		info_img->p_x = x;
		info_img->p_y = y;
		info_img->p_chk++;
	}
	else if (info_img->map[y][x] == '1')
	{
		put_image(info_img, info_img->img->background, x, y);
		put_image(info_img, info_img->img->wall, x, y);
	}
	else if (info_img->map[y][x] == 'E')
	{
		put_image(info_img, info_img->img->background, x, y);
		put_image(info_img, info_img->img->exit, x, y);
		info_img->img->exit_chk++;
	}
	else if (info_img->map[y][x] == 'C')
	{
		put_image(info_img, info_img->img->background, x, y);
		put_image(info_img, info_img->img->egg, x, y);
		info_img->img->eggadd++;
	}
}

void	detect_component(t_info *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < map->line_height)
	{
		while (x < map->line_width)
		{
			if (map->map[y][x] == 'P')
			{
				map->p_chk += 1;
				map->x_pos = x;
				map->y_pos = y;
			}
			x++;
		}
		y++;
	}
}
