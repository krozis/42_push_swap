/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:55:48 by stelie            #+#    #+#             */
/*   Updated: 2022/05/20 12:40:44 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_display_tab(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len)
	{
		ft_printf("[%i]", ps->tab_a[i]);
		if (ft_nbrlen(ps->tab_a[i]) < 6)
			ft_printf("\t");
		ft_printf("\t[%i]\n", ps->tab_b[i]);
		i++;
	}
	ft_printf("[tab A]\t\t[tab B]\n");
}

void	ps_display_rel_tab(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len)
	{
		if (i < ps->in_a)
			ft_printf("[%i]", ps->tab_a[i]);
		if (ft_nbrlen(ps->tab_a[i]) < 6)
			ft_printf("\t");
		if (i < ps->in_b)
			ft_printf("\t[%i]", ps->tab_b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("[tab A]\t\t[tab B]\n");
}
