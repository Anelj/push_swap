/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:24 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:27 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_swap(int isa, int ischeck)
{
	if (isa && !ischeck)
		write(1, "sa\n", 3);
	else if (!ischeck)
		write(1, "sb\n", 3);
}

void	ft_swap(t_lst **list, int isa, int ischeck)
{
	t_lst	*lst;
	t_lst	*tmp;

	ft_print_swap(isa, ischeck);
	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return ;
	lst = *list;
	if (!lst || !(lst->prev))
	{
		if (ischeck && lst && lst->next)
			ft_join_rightpart(lst);
		else
			return ;
	}
	tmp = lst->prev;
	if (lst->next)
		lst->next->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = lst;
	tmp->next = lst->next;
	lst->next = tmp;
	lst->prev = tmp->prev;
	tmp->prev = lst;
	*list = tmp;
}

void	ft_rotate(t_lst **list, int isa, int ischeck)
{
	t_lst	*lst;

	if (isa && !ischeck)
		write(1, "ra\n", 3);
	else if (!ischeck)
		write(1, "rb\n", 3);
	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return ;
	lst = *list;
	if (!(lst->prev) && (lst->next))
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		*list = lst;
	}
	else
	{
		*list = lst->prev;
	}
}

void	ft_revrotate(t_lst **list, int isa, int ischeck)
{
	t_lst	*lst;
	t_lst	*tmp;

	if (isa && !ischeck)
		write(1, "rra\n", 4);
	else if (!ischeck)
		write(1, "rrb\n", 4);
	if (!list || !(*list) || ((!((*list)->next)) && !((*list)->prev)))
		return ;
	lst = *list;
	if (lst->next)
		*list = lst->next;
	else
	{
		tmp = lst;
		while (lst->prev)
		{
			lst = lst->prev;
		}
		*list = lst;
		lst->next->prev = NULL;
		lst->next = NULL;
		lst->prev = tmp;
		tmp->next = lst;
	}
}
