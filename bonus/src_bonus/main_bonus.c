/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:25:47 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/29 01:16:38 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_materials(t_info *map)
{
	if ((map->img->exit_chk == !1) || (map->img->eggadd == 0)
		|| (map->p_chk != 1))
	{
		write(1, "Error: wrong map argument\n", 26);
		exit_game(map, 2);
	}
}

int	end(t_info *end)
{
	int	i;

	i = 0;
	if (end->finish == 1)
	{
		while (i++ < 50000)
			;
		exit_game(end, 0);
	}
	return (0);
}

void	print_screen(t_info *data)
{
	char	*s;

	s = ft_itoa(data->img->eggadd);
	mlx_string_put(data->mlx, data->mlx_window, 5, 14, 0xEB3B3B, "EGG");
	mlx_string_put(data->mlx, data->mlx_window, 5, 25, 0xEB3B3B, s);
	free(s);
	s = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->mlx_window, 5, 35, 0xEB3B3B, "STEP");
	mlx_string_put(data->mlx, data->mlx_window, 5, 46, 0xEB3B3B, s);
	free(s);
}

int	xbutton(t_info *data)
{
	exit_game(data, 0);
	return (0);
}

int	main(int argc, char**argv)
{
	t_info	*data;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	xpm_control();
	xpm_control_two();
	data = (t_info *)ft_calloc(sizeof(t_info), 1);
	read_map(data, argv[1]);
	data->mlx = mlx_init();
	data->img = mlx_new_image(data->mlx, 64, 64);
	data->mlx_window = mlx_new_window
		(data->mlx, data->line_width * 64, data->line_height * 64, "so_long");
	for_image(data);
	take_image(data);
	check_materials(data);
	mlx_loop_hook(data->mlx, end, data);
	mlx_hook(data->mlx_window, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_window, 17, 0, xbutton, data);
	mlx_loop(data->mlx);
}
