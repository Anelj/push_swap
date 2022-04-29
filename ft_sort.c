/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:02 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:47:03 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issorta0(t_ilist *ilst, t_lst *a, t_lst *tmp)
{
	if (!(ilst->j))
	{
		a->prev = tmp;
		tmp->next = a;
		ilst->lst->next->prev = NULL;
		ilst->lst->next = NULL;
		while (a->prev)
		{
			if (a->content > a->prev->content)
				return (0);
			a = a->prev;
		}
	}
	return (1);
}

int	ft_issorta(t_ilist *ilst)
{
	t_lst	*a;
	t_lst	*tmp;

	a = ilst->lst;
	while (a->next)
		a = a->next;
	if (!(ilst->j))
	{
		tmp = a;
		a = ilst->lst;
	}
	while (a->prev)
	{
		if (a->content > a->prev->content)
			return (0);
		a = a->prev;
	}
	return (ft_issorta0(ilst, a, tmp));
}

static void	ft_swap_in_ar(long long *ar, int imax, int i)
{
	long long	tmp;

	tmp = ar[imax];
	ar[imax] = ar[i];
	ar[i] = tmp;
}

int	ft_sort(long long *ar, int size)
{
	int			i;
	int			j;
	long long	max;
	int			imax;

	j = size;
	while (j != 1)
	{
		i = 1;
		max = ar[0];
		imax = 0;
		while (i < j)
		{
			if (ar[i] == max)
				return (1);
			if (ar[i] > max)
			{
				max = ar[i];
				imax = i;
			}
			i++;
		}
		ft_swap_in_ar(ar, imax, --j);
	}
	return (0);
}

void	ft_sorta(t_ilist *lsta, t_ilist **ilstb, int jb, long long *ar)
{
	t_ilist	*lstb;

	if (jb > 0)
		lstb = ilstb[jb];
	else
		lstb = NULL;
	while (lsta && lsta->lst && lsta->lst->next)
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	if (lsta && lsta->lst && lsta->lst->prev
		&& lsta->lst->prev->content < lsta->lst->content)
		ft_ss_or_swap(lsta, lstb, 1);
}
