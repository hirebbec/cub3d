/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:22:22 by hirebbec          #+#    #+#             */
/*   Updated: 2022/07/12 17:29:14 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	ft_argc_num_checker(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nWrong number of arguments", 2);
		exit(1);
	}
}

void	ft_argv_checker(char *argv)
{
	int	len;
	int	fd;

	len = 0;
	while (argv[len])
		len++;
	if (argv[len - 1] != 'b' || argv[len - 2] != 'u' || argv[len - 3] != 'c'
		|| argv[len - 4] != '.')
	{
		ft_putendl_fd("Error\nWrong file", 2);
		exit(1);
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nCannot read file or file does not exist", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	init(argc, argv, &game);
	raycast(&game);
}
