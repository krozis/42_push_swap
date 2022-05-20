/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:02:41 by krozis            #+#    #+#             */
/*   Updated: 2022/05/20 13:15:41 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_a(t_ps *ps)
{
	int	tmp;

	if (ps->in_a < 2)
		return ;
	tmp = ps->tab_a[0];
	ps->tab_a[0] = ps->tab_a[1];
	ps->tab_a[1] = tmp;
	ft_printf("sa\n");
}

void	ps_swap_b(t_ps *ps)
{
	int	tmp;

	if (ps->in_b < 2)
		return ;
	tmp = ps->tab_b[0];
	ps->tab_b[0] = ps->tab_b[1];
	ps->tab_b[1] = tmp;
	ft_printf("sb\n");
}
