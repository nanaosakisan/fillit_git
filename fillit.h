/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:20:47 by arusso            #+#    #+#             */
/*   Updated: 2017/12/16 17:16:38 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ERROR_MSG "usage:  ./fillit name_file\n\t./fillit name_file -g\n"

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_tetri
{
	int					***tab;
	int					count_tetri;
	char				**solution;
	int					y;
	int					x;
	char				c;
}						t_tetri;

int						main(int argc, char **argv);
int						ft_check_all(char *buff, t_tetri *tetriminos);
int						ft_count_tetri(char *buff, t_tetri *tetriminos);
int						ft_check_symbole(char *buff);
int						ft_check_ligne(char *buff);
int						ft_check_col(char *buff);
int						ft_check_tetri(char *buff);
int						ft_error(char *str);
void					ft_free_all(t_tetri *tetriminos, char **buff);
void					ft_init_struct(t_tetri *tetriminos);
void					ft_init_soluc(t_tetri *tetriminos);
void					ft_launch_solveur(t_tetri *tetriminos, char *buff);
void					ft_print_solution(t_tetri *tetriminos);
void					ft_reset_soluc(t_tetri *tetriminos, int *y_tmp,
										int *x_tmp);
t_tetri					*ft_solution(t_tetri *tetriminos);
void					ft_solveur(t_tetri *tetriminos, int *y_tmp, int *x_tmp,
									int *num);
t_tetri					*ft_tetri_tab(char *buff, t_tetri *tetriminos);

#endif
