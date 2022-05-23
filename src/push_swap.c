/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/23 15:27:17 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_clean_tab(t_ps *ps, t_bool fail)
{
	ft_printf("FREEING TAB A\n");
	if (ps->tab_a != NULL)
		free(ps->tab_a);
	ft_printf("FREEING TAB B\n");
	if (ps->tab_b != NULL)
		free(ps->tab_b);
	ft_printf("FREEING IDX A\n");
	if (ps->idx_a != NULL)
		free(ps->idx_a);
	ft_printf("FREEING IDX B\n");
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
	return (ps_clean_tab(ps, GOOD));
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
		return (ps_sort_3(&ps));
	ps_display_all_tabs(&ps);
	ps_clean_tab(&ps, 0);
	return (EXIT_SUCCESS);
}
