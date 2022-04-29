/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroj_ilsts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:20 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:47:21 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_join_rightpart(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*prevlast;
	t_lst	*last;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	if (!(lst->next))
		return (tmp);
	prevlast = tmp;
	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	last = lst->next;
	lst->next->prev = NULL;
	lst->next = NULL;
	tmp->next = prevlast;
	prevlast->prev = tmp;
	return (last);
}
