/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:11 by krozis            #+#    #+#             */
/*   Updated: 2022/05/26 19:51:20 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_chunk_c(t_ps *ps)
{
	if (ps->idx_a[0] > ps->idx_b[0])
		while (ps->idx_a[0] > ps->idx_b[ps->in_b - 1])
			ps_rrotate_b(ps);
	else
		while (ps->idx_a[0] < ps->idx_b[0])
			ps_rotate_b(ps);
}

static void	ps_sort_chunk_b(t_ps *ps, int chunk, t_bool is_min, t_bool is_max)
{
	if (is_max == TRUE)
	{
		if (chunk != 0)
			while (ps_is_in_chunk(ps, ps->idx_b[ps->in_b - 1], chunk))
				ps_rrotate_b(ps);
		else
			while (ps->idx_b[ps->in_b - 1] > ps->idx_b[0])
				ps_rrotate_b(ps);
	}
	if (is_min == TRUE)
	{
		if (chunk != 0)
			while (ps_is_in_chunk(ps, ps->idx_b[0], chunk))
				ps_rotate_b(ps);
		else
			while (ps->idx_b[ps->in_b - 1] > ps->idx_b[0])
				ps_rotate_b(ps);
	}
	if (is_min == FALSE && is_max == FALSE)
		ps_sort_chunk_c(ps);
}

static void	ps_sort_chunk_a(t_ps *ps, int chunk)
{
	int		i;
	t_bool	is_max;
	t_bool	is_min;

	i = 0;
	is_max = TRUE;
	is_min = TRUE;
	while (i < ps->in_b)
	{
		if (ps_is_in_chunk(ps, ps->idx_b[i], chunk)
			&& ps->idx_a[0] > ps->idx_b[i])
			is_min = 0;
		else if (ps_is_in_chunk(ps, ps->idx_b[i], chunk)
			&& ps->idx_a[0] < ps->idx_b[i])
			is_max = 0;
		i++;
	}
	ps_sort_chunk_b(ps, chunk, is_min, is_max);
	ps_push_b(ps);
}

static void	ps_push_chunk(t_ps *ps, int chunk)
{
	if (ps->in_b < 2 || (ps->idx_a[0] > ps->idx_b[0]
			&& ps->idx_a[0] < ps->idx_b[ps->in_b - 1]))
		ps_push_b(ps);
	else
		ps_sort_chunk_a(ps, chunk);
	if (ps->in_b == 2 && ps->idx_b[0] < ps->idx_b[1])
		ps_swap_b(ps);
}

void	ps_sort_hundred(t_ps *ps)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = ps->lmt[0];
	while (i < ps->chunk)
	{
		if (i != 0)
			nb = ps->lmt[i] - ps->lmt[i - 1];
		while (nb--)
		{
			j = ps_get_closest(ps, i);
			if (j > 0)
				while (j--)
					ps_rotate_a(ps);
			else if (j < 0)
				while (j++)
					ps_rrotate_a(ps);
			ps_push_chunk(ps, i);
		}
		ps_resort_chunk(ps, i);
		i++;
	}
	ps_push_back(ps);
}
