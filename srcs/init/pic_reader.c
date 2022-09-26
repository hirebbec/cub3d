/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:45:34 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 18:47:58 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	pic_ea_init(char *line, t_game *game)
{
	char	**temp;
	char	*temp1;
	char	*temp2;

	temp = ft_split(line, ' ');
	temp1 = ft_strtrim(temp[1], "\n");
	temp2 = ft_strtrim(temp1, "\t");
	game->pic.ea_path = ft_strdup(temp2);
	free(temp1);
	free(temp2);
	ft_free(temp);
}

static void	pic_we_init(char *line, t_game *game)
{
	char	**temp;
	char	*temp1;
	char	*temp2;

	temp = ft_split(line, ' ');
	temp1 = ft_strtrim(temp[1], "\n");
	temp2 = ft_strtrim(temp1, "\t");
	game->pic.we_path = ft_strdup(temp2);
	free(temp2);
	free(temp1);
	ft_free(temp);
}

static void	pic_no_init(char *line, t_game *game)
{
	char	**temp;
	char	*temp1;
	char	*temp2;

	temp = ft_split(line, ' ');
	temp1 = ft_strtrim(temp[1], "\n");
	temp2 = ft_strtrim(temp1, "\t");
	game->pic.no_path = ft_strdup(temp2);
	free(temp2);
	free(temp1);
	ft_free(temp);
}

static void	pic_so_init(char *line, t_game *game)
{
	char	**temp;
	char	*temp1;
	char	*temp2;

	temp = ft_split(line, ' ');
	temp1 = ft_strtrim(temp[1], "\n");
	temp2 = ft_strtrim(temp1, "\t");
	game->pic.so_path = ft_strdup(temp2);
	free(temp2);
	free(temp1);
	ft_free(temp);
}

void	pic_reader(char *line, t_game *game)
{
	if (ft_strnstr(line, "EA ", ft_strlen(line)))
	{
		game->pic.ea_duplicate_flag++;
		pic_ea_init(line, game);
	}
	else if (ft_strnstr(line, "NO ", ft_strlen(line)))
	{
		game->pic.no_duplicate_flag++;
		pic_no_init(line, game);
	}
	else if (ft_strnstr(line, "SO ", ft_strlen(line)))
	{
		game->pic.so_duplicate_flag++;
		pic_so_init(line, game);
	}
	else if (ft_strnstr(line, "WE ", ft_strlen(line)))
	{
		game->pic.we_duplicate_flag++;
		pic_we_init(line, game);
	}
}
