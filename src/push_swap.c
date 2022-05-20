/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:30:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/20 13:13:53 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_sort_3(t_ps *ps)
{
	(void)ps;
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ps_fill_tab_a(&ps, ac, av) == EXIT_FAILURE)
		return (ft_put_errmsg(PS_ERR_MSG));
	if (ac < 4)
		return(ps_sort_3(&ps));
/*
	if (ac < 6)
		return (ps_sort_5(&ps));
*/
	ps_display_rel_tab(&ps);
	ps_clean_tab(&ps);
	return (EXIT_SUCCESS);
}
