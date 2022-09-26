/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:09:24 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 18:05:40 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pic_name_checker(t_game *game);

static void	pic_ea(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Wrong EA image path", 2);
		exit(1);
	}
	close(fd);
}

static void	pic_we(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Wrong WE image path", 2);
		exit(1);
	}
	close(fd);
}

static void	pic_so(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Wrong SO image path", 2);
		exit(1);
	}
	close(fd);
}

static void	pic_no(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Wrong NO image path", 2);
		exit(1);
	}
	close(fd);
}

void	pic_validate(t_game *game)
{
	if (game->pic.ea_duplicate_flag > 1)
	{
		ft_putendl_fd("Duplicate error", 2);
		exit(1);
	}
	if (game->pic.we_duplicate_flag > 1)
	{
		ft_putendl_fd("Duplicate error", 2);
		exit(1);
	}
	if (game->pic.so_duplicate_flag > 1)
	{
		ft_putendl_fd("Duplicate error", 2);
		exit(1);
	}
	if (game->pic.no_duplicate_flag > 1)
	{
		ft_putendl_fd("Duplicate error", 2);
		exit(1);
	}
	pic_ea(game->pic.ea_path);
	pic_we(game->pic.we_path);
	pic_so(game->pic.so_path);
	pic_no(game->pic.no_path);
	pic_name_checker(game);
}
