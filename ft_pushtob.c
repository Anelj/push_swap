/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushtob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:33 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:35 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pushtob_shortp2(
		long long *ar, t_ilist *lsta, t_ilist *lstb, t_ilist *lstbprev)
{
	int	mid;

	mid = lsta->imin - 1;
	while (lsta->lst->content > ar[mid])
	{
		if (lstb->lst)
			ft_rrr_or_revrotate(lsta, lstb, 1, ar);
		else
			ft_rrr_or_revrotate(lsta, lstbprev, 1, ar);
	}
}

static void	ft_pushtob_shortp1(
		long long *ar, t_ilist *lsta, t_ilist *lstb, t_ilist *lstbprev)
{
	int	mid;

	mid = lsta->imin - 1;
	while (lsta->lst->content > ar[mid])
	{
		if (lstb->lst)
			ft_rr_or_rotate(lsta, lstb, 1, ar);
		else
			ft_rr_or_rotate(lsta, lstbprev, 1, ar);
	}
}

static int	ft_helper_pushtob(
		long long *ar, t_ilist *lsta, t_ilist *lstb, t_ilist *lstbprev)
{
	int	shortp;

	shortp = ft_shortestpass(lsta, ar[lsta->imin - 1]);
	while (shortp != -1)
	{
		if (shortp == 1)
		{
			ft_pushtob_shortp1(ar, lsta, lstb, lstbprev);
			if (!(lstb->lst) && ft_issorta(lsta))
				return (0);
			ft_push(lstb, lsta, 0);
		}
		else if (shortp == 2)
		{
			ft_pushtob_shortp2(ar, lsta, lstb, lstbprev);
			if (!(lstb->lst) && ft_issorta(lsta))
				return (0);
			ft_push(lstb, lsta, 0);
		}
		else if (shortp == 0)
			ft_push(lstb, lsta, 0);
		shortp = ft_shortestpass(lsta, ar[lsta->imin - 1]);
	}
	return (1);
}

int	ft_pushtob(t_ilist *lsta, t_ilist **ilstb, int jb, long long *ar)
{
	t_ilist	*lstb;
	int		jbprev;

	lstb = ilstb[jb];
	if (jb - 1 < 0)
		jbprev = jb;
	else
		jbprev = jb - 1;
	return (ft_helper_pushtob(ar, lsta, lstb, ilstb[jbprev]));
}
