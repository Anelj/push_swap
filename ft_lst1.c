/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:45:54 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:45:57 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ft_ilst_null_plist(int imin, int imax, int isa, int j)
{
	t_ilist	*ilst;

	ilst = ft_ilst(NULL, isa, j);
	if (!ilst)
		return (NULL);
	ft_ilst_set_maxmin(ilst, imin, imax);
	return (ilst);
}

void	ft_isilst_null(t_ilist *ilst, t_ilist **ilstas, t_ilist **ilstbs,
					long long *ar)
{
	if (!ilst)
		ft_free_and_exit(ar, NULL, ilstas, ilstbs);
}
