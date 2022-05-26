/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:44:25 by krozis            #+#    #+#             */
/*   Updated: 2022/05/27 00:04:15 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_fill(t_ps *ps, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (ft_isdigit(*str) || *str == '-' || *str == '+')
		{
			if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
				return (ps_clean_tab(ps, FAIL));
			ps->tab_a[i] = ft_atoi(str);
			ps->idx_a[i] = -1;
			ps->idx_b[i] = -1;
			i++;
			str++;
			while (*str && ft_isdigit(*str))
				str++;
		}
	}
	return (EXIT_SUCCESS);
}

static int	ps_get_len(t_ps *ps, char *str)
{
	ps->len = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (*str && ft_isdigit(*str))
		{
			ps->len++;
			while (*str && ft_isdigit(*str))
				str++;
		}
	}
	if (ps->len == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ps_parse(t_ps *ps, char **av)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]))
			digit = 1;
		if (!ft_incharset(av[1][i], PS_ALLOWED))
			return (EXIT_FAILURE);
		i++;
	}
	if (!digit)
		return (EXIT_FAILURE);
	if (ps_get_len(ps, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ps_malloc(ps) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (ps_fill(ps, av[1]));
}
