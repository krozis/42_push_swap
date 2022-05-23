/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/23 15:13:59 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (fail);
}

int	ps_sort_3(t_ps *ps)
{
	if (ps->len < 3)
		ps_swap_a(ps);
	else if (ps->tab_a[0] > ps->tab_a[1] && ps->tab_a[1] < ps->tab_a[2]
		&& ps->tab_a[0] > ps->tab_a[2])
		ps_rotate_a(ps);
	else if (ps->tab_a[0] < ps->tab_a[1] && ps->tab_a[0] > ps->tab_a[2]
		&& ps->tab_a[0] > ps->tab_a[2])
		ps_rrotate_a(ps);
	else
	{
		if (ps->tab_a[0] < ps->tab_a[1] && ps->tab_a[1] > ps->tab_a[2])
			ps_rrotate_a(ps);
		else if (ps->tab_a[0] > ps->tab_a[1] && ps->tab_a[1] > ps->tab_a[2])
			ps_rotate_a(ps);
		ps_swap_a(ps);
	}
	ps_clean_tab(ps, TRUE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ps_fill_tab_a(&ps, ac, av) == EXIT_FAILURE)
		return (ft_put_errmsg(PS_ERR_MSG));
	if (ft_issorted(ps.tab_a, ps.len, TRUE))
		return (ps_clean_tab(&ps, TRUE));
	if (ps.len < 4)
		return (ps_sort_3(&ps));
	ps_display_all_tabs(&ps);
	ps_clean_tab(&ps, 0);
	return (EXIT_SUCCESS);
}
