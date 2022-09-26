/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:06:47 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 19:22:07 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	color_struct_zero(t_game *game)
{
	game->color.f_col_r = 0;
	game->color.f_col_g = 0;
	game->color.f_col_b = 0;
	game->color.c_col_r = 0;
	game->color.c_col_g = 0;
	game->color.c_col_b = 0;
	game->color.duplicate_flag_f = 0;
	game->color.duplicate_flag_c = 0;
	game->pic.ea_duplicate_flag = 0;
	game->pic.we_duplicate_flag = 0;
	game->pic.no_duplicate_flag = 0;
	game->pic.so_duplicate_flag = 0;
	game->map_flag = 0;
	game->map_already_init_flag = 0;
}

void	ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	add_char(char **line, char c)
{
	int		len;
	char	*tmp;
	char	*result;

	if (*line == NULL)
		len = 0;
	else
		len = ft_strlen(*line);
	result = malloc(sizeof(char) * (len + 2));
	if (!result)
		return ;
	ft_memcpy(result, *line, len);
	result[len] = c;
	result[len + 1] = '\0';
	tmp = *line;
	(*line) = result;
	free(tmp);
}

void	extern1(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if ((int)ft_strlen(game->map[i]) < game->map_width)
		{
			while ((int)ft_strlen(game->map[i]) != game->map_width)
				add_char(&game->map[i], '1');
		}
		i++;
	}
}
