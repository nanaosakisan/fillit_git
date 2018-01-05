/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 09:41:01 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/26 09:41:04 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_verif_tetri(char **solution, int y_tmp, int x_tmp, int **tab)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(*solution) - 1;
	while (++i < 4)
	{
		if (tab[i][0] + y_tmp < 0 || tab[i][0] + y_tmp >= len
			|| tab[i][1] + x_tmp < 0 || tab[i][1] + x_tmp > len)
			return (0);
		if (solution[tab[i][0] + y_tmp][tab[i][1] + x_tmp] != '.')
			return (0);
	}
	return (1);
}

static void	ft_suppr_tetri(t_tetri *tetriminos, int *y_tmp, int *x_tmp)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tetriminos->y)
	{
		j = -1;
		while (++j < tetriminos->y)
		{
			if (tetriminos->solution[i][j] == tetriminos->c)
			{
				if (*y_tmp == tetriminos->y && *x_tmp == tetriminos->x)
				{
					*y_tmp = i;
					*x_tmp = j + 1;
				}
				tetriminos->solution[i][j] = '.';
			}
		}
	}
}

static void	ft_reset(t_tetri *tetriminos, int *y_tmp, int *x_tmp, int *num)
{
	if (*num == 0)
		ft_reset_soluc(tetriminos, y_tmp, x_tmp);
	else
	{
		ft_suppr_tetri(tetriminos, y_tmp, x_tmp);
		(*num)--;
		if (tetriminos->c != 'A')
			tetriminos->c = tetriminos->c - 1;
	}
}

static void	ft_init_var(int *num, int *y_tmp, int *x_tmp)
{
	*num = 0;
	*y_tmp = 0;
	*x_tmp = 0;
}

t_tetri		*ft_solution(t_tetri *tetriminos)
{
	int	y_tmp;
	int	x_tmp;
	int num;

	ft_init_soluc(tetriminos);
	ft_init_var(&num, &y_tmp, &x_tmp);
	while (num < tetriminos->count_tetri)
	{
		while (y_tmp < tetriminos->y)
		{
			x_tmp = (x_tmp == tetriminos->x) ? 0 : x_tmp;
			while (x_tmp < tetriminos->x)
			{
				if ((ft_verif_tetri(tetriminos->solution, y_tmp, x_tmp,
					tetriminos->tab[num])) == 1)
					ft_solveur(tetriminos, &y_tmp, &x_tmp, &num);
				if (num == tetriminos->count_tetri)
					return (tetriminos);
				x_tmp++;
			}
			y_tmp++;
		}
		ft_reset(tetriminos, &y_tmp, &x_tmp, &num);
	}
	return (tetriminos);
}
