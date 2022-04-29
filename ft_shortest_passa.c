/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_passa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:43 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:45 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_helper_shortestpass(t_lst *tmp, long long mid, int ileft)
{
	int	iright;

	iright = 0;
	while (tmp && tmp->content > mid)
	{
		tmp = tmp->next;
		iright++;
	}
	if (!tmp)
		iright = 0;
	if (!ileft && !iright)
		return (-1);
	if ((!ileft && iright) || (iright && ileft > iright))
		return (2);
	else
		return (1);
}

static int	ft_helper_shortestpass0a(t_lst *last, long long mid)
{
	int	iright;

	iright = 0;
	while (last && last->content > mid)
	{
		last = last->next;
		iright++;
	}
	return (iright);
}

static int	ft_shortestpass0a(t_ilist *lsta, long long mid)
{
	t_lst	*last;
	t_lst	*tmp;
	int		ileft;

	tmp = lsta->lst;
	last = ft_join_rightpart(lsta->lst);
	ileft = 0;
	if (!lsta || !(lsta->lst))
		return (-1);
	if (lsta->lst->content <= mid)
		return (0);
	while (tmp && tmp->content > mid)
	{
		tmp = tmp->prev;
		ileft++;
	}
	if (!tmp)
		return (-1);
	if (ileft > ft_helper_shortestpass0a(last, mid))
		return (2);
	else
		return (1);
}

int	ft_shortestpass(t_ilist *lsta, long long mid)
{
	t_lst	*tmp;
	int		ileft;

	tmp = lsta->lst;
	ileft = 0;
	if (!(lsta->j))
		return (ft_shortestpass0a(lsta, mid));
	if (lsta->lst->content <= mid)
		return (0);
	while (tmp && tmp->content > mid)
	{
		tmp = tmp->prev;
		ileft++;
	}
	if (!tmp)
		ileft = 0;
	tmp = lsta->lst;
	return (ft_helper_shortestpass(tmp, mid, ileft));
}
