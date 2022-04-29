/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:45:32 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:45:34 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_and_exit(
		long long *ar, t_lst *pList, t_ilist **lsta, t_ilist **lstb)
{
	ft_free(ar, pList, lsta, lstb);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_checker(
		long long *ar, t_lst *pList, t_ilist *lsta, t_ilist *lstb)
{
	free(ar);
	if (pList && !lsta)
		ft_lst_of_ilst_clear(&pList);
	if (lsta && lsta->lst)
		ft_lst_of_ilst_clear(&(lsta->lst));
	free(lsta);
	if (lstb && lstb->lst)
		ft_lst_of_ilst_clear(&(lstb->lst));
	free(lstb);
}

void	ft_checker_free_and_exit(
		char *buf, t_lst *pList, t_ilist *lsta, t_ilist *lstb)
{
	free(buf);
	ft_free_checker(NULL, pList, lsta, lstb);
	write(2, "Error\n", 6);
	close(0);
	get_next_line(0);
	exit(1);
}

void	ft_free(long long int *ar, t_lst *pList, t_ilist **lsta, t_ilist **lstb)
{
	int	i;

	free(ar);
	if (pList)
		ft_lst_of_ilst_clear(&pList);
	i = 0;
	while (lsta && lsta[i])
	{
		if (lsta[i]->lst)
			ft_lst_of_ilst_clear(&(lsta[i]->lst));
		free(lsta[i]);
		i++;
	}
	free(lsta);
	i = 0;
	while (lstb && lstb[i])
	{
		if (lstb[i]->lst)
			ft_lst_of_ilst_clear(&(lstb[i]->lst));
		free(lstb[i]);
		i++;
	}
	free(lstb);
}

void	ft_free_cmds(char **cmds)
{
	char	**tmp;

	tmp = cmds;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(cmds);
}
