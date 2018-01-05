/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:13:48 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/16 15:13:52 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	***init_tab(t_tetri *tetriminos)
{
	int ***tab;
	int i;
	int j;

	tab = NULL;
	if (!(tab = (int***)ft_memalloc(sizeof(int**) * tetriminos->count_tetri)))
		return (NULL);
	i = -1;
	while (++i < tetriminos->count_tetri)
	{
		if (!(tab[i] = (int**)ft_memalloc(sizeof(int*) * 4)))
			return (NULL);
		j = -1;
		while (++j < 4)
			if (!(tab[i][j] = (int*)ft_memalloc(sizeof(int*) * 2)))
				return (NULL);
	}
	return (tab);
}

static char	*ft_fill_tab(char *buff, int i, int ***tab, int nb)
{
	int x;
	int y;
	int count;

	y = -1;
	count = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (buff[i] == '#')
			{
				tab[nb][count][0] = y;
				tab[nb][count][1] = x;
				count++;
			}
			i++;
		}
		i++;
	}
	return (buff + i + 1);
}

static int	***ft_replace_tetri(int ***tab, int nb)
{
	int count;
	int y;
	int x;
	int diff_y;
	int diff_x;

	y = tab[nb][0][0];
	x = tab[nb][0][1];
	count = -1;
	while (++count < 4)
	{
		diff_y = tab[nb][count][0] - y;
		diff_x = tab[nb][count][1] - x;
		tab[nb][count][0] = diff_y;
		tab[nb][count][1] = diff_x;
	}
	return (tab);
}

t_tetri		*ft_tetri_tab(char *buff, t_tetri *tetriminos)
{
	int ***tab;
	int nb;
	int i;

	tab = NULL;
	tab = init_tab(tetriminos);
	nb = 0;
	i = -1;
	while (buff[++i] != '\0')
	{
		buff = ft_fill_tab(buff, 0, tab, nb);
		nb++;
	}
	nb = -1;
	while (++nb < tetriminos->count_tetri)
		tab = ft_replace_tetri(tab, nb);
	tetriminos->tab = tab;
	return (tetriminos);
}
