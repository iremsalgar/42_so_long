/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 03:46:42 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/28 22:17:07 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_info *map, int d)
{
	int	i;

	i = 0;
	if (d == 2 || d == 3)
		write(1, "error\n", 6);
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	if (d == 3)
		destroy_image(map);
	if (map->img)
		free(map->img);
	free(map);
	system("leaks so_long_bonus");
	exit(0);
}

void	destroy_image(t_info *map)
{
	if (map->img->player_s)
		mlx_destroy_image(map->mlx, map->img->player_s);
	if (map->img->player_w)
		mlx_destroy_image(map->mlx, map->img->player_w);
	if (map->img->player_a)
		mlx_destroy_image(map->mlx, map->img->player_a);
	if (map->img->player_d)
		mlx_destroy_image(map->mlx, map->img->player_d);
	if (map->img->wall)
		mlx_destroy_image(map->mlx, map->img->wall);
	if (map->img->background)
		mlx_destroy_image(map->mlx, map->img->background);
	if (map->img->egg)
		mlx_destroy_image(map->mlx, map->img->egg);
	if (map->img->exit)
		mlx_destroy_image(map->mlx, map->img->exit);
}
