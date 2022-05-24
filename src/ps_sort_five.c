/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:13 by krozis            #+#    #+#             */
/*   Updated: 2022/05/24 15:33:04 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_s5_a(t_ps *ps)
{
	if (ps->idx_b[0] == 1)
	{
		if (ps->idx_a[0] == 0)
			ps_rotate_a(ps);
		ps_push_a(ps);
	}
	else if (ps->idx_b[0] == 2)
	{
		if (ps->idx_b[1] == 0 || ps->idx_b[1] == 1)
			ps_rotate_a(ps);
		else
			ps_rrotate_a(ps);
		ps_push_a(ps);
	}
	else
	{
		if (ps->idx_b[1] != 4)
			ps_rrotate_a(ps);
		ps_push_a(ps);
	}	
}

static void	ps_s5_b(t_ps *ps)
{
	if ((ps->idx_b[0] == 0 && ps->idx_a[0] == 3)
		|| (ps->idx_b[0] == 1 && ps->idx_a[0] == 4)
		|| (ps->idx_b[0] == 2 && ps->idx_a[0] == 0)
		|| (ps->idx_b[0] == 3 && ps->idx_a[0] == 1)
		|| (ps->idx_b[0] == 4 && ps->idx_a[0] == 2))
		ps_rotate_a(ps);
	if ((ps->idx_b[0] == 0 && ps->idx_a[0] == 4)
		|| ps->idx_a[0] == ps->idx_b[0] - 1)
		ps_rotate_a(ps);
	if ((ps->idx_b[0] == 0 && ps->idx_a[0] == 2)
		|| (ps->idx_b[0] == 1 && ps->idx_a[0] == 3)
		|| (ps->idx_b[0] == 2 && ps->idx_a[0] == 4)
		|| (ps->idx_b[0] == 3 && ps->idx_a[0] == 0)
		|| (ps->idx_b[0] == 4 && ps->idx_a[0] == 1))
		ps_rrotate_a(ps);
	ps_push_a(ps);
}

static void	ps_s5_c(t_ps *ps)
{
	if (ps->idx_a[0] == 0)
		return ;
	if (ps->idx_a[0] == 1)
		ps_rrotate_a(ps);
	if (ps->idx_a[0] == 2)
	{
		ps_rrotate_a(ps);
		ps_rrotate_a(ps);
	}
	if (ps->idx_a[0] == 3)
	{
		ps_rotate_a(ps);
		ps_rotate_a(ps);
	}
	if (ps->idx_a[0] == 4)
		ps_rotate_a(ps);
}

static void	ps_s4(t_ps *ps)
{
	ps_push_b(ps);
	ps_sort_3(ps);
	if (ps->idx_b[0] == 1)
		ps_rotate_a(ps);
	if (ps->idx_b[0] == 2)
		ps_rrotate_a(ps);
	ps_push_a(ps);
	if (ps->idx_a[0] == 2)
		ps_rotate_a(ps);
	if (ps->idx_a[0] == 2 || ps->idx_a[0] == 3)
		ps_rotate_a(ps);
	if (ps->idx_a[0] == 1)
		ps_rrotate_a(ps);
}

void	ps_sort_5(t_ps *ps)
{
	if (ps->len < 5)
		ps_s4(ps);
	else
	{
		ps_push_b(ps);
		ps_push_b(ps);
		ps_sort_3(ps);
		if (ps->idx_b[0] == 0 || ps->idx_b[0] == 4)
			ps_push_a(ps);
		else
			ps_s5_a(ps);
		ps_s5_b(ps);
		ps_s5_c(ps);
	}
}
