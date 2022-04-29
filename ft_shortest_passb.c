/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_passb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:51 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:52 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_helper_shortestpass0b(t_lst *last, long long mid)
{
	int	iright;

	iright = 0;
	while (last && last->content < mid)
	{
		last = last->next;
		iright++;
	}
	return (iright);
}

static int	ft_shortestpass0b(t_ilist *lstb, long long mid)
{
	t_lst	*last;
	t_lst	*tmp;
	int		ileft;

	tmp = lstb->lst;
	last = ft_join_rightpart(lstb->lst);
	ileft = 0;
	if (!lstb || !(lstb->lst))
		return (-1);
	if (lstb->lst->content >= mid)
		return (0);
	while (tmp && tmp->content < mid)
	{
		tmp = tmp->prev;
		ileft++;
	}
	if (!tmp)
		return (-1);
	if (ileft > ft_helper_shortestpass0b(last, mid))
		return (2);
	else
		return (1);
}

static int	ft_helper_shortestpassb(t_lst *tmp, long long mid, int iright)
{
	int	ileft;

	ileft = 0;
	while (tmp && tmp->content < mid)
	{
		tmp = tmp->prev;
		ileft++;
	}
	if (!tmp)
		ileft = 0;
	if (!ileft && !iright)
		return (-1);
	if ((!ileft && iright) || (iright && ileft > iright))
		return (2);
	else
		return (1);
}

int	ft_shortestpassb(t_ilist *lstb, long long mid)
{
	t_lst	*tmp;
	int		iright;

	tmp = lstb->lst;
	iright = 0;
	if (!(lstb->j))
		return (ft_shortestpass0b(lstb, mid));
	if (lstb && lstb->lst && lstb->lst->content >= mid)
		return (0);
	while (tmp && tmp->content < mid)
	{
		tmp = tmp->next;
		iright++;
	}
	if (!tmp)
		iright = 0;
	tmp = lstb->lst;
	return (ft_helper_shortestpassb(tmp, mid, iright));
}
