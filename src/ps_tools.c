/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:10 by krozis            #+#    #+#             */
/*   Updated: 2022/05/26 19:49:15 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_resort_chunk(t_ps *ps, int chunk)
{
	if (chunk == 0)
	{
		if (ps->idx_b[0] == 0)
			ps_rotate_b(ps);
		else
			while (ps->idx_b[ps->in_b - 1] > ps->idx_b[0])
				ps_rrotate_b(ps);
	}
	else
		while (ps_is_in_chunk(ps, ps->idx_b[ps->in_b - 1], chunk))
			ps_rrotate_b(ps);
}

void	ps_push_back(t_ps *ps)
{
	while (ps->in_b)
		ps_push_a(ps);
}

t_bool	ps_is_in_chunk(t_ps *ps, int nb, int chunk)
{
	if (nb < ps->lmt[chunk])
	{
		if (chunk == 0)
			return (TRUE);
		if (nb >= ps->lmt[chunk - 1])
			return (TRUE);
	}
	return (FALSE);
}

int	ps_get_closest(t_ps	*ps, int chunk)
{
	int	i;
	int	j;

	i = 0;
	j = ps->in_a - 1;
	while (i <= ps->in_a / 2)
	{
		if (ps_is_in_chunk(ps, ps->idx_a[i], chunk))
			break ;
		i++;
	}
	while (j >= ps->in_a / 2)
	{
		if (ps_is_in_chunk(ps, ps->idx_a[j], chunk))
			break ;
		j--;
	}
	if (i > ps->in_a - j)
		return (-1 * (ps->in_a - j));
	return (i);
}

void	ps_chunker(t_ps *ps)
{
	int	i;
	int	add;
	int	div;
	int	mod;

	i = 0;
	add = 1;
	div = ps->len / ps->chunk;
	mod = ps->len % ps->chunk;
	while (i < ps->chunk)
	{
		ps->lmt[i] = div * (i + 1);
		if (i >= ps->chunk - mod)
		{
			ps->lmt[i] += add;
			add++;
		}
		i++;
	}
}
