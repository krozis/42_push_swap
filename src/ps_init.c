/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:24:25 by krozis            #+#    #+#             */
/*   Updated: 2022/05/27 00:04:05 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_first_min(t_ps *ps)
{
	int		i;
	int		min;

	min = INT_MAX;
	i = 0;
	while (i < ps->len)
	{
		if (ps->tab_a[i] == INT_MIN)
			return (i);
		if (ps->tab_a[i] < min)
			min = ps->tab_a[i];
		i++;
	}
	i = 0;
	while (i < ps->len)
	{
		if (ps->tab_a[i] == min)
			return (i);
		i++;
	}
	return (i);
}

static int	ps_get_min(t_ps *ps, int old)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < ps->len)
	{
		if (ps->tab_a[i] < min && ps->tab_a[i] > old)
			min = ps->tab_a[i];
		i++;
	}
	i = 0;
	while (i < ps->len && ps->tab_a[i] != min)
		i++;
	return (i);
}

static int	ps_indexer(t_ps *ps)
{
	int	i;
	int	j;

	if (ft_hasdouble(ps->tab_a, ps->len))
		return (ps_clean_tab(ps, FAIL));
	ps->in_a = ps->len;
	ps->in_b = 0;
	i = 1;
	j = ps_get_first_min(ps);
	ps->idx_a[j] = 0;
	while (i < ps->len)
	{
		j = ps_get_min(ps, ps->tab_a[j]);
		ps->idx_a[j] = i;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ps_wrong_elem(char *elem)
{
	int	i;

	i = 0;
	if (elem[0] == '-' || elem[0] == '+')
		i++;
	while (elem[i])
	{
		if (!ft_isdigit(elem[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_atol(elem) > INT_MAX || ft_atol(elem) < INT_MIN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ps_fill_tab(t_ps *ps, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
	{
		if (ps_parse(ps, av) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		ps->len = ac - 1;
		if (ps_malloc(ps) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		while (i < ac)
		{
			if (ps_wrong_elem(av[i]) == EXIT_FAILURE)
				return (ps_clean_tab(ps, FAIL));
			ps->tab_a[i - 1] = ft_atoi(av[i]);
			ps->idx_a[i - 1] = -1;
			ps->idx_b[i - 1] = -1;
			i++;
		}
	}
	return (ps_indexer(ps));
}
