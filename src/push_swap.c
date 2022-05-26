/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/26 20:06:50 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_malloc(t_ps *ps)
{
	ps->tab_a = malloc(sizeof(int) * (ps->len));
	ps->tab_b = malloc(sizeof(int) * (ps->len));
	ps->idx_a = malloc(sizeof(int) * (ps->len));
	ps->idx_b = malloc(sizeof(int) * (ps->len));
	if (ps->len > 5 && ps->len < 101)
		ps->lmt = malloc(sizeof(int) * 5);
	if (ps->len > 100)
		ps->lmt = malloc(sizeof(int) * 11);
	if (ps->tab_a == NULL || ps->tab_b == NULL
		|| ps->idx_a == NULL || ps->idx_b == NULL)
		return (ps_clean_tab(ps, FAIL));
	if (ps->len > 5 && ps->lmt == NULL)
		return (ps_clean_tab(ps, FAIL));
	return (EXIT_SUCCESS);
}

int	ps_clean_tab(t_ps *ps, t_bool fail)
{
	if (ps->tab_a != NULL)
		free(ps->tab_a);
	if (ps->tab_b != NULL)
		free(ps->tab_b);
	if (ps->idx_a != NULL)
		free(ps->idx_a);
	if (ps->idx_b != NULL)
		free(ps->idx_b);
	if (ps->len > 5)
		if (ps->lmt != NULL)
			free(ps->lmt);
	return (fail);
}

void	ps_sort_3(t_ps *ps)
{
	if (ft_issorted(ps->idx_a, ps->in_a, INCREASING))
		return ;
	if (ps->len < 3)
		ps_swap_a(ps);
	else if (ps->idx_a[0] > ps->idx_a[1] && ps->idx_a[0] > ps->idx_a[2]
		&& ps->idx_a[1] < ps->idx_a[2])
		ps_rotate_a(ps);
	else if (ps->tab_a[0] < ps->tab_a[1] && ps->tab_a[0] > ps->tab_a[2]
		&& ps->tab_a[1] > ps->tab_a[2])
		ps_rrotate_a(ps);
	else
	{
		if (ps->tab_a[0] > ps->tab_a[1] && ps->tab_a[0] > ps->tab_a[2])
			ps_rotate_a(ps);
		else if (ps->tab_a[0] < ps->tab_a[1] && ps->tab_a[0] < ps->tab_a[2])
			ps_rrotate_a(ps);
		ps_swap_a(ps);
	}
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ps_fill_tab_a(&ps, ac, av) == EXIT_FAILURE)
		return (ft_put_errmsg(PS_ERR_MSG));
	if (ft_issorted(ps.idx_a, ps.len, INCREASING))
		return (ps_clean_tab(&ps, GOOD));
	if (ps.len < 4)
		ps_sort_3(&ps);
	else if (ps.len < 6)
		ps_sort_5(&ps);
	else
	{
		if (ps.len < 101)
			ps.chunk = 5;
		else
			ps.chunk = 14;
		ps_chunker(&ps);
		ps_sort_hundred(&ps);
	}
	ps_clean_tab(&ps, GOOD);
	return (EXIT_SUCCESS);
}
