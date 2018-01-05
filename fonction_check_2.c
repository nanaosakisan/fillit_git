/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_check_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:36:45 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/22 11:36:51 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_link(char *tmp)
{
	int i;
	int j;
	int count;
	int test[2];

	i = -1;
	test[0] = 1;
	test[1] = 5;
	count = 0;
	while (tmp[++i] != '\0')
	{
		if (tmp[i] == '#')
		{
			j = 0;
			while (j < 2)
			{
				if (tmp[i + test[j]] == '#')
					count++;
				if (tmp[i - test[j]] == '#')
					count++;
				j++;
			}
		}
	}
	return (count);
}

static int	ft_check_touch(char *buff)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (buff[i] != '\0')
	{
		tmp = ft_strsub(buff, i, 21);
		if (ft_check_link(tmp) < 6)
			return (0);
		else
			i = i + 21;
	}
	ft_memdel((void**)&tmp);
	return (1);
}

int			ft_check_all(char *buff, t_tetri *tetriminos)
{
	if (ft_strlen(buff) == 0 || ft_count_tetri(buff, tetriminos) == 0
		|| ft_check_symbole(buff) == 0 || ft_check_ligne(buff) == 0
		|| ft_check_col(buff) == 0 || ft_check_tetri(buff) == 0
		|| ft_check_touch(buff) == 0)
		return (0);
	else
		return (1);
}
