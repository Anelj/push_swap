/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortthreea.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:56 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:56 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_helper_sortthreea0(long long *ar, t_ilist *lsta, t_ilist *lstb)
{
	t_lst	*lst;

	lst = lsta->lst;
	if (lst && lst->content == ar[lsta->imin]
		&& lst->prev->content == ar[lsta->imax])
	{
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
		ft_ss_or_swap(lsta, lstb, 1);
	}
	else if (lst && lst->prev->content == ar[lsta->imin]
		&& lst->content == ar[lsta->imax])
		ft_rotate(&(lsta->lst), 1, 0);
	else if (lst && lst->prev->content == ar[lsta->imin]
		&& lst->prev->prev->content == ar[lsta->imax])
		ft_ss_or_swap(lsta, lstb, 1);
	else if (lst && lst->prev->prev->content == ar[lsta->imin]
		&& lst->prev->content == ar[lsta->imax])
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	else if (lst && lst->prev->prev->content == ar[lsta->imin]
		&& lst->content == ar[lsta->imax])
	{
		ft_ss_or_swap(lsta, lstb, 1);
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	}
	return (ft_issorta(lsta));
}

static int	ft_sortthreea0(
		t_ilist *lsta, long long *ar, t_ilist **ilstb, int jb)
{
	t_ilist	*lstb;

	if (jb > 0)
		lstb = ilstb[jb];
	else
		lstb = NULL;
	if (lsta->j || lsta->imax - lsta->imin != 2)
		return (0);
	ft_join_rightpart(lsta->lst);
	return (ft_helper_sortthreea0(ar, lsta, lstb));
}

static void	ft_helper1_sortthreea(long long *ar, t_ilist *lsta, t_ilist *lstb)
{
	if (!(lsta->lst->prev))
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	if (lsta->lst->next && lsta->lst->next->content == ar[lsta->imin]
		&& lsta->lst->prev->content == ar[lsta->imax])
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	if (((lsta->lst->next && lsta->lst->next->content == ar[lsta->imin]
				&& lsta->lst->content == ar[lsta->imax])
			|| (!(lsta->lst->next) && lsta->lst->content == ar[lsta->imin]
				&& lsta->lst->prev->content == ar[lsta->imax])))
	{
		if (!(lsta->lst->next))
			ft_rotate(&(lsta->lst), 1, 0);
		if (lsta->lst->content == ar[lsta->imax])
			ft_ss_or_swap(lsta, lstb, 1);
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
	}
}

void	ft_helper2_sortthreea(long long *ar, t_ilist *lsta, t_ilist *lstb)
{
	if ((!(lsta->lst->next) && lsta->lst->prev->content == ar[lsta->imin]
			&& lsta->lst->prev->prev->content == ar[lsta->imax])
		|| (lsta->lst->next && lsta->lst->prev->content == ar[lsta->imax]
			&& lsta->lst->content == ar[lsta->imin]))
	{
		if (lsta->lst->next)
			ft_rrr_or_revrotate(lsta, lstb, 1, ar);
		ft_ss_or_swap(lsta, lstb, 1);
	}
	if (!(lsta->lst->next) && lsta->lst->prev->content == ar[lsta->imax]
		&& lsta->lst->prev->prev->content == ar[lsta->imin])
		ft_rotate(&(lsta->lst), 1, 0);
	if (lsta->lst->content == ar[lsta->imax]
		&& lsta->lst->prev->content == ar[lsta->imin])
	{
		ft_ss_or_swap(lsta, lstb, 1);
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
		ft_ss_or_swap(lsta, lstb, 1);
	}
	if (lsta->lst->next && lsta->lst->next->content == ar[lsta->imax]
		&& lsta->lst->prev->content == ar[lsta->imin])
		ft_rrr_or_revrotate(lsta, lstb, 1, ar);
}

int	ft_sortthreea(t_ilist *lsta, long long *ar, t_ilist **ilstb, int jb)
{
	t_ilist	*lstb;

	if (jb > 0)
		lstb = ilstb[jb];
	else
		lstb = NULL;
	if (!lsta || lsta->imax - lsta->imin != 2)
		return (ft_issorta(lsta));
	if (!(lsta->j))
		return (ft_sortthreea0(lsta, ar, ilstb, jb));
	ft_helper1_sortthreea(ar, lsta, lstb);
	if (!(lsta->lst->next) && lsta->lst->prev->content == ar[lsta->imin]
		&& lsta->lst->content == ar[lsta->imax])
	{
		ft_ss_or_swap(lsta, lstb, 1);
		ft_sortthreea(lsta, ar, ilstb, jb);
	}
	ft_helper2_sortthreea(ar, lsta, lstb);
	if (!(lsta->lst->next) && lsta->lst->content == ar[lsta->imax]
		&& lsta->lst->prev->prev->content == ar[lsta->imin])
	{
		ft_ss_or_swap(lsta, lstb, 1);
		ft_sortthreea(lsta, ar, ilstb, jb);
	}
	return (ft_issorta(lsta));
}
