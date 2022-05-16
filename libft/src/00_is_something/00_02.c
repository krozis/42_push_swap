/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:15:21 by krozis            #+#    #+#             */
/*   Updated: 2022/05/16 20:45:48 by krozis           ###   ########.fr       */
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
