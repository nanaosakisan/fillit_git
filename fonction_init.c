/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:58:13 by iporsenn          #+#    #+#             */
/*   Updated: 2018/01/04 15:58:14 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_struct(t_tetri *tetriminos)
{
	tetriminos->tab = NULL;
	tetriminos->count_tetri = 0;
	tetriminos->solution = NULL;
	tetriminos->y = 2;
	tetriminos->x = 3;
	tetriminos->c = 'A';
}

void		ft_fill_soluc(t_tetri *tetriminos)
{
	int i;
	int j;

	i = 0;
	while (i < tetriminos->y)
	{
		j = -1;
		while (++j < tetriminos->y)
			tetriminos->solution[i][j] = '.';
		tetriminos->solution[i][j] = '\n';
		i++;
	}
}

void		ft_init_soluc(t_tetri *tetriminos)
{
	int i;

	i = -1;
	if (!(tetriminos->solution = (char **)ft_memalloc(sizeof(char*)
		* tetriminos->y)))
		return ;
	while (++i < tetriminos->y)
	{
		if (!(tetriminos->solution[i] = ft_strnew(tetriminos->x)))
			return ;
	}
	ft_fill_soluc(tetriminos);
}
