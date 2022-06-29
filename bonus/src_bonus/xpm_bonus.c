/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:20:13 by isalgar           #+#    #+#             */
/*   Updated: 2022/06/29 01:17:37 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_control(void)
{
	int	fd_back;
	int	fd_sea;
	int	fd_wall;
	int	fd_egg;

	fd_back = open("./bonus/image/back.xpm", O_RDWR);
	fd_sea = open("./bonus/image/sea.xpm", O_RDWR);
	fd_wall = open("./bonus/image/wall.xpm", O_RDWR);
	fd_egg = open("./bonus/image/egg.xpm", O_RDWR);
	if (fd_back <= 0 || fd_sea <= 0 || fd_wall <= 0 || fd_egg <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(fd_back);
		close(fd_sea);
		close(fd_wall);
		close(fd_egg);
		exit(1);
	}
	close(fd_back);
	close(fd_sea);
	close(fd_wall);
	close(fd_egg);
}

void	xpm_control_two(void)
{
	int	fd_exit;
	int	fd_front;
	int	fd_left;
	int	fd_right;

	fd_exit = open("./bonus/image/exit.xpm", O_RDWR);
	fd_front = open("./bonus/image/front.xpm", O_RDWR);
	fd_left = open("./bonus/image/left.xpm", O_RDWR);
	fd_right = open("./bonus/image/right.xpm", O_RDWR);
	if (fd_exit <= 0 || fd_front <= 0 || fd_left <= 0 || fd_right <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(fd_exit);
		close(fd_front);
		close(fd_left);
		close(fd_right);
		exit(1);
	}
	close(fd_exit);
	close(fd_front);
	close(fd_left);
	close(fd_right);
}
