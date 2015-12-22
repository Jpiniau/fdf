/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:55:10 by jpiniau           #+#    #+#             */
/*   Updated: 2015/12/21 15:48:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	ft_cadre(int x1, int y1, t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y <= 120)
	{
		x = -1;
		while (++x <= 325)
			mlx_pixel_put(e->mlx, e->win, x + x1, y + y1, 0x000000);
	}
}

int			ft_menu(t_env *e)
{
	int		x1;
	int		y1;
	char	*vue;
	char	*echelle;
	char	*menu;

	vue = ft_strdup("vue: iso : i, parallele : p");
	echelle = ft_strdup("\"echelle\" de z: fleche haut/bas");
	menu = ft_strdup("afficher/cacher menu: m");
	x1 = WIN_HEIGHT - 320;
	y1 = WIN_WIDTH - 120;
	ft_cadre(WIN_HEIGHT - 325, WIN_WIDTH - 120, e);
	mlx_string_put(e->mlx, e->win, x1 + 120, y1, 0xffffff, "Menu");
	mlx_string_put(e->mlx, e->win, x1, y1 + 25, 0xffffff, vue);
	mlx_string_put(e->mlx, e->win, x1, y1 + 40, 0xffffff, "mouvement: wasd");
	mlx_string_put(e->mlx, e->win, x1, y1 + 55, 0xffffff, "zoom/dezoom: z/x");
	mlx_string_put(e->mlx, e->win, x1, y1 + 70, 0xffffff, echelle);
	mlx_string_put(e->mlx, e->win, x1, y1 + 85, 0xffffff, "reset: r");
	mlx_string_put(e->mlx, e->win, x1, y1 + 100, 0xffffff, menu);
	return (0);
}
