/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:46:10 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:46:13 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrevrotate(t_ilist *lsta, t_ilist *lstb, int ischeck)
{
	ft_revrotate(&(lsta->lst), 1, 1);
	ft_revrotate(&(lstb->lst), 0, 1);
	if (!ischeck)
		write(1, "rrr\n", 4);
}

void	ft_rrotate(t_ilist *lsta, t_ilist *lstb, int ischeck)
{
	ft_rotate(&(lsta->lst), 1, 1);
	ft_rotate(&(lstb->lst), 0, 1);
	if (!ischeck)
		write(1, "rr\n", 3);
}

void	ft_sswap(t_ilist *lsta, t_ilist *lstb, int ischeck)
{
	ft_swap(&(lstb->lst), 0, 1);
	ft_swap(&(lsta->lst), 1, 1);
	if (!ischeck)
		write(1, "ss\n", 3);
}
