/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:45:39 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:45:42 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lst_of_ilst_new(long long content, t_lst *lst)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (list == NULL)
	{
		return (NULL);
	}
	list->content = content;
	list->next = lst;
	list->prev = NULL;
	return (list);
}

t_lst	*ft_lst(long long *ar, int size)
{
	t_lst	*begin_list;
	t_lst	*lst;
	int		i;

	i = 1;
	lst = ft_lst_of_ilst_new(ar[0], NULL);
	if (!lst)
		return (NULL);
	begin_list = lst;
	while (lst && size > i)
	{
		lst->prev = ft_lst_of_ilst_new(ar[i], lst);
		lst = lst->prev;
		i++;
	}
	if (size != i)
	{
		ft_lst_of_ilst_clear(&begin_list);
		return (NULL);
	}
	return (begin_list);
}

void	ft_lst_of_ilst_clear(t_lst **list)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	if (!list && !*list)
		return ;
	tmp = (*list)->prev;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->prev;
		free(tmp1);
	}
	tmp = (*list)->next;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	free(*list);
	*list = NULL;
}

t_ilist	*ft_ilst_set_maxmin(t_ilist	*ilst, int imin, int imax)
{
	ilst->imin = imin;
	ilst->imax = imax;
	return (ilst);
}

t_ilist	*ft_ilst(t_lst *pList, int isa, int j)
{
	t_ilist	*ilst;

	ilst = malloc(sizeof(t_ilist));
	if (!ilst)
	{
		return (NULL);
	}
	ilst->lst = pList;
	ilst->isa = isa;
	ilst->j = j;
	return (ilst);
}
