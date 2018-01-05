/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_check_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:35:07 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/22 11:35:09 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetri(char *buff, t_tetri *tetriminos)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (buff[i] != '\0')
	{
		if ((buff[i] == '\n' && buff[i - 1] == '\n')
			|| (buff[i] == '\n' && buff[i + 1] == '\0'))
			cpt++;
		i++;
	}
	if (cpt == 27)
		return (0);
	else
	{
		tetriminos->count_tetri = cpt;
		return (1);
	}
}

int		ft_check_symbole(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '.' || buff[i] == '#' || buff[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_ligne(char *buff)
{
	int i;
	int x;

	i = 0;
	while (buff[i] != '\0')
	{
		x = 0;
		while (buff[i] != '\n')
		{
			x++;
			i++;
		}
		if (buff[i] == '\n' && buff[i - 1] != '\n' && x != 4)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_col(char *buff)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && buff[i - 1] != '\n')
			y++;
		if ((buff[i + 1] == '\0' && buff[i - 1] == '\n') || (buff[i] == '\n'
			&& buff[i - 1] == '\n' && y != 4) || (buff[i] == '\n'
			&& buff[i + 1] == '\0' && y != 4))
			return (0);
		if (buff[i] == '\n' && buff[i - 1] == '\n' && y == 4)
			y = 0;
		i++;
	}
	return (1);
}

int		ft_check_tetri(char *buff)
{
	int i;
	int j;
	int cpt;

	i = 0;
	while (buff[i] != '\0')
	{
		j = 0;
		cpt = 0;
		while (j < 4)
		{
			if (buff[i] == '#')
				cpt++;
			else if (buff[i] == '\n')
				j++;
			i++;
		}
		if (cpt != 4)
			return (0);
		i++;
	}
	return (1);
}
