/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:45 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/29 15:49:15 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_lst
{
	long long		content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_ilist
{
	struct s_lst	*lst;
	int				isa;
	int				j;
	int				imax;
	int				imin;
}	t_ilist;

long long	ft_atoilong(char *str, long long *ar);

t_lst		*ft_lst(long long *ar, int size);

void		ft_swap(t_lst **list, int isa, int ischeck);

void		ft_rotate(t_lst **list, int isa, int ischeck);

void		ft_lst_of_ilst_clear(t_lst **list);

void		ft_revrotate(t_lst **list, int isa, int ischeck);

void		ft_push(t_ilist *to, t_ilist *from, int ischeck);

t_ilist		*ft_ilst(t_lst *pList, int isa, int j);

void		ft_push_swap(t_ilist **lsta, t_ilist **lstb, long long *ar);

void		ft_free(
				long long int *ar, t_lst *pList, t_ilist **lsta,
				t_ilist **lstb);

int			ft_isthree_lsts(t_lst *lst);

int			ft_sortthreea(t_ilist *lsta, long long *ar, t_ilist **lstb, int jb);

void		ft_rr_or_rotate(
				t_ilist *lsta, t_ilist *lstb, int isa, long long *ar);

t_ilist		**ft_grouped_lst(
				t_lst *pList, int argc, long long *ar, t_ilist **ilsts);

int			ft_sort(long long *ar, int size);

void		ft_free_checker(
				long long *ar, t_lst *pList, t_ilist *lsta, t_ilist *lstb);

void		ft_rrevrotate(t_ilist *lsta, t_ilist *lstb, int ischeck);

void		ft_rrotate(t_ilist *lsta, t_ilist *lstb, int ischeck);

void		ft_sswap(t_ilist *lsta, t_ilist *lstb, int ischeck);

int			ft_issorta(t_ilist *ilst);

t_lst		*ft_join_rightpart(t_lst *lst);

void		ft_free_and_exit(
				long long *ar, t_lst *pList, t_ilist **lsta, t_ilist **lstb);

void		ft_checker_free_and_exit(
				char *buf, t_lst *pList, t_ilist *lsta, t_ilist *lstb);

void		ft_sorta(t_ilist *lsta, t_ilist **ilstb, int jb, long long *ar);

void		ft_rrr_or_revrotate(
				t_ilist *lsta, t_ilist *lstb, int isa, long long *ar);

void		ft_ss_or_swap(t_ilist *lsta, t_ilist *lstb, int isa);

int			ft_mida(t_ilist *lsta, long long *ar);

int			ft_midb(t_ilist *lstb);

int			ft_shortestpass(t_ilist *lsta, long long mid);

int			ft_shortestpassb(t_ilist *lstb, long long mid);

int			ft_pushtob(t_ilist *lsta, t_ilist **ilstb, int jb, long long *ar);

t_ilist		*ft_ilst_set_maxmin(t_ilist *ilst, int imin, int imax);

t_ilist		*ft_ilst_null_plist(int imin, int imax, int isa, int j);

void		ft_isilst_null(
				t_ilist *ilst, t_ilist **ilstas, t_ilist **ilstbs,
				long long *ar);

char		*get_next_line(int fd);

#endif
