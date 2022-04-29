/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:18 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:20 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_del_lstel_from_from(t_ilist *from, t_lst *tmp, int ischeck)
{
	t_lst	*tmp1;

	if (tmp->prev)
	{
		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}
	else if (tmp->next && from->j)
	{
		from->lst = tmp->next;
		from->lst->prev = NULL;
		if (from->isa && !ischeck)
			write(1, "rra\n", 4);
		else if (!ischeck)
			write(1, "rrb\n", 4);
	}
	else if (tmp->next)
	{
		tmp1 = tmp->next;
		tmp1->prev = NULL;
		while (tmp1->next)
			tmp1 = tmp1->next;
		from->lst = tmp1;
	}
}

static void	ft_add_lstel_to_to(t_ilist *to, t_lst *tmp)
{
	if (to->lst)
	{
		tmp->next = to->lst->next;
		if (to->lst->next)
			to->lst->next->prev = tmp;
		to->lst->next = tmp;
		tmp->prev = to->lst;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	to->lst = tmp;
}

void	ft_push(t_ilist *to, t_ilist *from, int ischeck)
{
	t_lst	*tmp;

	if (from->isa && !ischeck)
		write(1, "pb\n", 3);
	else if (!ischeck)
		write(1, "pa\n", 3);
	if (!from || !to || !(from->lst))
		return ;
	tmp = from->lst;
	from->lst = tmp->prev;
	ft_del_lstel_from_from(from, tmp, ischeck);
	ft_add_lstel_to_to(to, tmp);
}
