/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:04 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:06 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_midb(t_ilist *lstb)
{
	int	imin;
	int	imax;

	imin = lstb->imin;
	imax = lstb->imax;
	if (imax - imin == 2)
		return (imin);
	if (imax - imin <= 4)
		return (imax - 1);
	return (imin + (imax - imin) / 2 + (imax - imin) % 2 + 1);
}

static int	ft_helper_mida(int i, int imin, int imax)
{
	if (i < imin)
		return (-1);
	if (imax - imin == 2)
		return (imin);
	if (imax - imin <= 6 && imax - 2 - 1 <= i)
		return (imax - 2 - 1);
	if ((imin + (imax - imin) / 2) <= i)
		return (imin + (imax - imin) / 2);
	return (i);
}

int	ft_mida(t_ilist *lsta, long long *ar)
{
	int		imin;
	int		imax;
	t_lst	*tmp;
	int		i;

	imin = lsta->imin;
	imax = lsta->imax;
	tmp = lsta->lst;
	while (tmp && tmp->content != ar[imax])
		tmp = tmp->prev;
	if (!tmp)
	{
		tmp = lsta->lst;
		while (tmp && tmp->content != ar[imax])
			tmp = tmp->next;
	}
	i = imax;
	while (i >= imin && tmp && tmp->content == ar[i])
	{
		tmp = tmp->next;
		i--;
	}
	return (ft_helper_mida(i, imin, imax));
}
