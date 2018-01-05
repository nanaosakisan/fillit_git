/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:29:24 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/28 11:29:26 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_launch_solveur(t_tetri *tetriminos, char *buff)
{
	ft_tetri_tab(buff, tetriminos);
	ft_print_solution(ft_solution(tetriminos));
}

void		ft_print_solution(t_tetri *tetriminos)
{
	int i;

	i = -1;
	while (++i < tetriminos->y)
		ft_putstr(tetriminos->solution[i]);
}

static void	ft_found_letter(char **solution, t_tetri *tetriminos)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetriminos->y)
	{
		j = -1;
		while (++j < tetriminos->y)
		{
			if (solution[i][j] == tetriminos->c)
				tetriminos->c++;
		}
		i++;
	}
}

static void	ft_place_tetri(int y_tmp, int x_tmp, int **tab, t_tetri *tetrimin)
{
	int	i;

	i = -1;
	ft_found_letter(tetrimin->solution, tetrimin);
	while (++i < 4)
		tetrimin->solution[tab[i][0] + y_tmp][tab[i][1] + x_tmp] = tetrimin->c;
}

void		ft_solveur(t_tetri *tetriminos, int *y_tmp, int *x_tmp, int *num)
{
	ft_place_tetri(*y_tmp, *x_tmp, tetriminos->tab[*num], tetriminos);
	*y_tmp = 0;
	*x_tmp = -1;
	(*num)++;
}
