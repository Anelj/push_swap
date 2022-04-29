/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <mgoliath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:44:54 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/23 19:44:57 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_digitstr(char *str, int *i)
{
	while ((*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ') && *str)
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			*i = 1;
		str++;
	}
	return (str);
}

long long	ft_atoilong(char *str, long long *ar)
{
	int			i;
	long long	n;

	i = 0;
	n = 0;
	str = ft_digitstr(str, &i);
	if (!(*str >= '0' && *str <= '9') || !*str)
		ft_free_and_exit(ar, NULL, NULL, NULL);
	while ((*str >= '0' && *str <= '9') && *str)
	{
		if (n < 2147483647 / 10
			|| (n == 2147483647 / 10 && ((i != 1 && *str <= '7')
					|| (i == 1 && *str <= '8'))))
		{
			n = n * 10 + (long long)((int)*str - 48);
			str++;
		}
		else
			ft_free_and_exit(ar, NULL, NULL, NULL);
	}
	if (*str)
		ft_free_and_exit(ar, NULL, NULL, NULL);
	if (i == 1)
		n = -n;
	return (n);
}
