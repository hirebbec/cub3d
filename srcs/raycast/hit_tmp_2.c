/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tmp_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:57:37 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 17:11:47 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	second_line(t_game *game, t_ray *ray, t_ray *luch)
{
	game->gamma = 1.570796 - atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	game->x_prev = ray->x;
	game->y_prev = ray->y;
	if (game->gamma + (ray->angle * 0.0174) > 1.570796)
	{
		ray->y = floor(game->y_prev + 1.0);
		ray->x = game->x_prev - (fabs(game->y_prev - ray->y) * \
		(tan(3.1415 - game->gamma - (ray->angle * 0.0174))));
		luch->flag = SO;
	}
	else if (game->gamma + (ray->angle * 0.0174) < 0)
	{
		ray->y = ceil(game->y_prev - 1.0);
		ray->x = game->x_prev + (fabs(game->y_prev - ray->y) * \
		(tan(-(ray->angle * 0.0174) - game->gamma)));
		luch->flag = NO;
	}
	else
	{
		ray->y = ceil(game->y_prev - 1.0);
		ray->x = game->x_prev - (fabs(game->y_prev - ray->y) * \
		tan(game->gamma + (ray->angle * 0.0174)));
		luch->flag = NO;
	}
}

void	else_second_line(t_game *game, t_ray *ray, t_ray *luch)
{
	if (game->gamma + (ray->angle * 0.0174) < 0)
	{
		ray->y = ceil(game->y_prev - 1.0);
		ray->x = game->x_prev + (fabs(game->y_prev - ray->y) * \
		(tan(-(ray->angle * 0.0174) - game->gamma)));
		luch->flag = NO;
	}
	else
	{
		ray->y = ceil(game->y_prev - 1.0);
		ray->x = game->x_prev - (fabs(game->y_prev - ray->y) * \
		tan(game->gamma + (ray->angle * 0.0174)));
		luch->flag = NO;
	}
}

void	second_colmn(t_game *game, t_ray *ray, t_ray *luch)
{
	game->gamma = atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	game->x_prev = ray->x;
	game->y_prev = ray->y;
	if (game->gamma - (ray->angle * 0.0174) > 1.570796)
	{
		ray->x = floor(game->x_prev + 1.0);
		ray->y = game->y_prev - (fabs(game->x_prev - ray->x) * \
		tan(3.1415 - game->gamma + (ray->angle * 0.0174)));
		luch->flag = EA;
	}
	else if (game->gamma - (ray->angle * 0.0174) < 0)
	{
		ray->x = ceil(game->x_prev - 1.0);
		ray->y = game->y_prev + (fabs(game->x_prev - ray->x) * \
		tan((ray->angle * 0.0174) - game->gamma));
		luch->flag = WE;
	}
	else
	{
		ray->x = ceil(game->x_prev - 1.0);
		ray->y = game->y_prev - (fabs(game->x_prev - ray->x) * \
		tan((game->gamma - (ray->angle * 0.0174))));
		luch->flag = WE;
	}
}

void	else_second_colmn(t_game *game, t_ray *ray, t_ray *luch)
{
	if (game->gamma - (ray->angle * 0.0174) < 0)
	{
		ray->x = ceil(game->x_prev - 1.0);
		ray->y = game->y_prev + (fabs(game->x_prev - ray->x) * \
		tan((ray->angle * 0.0174) - game->gamma));
		luch->flag = WE;
	}
	else
	{
		ray->x = ceil(game->x_prev - 1.0);
		ray->y = game->y_prev - (fabs(game->x_prev - ray->x) * \
		tan((game->gamma - (ray->angle * 0.0174))));
		luch->flag = WE;
	}
}
