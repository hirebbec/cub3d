/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:40:57 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 17:09:22 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	else_second_line(t_game *game, t_ray *ray, t_ray *luch);
void	else_second_colmn(t_game *game, t_ray *ray, t_ray *luch);

int	hit_c_second(double x, double y, t_game *game, double angle)
{
	int	x_;
	int	y_;

	if (x < 0.0)
		x = 0.0;
	if (y < 0.0)
		y = 0.0;
	if (x > game->map_width - 1)
		x = game->map_width - 1;
	if (y > game->map_height - 1)
		y = game->map_height - 1;
	if (angle > 1.57079)
		x_ = (int)floor(x);
	else
		x_ = (int)floor(x) - 1;
	y_ = (int)floor(y);
	if (game->map[y_][x_] == '1')
		return (1);
	return (0);
}

int	hit_l_second(double x, double y, t_game *game, double angle)
{
	int	x_;
	int	y_;

	if (x < 0.0)
		x = 0.0;
	if (y < 0.0)
		y = 0.0;
	if (x > game->map_width - 1)
		x = game->map_width - 1;
	if (y > game->map_height - 1)
		y = game->map_height - 1;
	x_ = (int)floor(x);
	if (angle > 1.57079)
		y_ = (int)ceil(y);
	else
		y_ = (int)ceil(y) - 1;
	if (game->map[y_][x_] == '1')
		return (1);
	return (0);
}

double	h_l_s(t_ray ray, t_game *game, t_ray *luch)
{
	second_line(game, &ray, luch);
	while (!hit_l_second(ray.x, ray.y, game, game->gamma + \
	(ray.angle * 0.0174)))
	{
		game->x_prev = ray.x;
		game->y_prev = ray.y;
		if (game->gamma + (ray.angle * 0.0174) > 1.570796)
		{
			ray.y = floor(game->y_prev + 1.0);
			ray.x = game->x_prev - (fabs(game->y_prev - ray.y) * \
			(tan(3.1415 - game->gamma - (ray.angle * 0.0174))));
			luch->flag = SO;
		}
		else
			else_second_line(game, &ray, luch);
	}
	luch->x_hit = ray.x;
	luch->y_hit = ray.y;
	return (pifogor(fabs(game->player.x - ray.x), fabs(game->player.y - ray.y), \
	game) * cos(fabs(ray.angle) * 0.0174));
}

double	h_c_s(t_ray ray, t_game *game, t_ray *luch)
{
	second_colmn(game, &ray, luch);
	while (!hit_c_second(ray.x, ray.y, game, game->gamma - \
	(ray.angle * 0.0174)))
	{
		game->x_prev = ray.x;
		game->y_prev = ray.y;
		if (game->gamma - (ray.angle * 0.0174) > 1.570796)
		{
			ray.x = floor(game->x_prev + 1.0);
			ray.y = game->y_prev - (fabs(game->x_prev - ray.x) * \
			tan(3.1415 - game->gamma + (ray.angle * 0.0174)));
			luch->flag = EA;
		}
		else
			else_second_colmn(game, &ray, luch);
	}
	luch->x_hit = ray.x;
	luch->y_hit = ray.y;
	return (pifogor(fabs(game->player.x - ray.x), fabs(game->player.y - ray.y), \
	game) * cos(fabs(ray.angle) * 0.0174));
}
