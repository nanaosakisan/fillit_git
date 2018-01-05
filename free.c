/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:10:06 by iporsenn          #+#    #+#             */
/*   Updated: 2018/01/04 14:10:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error(char *str)
{
	ft_putstr(str);
	return (0);
}

static void	ft_free_parseur(t_tetri *tetriminos)
{
	int num;
	int i;

	num = -1;
	while (++num < tetriminos->count_tetri)
	{
		i = -1;
		while (++i < 4)
		{
			ft_memdel((void**)&(tetriminos->tab[num][i]));
		}
		ft_memdel((void**)&(tetriminos->tab[num]));
	}
	ft_memdel((void**)&(tetriminos->tab));
}

static void	ft_free_solution(t_tetri *tetriminos)
{
	int i;

	i = -1;
	while (++i < tetriminos->y)
	{
		ft_memdel((void**)&(tetriminos->solution[i]));
	}
	ft_memdel((void**)&(tetriminos->solution));
}

void		ft_free_all(t_tetri *tetriminos, char **buff)
{
	ft_free_solution(tetriminos);
	ft_free_parseur(tetriminos);
	ft_memdel((void**)buff);
}

void		ft_reset_soluc(t_tetri *tetriminos, int *y_tmp, int *x_tmp)
{
	ft_free_solution(tetriminos);
	tetriminos->y++;
	tetriminos->x++;
	tetriminos->c = 'A';
	ft_init_soluc(tetriminos);
	*y_tmp = 0;
	*x_tmp = 0;
}
