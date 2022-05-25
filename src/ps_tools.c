/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:10 by krozis            #+#    #+#             */
/*   Updated: 2022/05/25 13:53:11 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	ps_get_closest(t_ps	*ps);

void	ps_chunker(t_ps *ps)
{
	int	i;
	int	max_in_chunk;

	i = 0;
	max_in_chunk = 0;
	while (i < ps->chunk)
	{
		max_in_chunk += ps->len / ps->chunk;
		ps->lmt[i] = max_in_chunk;
		i++;
	}
}
