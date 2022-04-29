/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_rr_rrr_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:10 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:47:12 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_or_rotate(t_ilist *lsta, t_ilist *lstb, int isa, long long *ar)
{
	if (isa && lsta->lst && lsta->lst->prev && !(lsta->lst->prev->prev))
		ft_ss_or_swap(lsta, lstb, 1);
	else if (!isa && lstb && lstb->lst && lstb->lst->prev
		&& !(lstb->lst->prev->prev))
		ft_ss_or_swap(lsta, lstb, 0);
	else if ((isa && lstb && lstb->lst && lstb->lst->prev
			&& (lstb->lst->content < ar[ft_midb(lstb)]))
		|| (!isa && lsta->lst && lsta->lst->prev && ft_mida(lsta, ar) >= 0
			&& (lsta->lst->content > ar[ft_mida(lsta, ar)])))
	{
		ft_rotate(&(lsta->lst), 1, 1);
		ft_rotate(&(lstb->lst), 0, 1);
		write(1, "rr\n", 3);
	}
	else if (isa && lsta)
		ft_rotate(&(lsta->lst), 1, 0);
	else if (lstb)
		ft_rotate(&(lstb->lst), 0, 0);
}

void	ft_rrr_or_revrotate(
		t_ilist *lsta, t_ilist *lstb, int isa, long long *ar)
{
	if ((isa && lstb && lstb->lst && lstb->lst->next
			&& (lstb->lst->next->content >= ar[ft_midb(lstb)]))
		|| (!isa && lsta && lsta->lst && lsta->lst->next
			&& ft_mida(lsta, ar) > 0
			&& (lsta->lst->next->content <= ar[ft_mida(lsta, ar)])))
	{
		ft_revrotate(&(lsta->lst), 1, 1);
		ft_revrotate(&(lstb->lst), 0, 1);
		write(1, "rrr\n", 4);
	}
	else if (isa && lsta)
		ft_revrotate(&(lsta->lst), 1, 0);
	else if (lstb)
		ft_revrotate(&(lstb->lst), 0, 0);
}

void	ft_ss_or_swap(t_ilist *lsta, t_ilist *lstb, int isa)
{
	if ((isa && lstb && lstb->lst && lstb->lst->prev
			&& lstb->lst->content < lstb->lst->prev->content)
		|| (!isa && lsta && lsta->lst && lsta->lst->prev
			&& lsta->lst->content > lsta->lst->prev->content))
	{
		ft_swap(&(lstb->lst), 0, 1);
		ft_swap(&(lsta->lst), 1, 1);
		write(1, "ss\n", 3);
	}
	else if (isa)
		ft_swap(&(lsta->lst), 1, 0);
	else
		ft_swap(&(lstb->lst), 0, 0);
}
