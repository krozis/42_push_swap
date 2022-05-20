/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:31:48 by krozis            #+#    #+#             */
/*   Updated: 2022/05/20 13:09:06 by krozis           ###   ########.fr       */
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
	int	in_a;
	int	in_b;
}				t_ps;

/*
	FUNCTIONS: debug
*/
void	ps_display_tab(t_ps *ps);
void	ps_display_rel_tab(t_ps *ps);

/*
	FUNCTIONS: init
*/
int		ps_clean_tab(t_ps *ps);
int		ps_fill_tab_a(t_ps *ps, int ac, char **av);
int		ps_wrong_elem(char *elem);

/*
	FUNCTIONS: moves
*/
void	ps_mini_swap(int *a, int *b);
void	ps_push_a(t_ps *ps);
void	ps_push_b(t_ps *ps);
void	ps_swap_a(t_ps *ps);
void	ps_swap_b(t_ps *ps);
void	ps_rotate_a(t_ps *ps);
void	ps_rotate_b(t_ps *ps);
void	ps_rrotate_a(t_ps *ps);
void	ps_rrotate_b(t_ps *ps);

#endif
