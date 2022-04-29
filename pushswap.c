/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:51 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:47:52 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_last_notnull_index(t_ilist **ilsts)
{
	int	i;

	i = 0;
	while (ilsts[i])
		i++;
	if (i)
		return (i - 1);
	return (i);
}

static int	ft_null_ilstb_after_pushtob(
		long long *ar, t_ilist **la, t_ilist **lb, int jb)
{
	int	mid;
	int	ja;

	ja = ft_find_last_notnull_index(la);
	while (((la[ja])->imax - (la[ja])->imin) > 1
		&& !ft_sortthreea(la[ja], ar, lb, jb - 1))
	{
		mid = ft_mida(la[ja], ar);
		if (mid < 0)
			break ;
		lb[jb] = ft_ilst_null_plist(la[ja]->imin, mid, 0, jb);
		ft_isilst_null(lb[jb], la, lb, ar);
		la[ja]->imin = mid + 1;
		if (!ft_pushtob(la[ja], lb, jb, ar))
		{
			if (!(lb[jb]->lst))
			{
				free(lb[jb]);
				lb[jb] = NULL;
			}
			break ;
		}
		jb++;
	}
	return (jb);
}

static void	ft_pushtoa(t_ilist *la, t_ilist *lb, long long mid, long long *ar)
{
	int	shortp;

	shortp = ft_shortestpassb(lb, mid);
	while (shortp != -1)
	{
		if (shortp == 0)
			ft_push(la, lb, 0);
		else if (shortp == 1)
		{
			while (lb->lst->content < mid)
				ft_rr_or_rotate(la, lb, 0, ar);
			ft_push(la, lb, 0);
		}
		else
		{
			while (lb->lst->content < mid)
				ft_rrr_or_revrotate(la, lb, 0, ar);
			ft_push(la, lb, 0);
		}
		shortp = ft_shortestpassb(lb, mid);
	}
}

static int	ft_nextnull_ilstb(long long *ar, t_ilist **la, int ja, t_ilist **lb)
{
	int	mid;
	int	jb;

	jb = ft_find_last_notnull_index(lb);
	if (lb[jb]->imax - lb[jb]->imin > 1)
		mid = ft_midb(lb[jb]);
	else
		mid = lb[jb]->imin;
	la[ja] = ft_ilst(NULL, 1, ja);
	if (!la[ja])
		ft_free_and_exit(ar, NULL, la, lb);
	ft_ilst_set_maxmin(la[ja], mid, lb[jb]->imax);
	lb[jb]->imax = mid - 1;
	ft_pushtoa(la[ja], lb[jb], ar[mid], ar);
	if (lb[jb]->imax - lb[jb]->imin < 0)
	{
		free(lb[jb]);
		lb[jb] = NULL;
		return (jb);
	}
	else
		return (jb + 1);
}

void	ft_push_swap(t_ilist **lsta, t_ilist **lstb, long long *ar)
{
	int	ja;
	int	jb;

	ja = 0;
	jb = 0;
	while (1)
	{
		jb = ft_null_ilstb_after_pushtob(ar, lsta, lstb, jb);
		ft_sorta(lsta[ja], lstb, jb - 1, ar);
		jb--;
		ja++;
		if (jb < 0)
			break ;
		if (lstb[jb])
		{
			jb = ft_nextnull_ilstb(ar, lsta, ja, lstb);
		}
	}
}
