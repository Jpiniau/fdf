/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 14:58:01 by jpiniau           #+#    #+#             */
/*   Updated: 2015/12/22 15:31:32 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	check_tmp(char *tmp)
{
	char	*tmp2;
	int		i;

	tmp2 = tmp;
	if (tmp == NULL)
		return (1);
	if (ft_strlen(tmp) <= 1)
		return (1);
	i = 0;
	while (*tmp)
	{
		if (ft_isdigit(*tmp))
			i++;
		tmp++;
	}
	if (i <= 1)
		return (1);
	tmp = tmp2;
	while (*tmp)
	{
		if (ft_isalpha(*tmp))
			return (1);
		tmp++;
	}
	return (0);
}

int	check_matrix(char *tmp_mat, int nb_line, t_env *e)
{
	char	**tmp;
	char	**matrix;
	int		y;
	int		x;
	size_t	tmpw;

	if (check_tmp(tmp_mat))
		return (1);
	matrix = ft_strsplit(tmp_mat, '\n');
	y = -1;
	e->size_mat.height = 0;
	while (++y < nb_line)
	{
		e->size_mat.height++;
		e->size_mat.width = 0;
		x = -1;
		tmp = ft_strsplit(matrix[y], ' ');
		while (tmp[++x])
			e->size_mat.width++;
		if (y >= 1)
			if (tmpw != e->size_mat.width)
				return (1);
		tmpw = e->size_mat.width;
	}
	return (0);
}
