/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:45:06 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:45:08 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_iscmd_and_execute(char *cmd, t_ilist *lsta, t_ilist *lstb)
{
	if (!ft_strncmp(cmd, "sa\n", 4))
		ft_swap(&(lsta->lst), 1, 1);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		ft_swap(&(lstb->lst), 0, 1);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ft_sswap(lsta, lstb, 1);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ft_rotate(&(lsta->lst), 1, 1);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		ft_rotate(&(lstb->lst), 0, 1);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		ft_rrotate(lsta, lstb, 1);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		ft_revrotate(&(lsta->lst), 1, 1);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		ft_revrotate(&(lstb->lst), 0, 1);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		ft_rrevrotate(lsta, lstb, 1);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		ft_push(lsta, lstb, 1);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		ft_push(lstb, lsta, 1);
	else
		return (0);
	return (1);
}

static void	ft_execute_cmds(t_ilist *lsta, t_ilist *lstb)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (!ft_iscmd_and_execute(s, lsta, lstb))
		{
			ft_checker_free_and_exit(s, NULL, lsta, lstb);
		}
		free(s);
		s = get_next_line(0);
	}
	if ((lstb && (lstb->lst)) || !ft_issorta(lsta))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	int			i;
	t_ilist		*lsta;
	t_ilist		*lstb;
	long long	*ar;
	t_lst		*lst;

	if (argc == 1)
		return (0);
	ar = malloc(sizeof(long long) * (argc - 1));
	if (!ar)
		ft_checker_free_and_exit(NULL, NULL, NULL, NULL);
	i = 0;
	while (*(++argv))
		ar[i++] = ft_atoilong(*argv, ar);
	lst = ft_lst(ar, argc - 1);
	if (ft_sort(ar, argc - 1))
		ft_free_and_exit(ar, lst, NULL, NULL);
	free(ar);
	lsta = ft_ilst(lst, 1, 0);
	lstb = ft_ilst(NULL, 0, 0);
	if (!lst || !lsta || !lstb)
		ft_checker_free_and_exit(NULL, lst, lsta, lstb);
	ft_execute_cmds(lsta, lstb);
	ft_free_checker(NULL, NULL, lsta, lstb);
	return (0);
}
