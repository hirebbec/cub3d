/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tmp_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:53:11 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 18:01:06 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	fourth_line(t_game *game, t_ray *ray, t_ray *luch)
{
	game->gamma = 1.570796 - atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	game->x_prev = ray->x;
	game->y_prev = ray->y;
	if (game->gamma + (ray->angle * 0.0174) > 1.570796)
	{
		ray->y = ceil(game->y_prev - 1.0);
		ray->x = game->x_prev + (fabs(game->y_prev - ray->y) * \
		(tan(3.1415 - game->gamma - (ray->angle * 0.0174))));
		luch->flag = NO;
	}
	else if (game->gamma + (ray->angle * 0.0174) < 0)
	{
		ray->y = floor(game->y_prev + 1.0);
		ray->x = game->x_prev - (fabs(game->y_prev - ray->y) * \
		(tan(-(ray->angle * 0.0174) - game->gamma)));
		luch->flag = SO;
	}
	else
	{
		ray->y = floor(game->y_prev + 1.0);
		ray->x = game->x_prev + (fabs(game->y_prev - ray->y) * \
		tan(game->gamma + (ray->angle * 0.0174)));
		luch->flag = SO;
	}
}

void	else_fourth_line(t_game *game, t_ray *ray, t_ray *luch)
{
	if (game->gamma + (ray->angle * 0.0174) < 0)
	{
		ray->y = floor(game->y_prev + 1.0);
		ray->x = game->x_prev - (fabs(game->y_prev - ray->y) * \
		(tan(-(ray->angle * 0.0174) - game->gamma)));
		luch->flag = SO;
	}
	else
	{
		ray->y = floor(game->y_prev + 1.0);
		ray->x = game->x_prev + (fabs(game->y_prev - ray->y) \
		* tan(game->gamma + (ray->angle * 0.0174)));
		luch->flag = SO;
	}
}

void	fourth_colmn(t_game *game, t_ray *ray, t_ray *luch)
{
	game->gamma = atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	game->x_prev = ray->x;
	game->y_prev = ray->y;
	if (game->gamma - (ray->angle * 0.0174) > 1.570796)
	{
		ray->x = ceil(game->x_prev - 1.0);
		ray->y = game->y_prev + (fabs(game->x_prev - ray->x) * \
		tan((3.1415 + (ray->angle * 0.0174) - game->gamma)));
		luch->flag = WE;
	}
	else if (game->gamma - (ray->angle * 0.0174) < 0)
	{
		ray->x = floor(game->x_prev + 1.0);
		ray->y = game->y_prev - (fabs(game->x_prev - ray->x) * \
		tan((ray->angle * 0.0174) - game->gamma));
		luch->flag = EA;
	}
	else
	{
		ray->x = floor(game->x_prev + 1.0);
		ray->y = game->y_prev + (fabs(game->x_prev - ray->x) * \
		tan((game->gamma - (ray->angle * 0.0174))));
		luch->flag = EA;
	}
}

void	else_fourth_colmn(t_game *game, t_ray *ray, t_ray *luch)
{
	if (game->gamma - (ray->angle * 0.0174) < 0)
	{
		ray->x = floor(game->x_prev + 1.0);
		ray->y = game->y_prev - (fabs(game->x_prev - ray->x) * \
		tan((ray->angle * 0.0174) - game->gamma));
		luch->flag = EA;
	}
	else
	{
		ray->x = floor(game->x_prev + 1.0);
		ray->y = game->y_prev + (fabs(game->x_prev - ray->x) * \
		tan((game->gamma - (ray->angle * 0.0174))));
		luch->flag = EA;
	}
}
