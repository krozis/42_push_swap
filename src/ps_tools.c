/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:10 by krozis            #+#    #+#             */
/*   Updated: 2022/05/25 18:38:47 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	ps_get_closest(t_ps	*ps);

void	ps_chunker(t_ps *ps)
{
	int i;
	int	add;
	int div;
	int mod;
	
	i = 0;
	add = 1;
	div = ps->len / ps->chunk;
	mod = ps->len % ps->chunk;
	ft_printf("number of int = %i\n", ps->len);
	while (i < ps->chunk)
	{
		ps->lmt[i] = div * (i + 1);
		if (i >= ps->chunk - mod)
		{
			ps->lmt[i] += add;
			add++;
		}
		ft_printf("CHUNK %i (limit = %i)\n", i + 1, ps->lmt[i]);
		i++;
	}
}
