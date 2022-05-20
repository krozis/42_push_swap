/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:58:00 by krozis            #+#    #+#             */
/*   Updated: 2022/05/20 13:18:01 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Shift UP all elements of A. First elem become last.
void	ps_rotate_a(t_ps *ps)
{
	int	i;

	if (ps->in_a < 2)
		return ;
	i = 0;
	while (++i < ps->in_a)
		ps_mini_swap(&(ps->tab_a[i]), &(ps->tab_a[i - 1]));
	ft_printf("ra\n");
}

//Shift UP all elements of B. First elem become last.
void	ps_rotate_b(t_ps *ps)
{
	int	i;

	if (ps->in_b < 2)
		return ;
	i = 0;
	while (++i < ps->in_b)
		ps_mini_swap(&(ps->tab_b[i]), &(ps->tab_b[i - 1]));
	ft_printf("rb\n");
}

//Shift DOWN all elements of A. Last elem become first.
void	ps_rrotate_a(t_ps *ps)
{
	int	i;

	if (ps->in_a < 2)
		return ;
	i = ps->in_a - 1;
	while (--i >= 0)
		ps_mini_swap(&(ps->tab_a[i]), &(ps->tab_a[i + 1]));
	ft_printf("rra\n");
}

//Shift DOWN all elements of B. Last elem become first.
void	ps_rrotate_b(t_ps *ps)
{
	int	i;

	if (ps->in_b < 2)
		return ;
	i = ps->in_b - 1;
	while (--i >= 0)
		ps_mini_swap(&(ps->tab_b[i]), &(ps->tab_b[i + 1]));
	ft_printf("rrb\n");
}
