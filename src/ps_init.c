/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ps_init.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: stelie <stelie@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/17 16:54:17 by stelie			#+#	#+#			 */
/*   Updated: 2022/05/17 17:49:47 by stelie		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	ps_clean_tab(t_ps *ps)
{
	if (ps->tab_a == NULL)
		free(ps->tab_a);
	if (ps->tab_b == NULL)
		free(ps->tab_b);
	return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}

int	ps_fill_tab_a(t_ps *ps, int ac, char **av)
{
	int	i;

	i = 1;
	ps->len = ac - 1;
	ps->tab_a = malloc(sizeof(int) * (ps->len));
	ps->tab_b = malloc(sizeof(int) * (ps->len));
	if (ps->tab_a == NULL || ps->tab_b == NULL)
		return (ps_clean_tab(ps));
	while (i < ac)
	{
		if (ps_wrong_elem(av[i]) == EXIT_FAILURE)
			return (ps_clean_tab(ps));
		else if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (ps_clean_tab(ps));
		ps->tab_a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (ft_hasdouble(ps->tab_a, ps->len))
		return (ps_clean_tab(ps));
	return (EXIT_SUCCESS);
}
