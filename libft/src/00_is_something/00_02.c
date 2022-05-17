/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:15:21 by krozis            #+#    #+#             */
/*   Updated: 2022/05/17 18:00:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isnumber(char *nb)
{
	int	i;

	i = -1;
	if (nb[0] == '-')
		i++;
	while (nb[++i])
		if (!(ft_isdigit(nb[i])))
			return (FALSE);
	return (TRUE);
}

t_bool	ft_hasdouble(int tab[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] == tab[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
