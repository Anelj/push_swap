/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:47:38 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:47:40 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_ilist		**lsta;
	t_ilist		**lstb;
	long long	*ar;
	t_lst		*lst;

	if (argc == 1)
		return (0);
	ar = malloc(sizeof(long long) * (argc - 1));
	if (!ar)
		ft_free_and_exit(NULL, NULL, NULL, NULL);
	i = 0;
	while (ar && *(++argv))
		ar[i++] = ft_atoilong(*argv, ar);
	lst = ft_lst(ar, argc - 1);
	if (!lst)
		ft_free_and_exit(ar, NULL, NULL, NULL);
	lsta = ft_grouped_lst(lst, argc, ar, NULL);
	lstb = ft_grouped_lst(NULL, argc, ar, lsta);
	if (ft_sort(ar, argc - 1))
		ft_free_and_exit(ar, NULL, lsta, lstb);
	ft_push_swap(lsta, lstb, ar);
	ft_free(ar, NULL, lsta, lstb);
	return (0);
}

t_ilist	**ft_grouped_lst(t_lst *pList, int argc, long long *ar, t_ilist **ilsts)
{
	t_ilist	**lsts;
	int		i;

	lsts = malloc(argc * sizeof(t_ilist *));
	if (!lsts)
	{
		if (pList)
			ft_free_and_exit(ar, pList, NULL, ilsts);
		else
			ft_free_and_exit(ar, pList, ilsts, NULL);
	}
	i = 0;
	while (lsts && i < argc)
	{
		lsts[i] = NULL;
		i++;
	}
	if (lsts && pList)
	{
		lsts[0] = ft_ilst(pList, 1, 0);
		if (!lsts[0])
			ft_free_and_exit(ar, pList, ilsts, NULL);
		ft_ilst_set_maxmin(lsts[0], 0, argc - 2);
	}
	return (lsts);
}
