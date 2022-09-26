/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:45:00 by naqua             #+#    #+#             */
/*   Updated: 2022/08/18 19:27:12 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	color_f_pos_checker(char *path);
void	pic_name_checker(t_game *game);
void	color_struct_zero(t_game *game);
void	color_ceil_floor_init(t_game *game);

static void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
			|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				game->player.player_type = game->map[i][j];
				game->player.x = (double)j + 0.5;
				game->player.y = (double)i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	camera_pos(t_game *game)
{
	if (game->player.player_type == 'N')
	{
		game->camera.y = game->player.y - 0.1;
		game->camera.x = game->player.x;
	}
	else if (game->player.player_type == 'S')
	{
		game->camera.y = game->player.y + 0.1;
		game->camera.x = game->player.x;
	}
	else if (game->player.player_type == 'W')
	{
		game->camera.x = game->player.x - 0.1;
		game->camera.y = game->player.y;
	}
	else if (game->player.player_type == 'E')
	{
		game->camera.x = game->player.x + 0.1;
		game->camera.y = game->player.y;
	}
}

void	camera_player_pos(t_game *game)
{
	player_pos(game);
	camera_pos(game);
}

static void	color_checker(t_game *game, char **argv)
{
	if (game->color.duplicate_flag_f > 1 || game->color.duplicate_flag_c > 1)
	{
		ft_putendl_fd("Duplicate error", 2);
		exit(1);
	}
	if (game->color.duplicate_flag_c < 1 || game->color.duplicate_flag_f < 1)
	{
		ft_putendl_fd("Floor or ceil color missing", 2);
		exit(1);
	}
	if ((game->color.c_col_r > 255 && game->color.c_col_r < 0)
		|| (game->color.c_col_g > 255 || game->color.c_col_g < 0)
		|| (game->color.c_col_b > 255 || game->color.c_col_b < 0)
		|| (game->color.f_col_r > 255 || game->color.f_col_r < 0)
		|| (game->color.f_col_g > 255 || game->color.f_col_b < 0)
		|| (game->color.f_col_b > 255 || game->color.f_col_b < 0))
	{
		ft_putendl_fd("RGB error [0; 255]", 2);
		exit(1);
	}
	color_f_pos_checker(argv[1]);
}

void	init(int argc, char **argv, t_game *game)
{
	ft_argc_num_checker(argc);
	ft_argv_checker(argv[1]);
	color_struct_zero(game);
	map_reader(argv[1], game, 0, ft_strdup(""));
	color_reader(argv[1], game);
	color_ceil_floor_init(game);
	color_checker(game, argv);
	map_validate(game->map, game);
	camera_player_pos(game);
	map_size(game);
	extern1(game);
	pic_validate(game);
	set_imgages(game);
	game->rays = malloc(sizeof(t_ray) * 1920);
}
