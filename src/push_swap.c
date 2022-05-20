/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/20 14:34:07 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ps_display_rel_tab(&ps);
	ps_clean_tab(&ps, TRUE);
	return (EXIT_SUCCESS);
}
