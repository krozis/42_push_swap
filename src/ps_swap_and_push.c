/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:00:41 by krozis            #+#    #+#             */
/*   Updated: 2022/05/26 19:54:34 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_mini_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// PUSH 1ST ELEMENT FROM B TO TOP OF A
void	ps_push_a(t_ps *ps)
{
	int	i;

	if (ps->in_b == 0)
		return ;
	ps->in_a++;
	i = ps->in_a;
	while (--i)
	{
		ps_mini_swap(&(ps->idx_a[i]), &(ps->idx_a[i - 1]));
		ps_mini_swap(&(ps->tab_a[i]), &(ps->tab_a[i - 1]));
	}
	ps->idx_a[0] = ps->idx_b[0];
	ps->tab_a[0] = ps->tab_b[0];
	i = 0;
	while (++i < ps->in_b)
	{
		ps_mini_swap(&(ps->idx_b[i]), &(ps->idx_b[i - 1]));
		ps_mini_swap(&(ps->tab_b[i]), &(ps->tab_b[i - 1]));
	}
	ps->in_b--;
	ps->idx_b[ps->in_b] = -1;
	ps->tab_b[ps->in_b] = 0;
	ft_printf("pa\n");
}

// PUSH 1ST ELEMENT FROM A TO TOP OF B
void	ps_push_b(t_ps *ps)
{
	int	i;

	if (ps->in_a == 0)
		return ;
	ps->in_b++;
	i = ps->in_b;
	while (--i)
	{
		ps_mini_swap(&(ps->idx_b[i]), &(ps->idx_b[i - 1]));
		ps_mini_swap(&(ps->tab_b[i]), &(ps->tab_b[i - 1]));
	}
	ps->idx_b[0] = ps->idx_a[0];
	ps->tab_b[0] = ps->tab_a[0];
	i = 0;
	while (++i < ps->in_a)
	{
		ps_mini_swap(&(ps->idx_a[i]), &(ps->idx_a[i - 1]));
		ps_mini_swap(&(ps->tab_a[i]), &(ps->tab_a[i - 1]));
	}
	ps->in_a--;
	ps->idx_a[ps->in_a] = -1;
	ps->tab_a[ps->in_a] = 0;
	ft_printf("pb\n");
}

// SWAP 1ST AND 2ND ELEMENTS IN A
void	ps_swap_a(t_ps *ps)
{
	if (ps->in_a < 2)
		return ;
	ps_mini_swap(&(ps->idx_a[0]), &(ps->idx_a[1]));
	ps_mini_swap(&(ps->tab_a[0]), &(ps->tab_a[1]));
	ft_printf("sa\n");
}

// SWAP 1ST AND 2ND ELEMENTS IN B
void	ps_swap_b(t_ps *ps)
{
	if (ps->in_b < 2)
		return ;
	ps_mini_swap(&(ps->idx_b[0]), &(ps->idx_b[1]));
	ps_mini_swap(&(ps->tab_b[0]), &(ps->tab_b[1]));
	ft_printf("sb\n");
}
