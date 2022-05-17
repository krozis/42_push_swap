/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:55:48 by stelie            #+#    #+#             */
/*   Updated: 2022/05/17 16:56:00 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_display_tab(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->len)
	{
		ft_printf("[%i]\t\t[%i]\n", ps->tab_a[i], ps->tab_b[i]);
		i++;
	}
	ft_printf("[tab A]\t\t[tab B]\n");
}
