/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:16:41 by iporsenn          #+#    #+#             */
/*   Updated: 2017/12/16 15:16:43 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		*buff;
	t_tetri		tetriminos;

	fd = 0;
	buff = ft_strnew(567);
	ft_init_struct(&tetriminos);
	if (argc != 2)
		return (ft_error("usage: ./fillit name_file\n"));
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error("open() failed\n"));
		read(fd, buff, 567);
		if (ft_check_all(buff, &tetriminos) == 1)
			ft_launch_solveur(&tetriminos, buff);
		else
			return (ft_error("error"));
		if ((close(fd)) == -1)
			return (ft_error("close() failed\n"));
	}
	ft_free_all(&tetriminos, &buff);
	return (0);
}
