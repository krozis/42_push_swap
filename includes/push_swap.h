/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:31:48 by krozis            #+#    #+#             */
/*   Updated: 2022/05/17 17:48:17 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define PS_ERR_MSG "Error\n"

typedef struct s_ps
{
	int	*tab_a;
	int	*tab_b;
	int	len;
}				t_ps;

/*
	FUNCTIONS: debug
*/
void	ps_display_tab(t_ps *ps);

/*
	FUNCTIONS: init
*/
int		ps_clean_tab(t_ps *ps);
int		ps_fill_tab_a(t_ps *ps, int ac, char **av);
int		ps_wrong_elem(char *elem);

#endif
