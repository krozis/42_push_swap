/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:31:48 by krozis            #+#    #+#             */
/*   Updated: 2022/05/26 20:05:41 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define PS_ERR_MSG "Error\n"
# define GOOD 0
# define FAIL 1
# define INCREASING 1
# define DECREASING 0

typedef struct s_ps
{
	int	*tab_a;
	int	*idx_a;
	int	*tab_b;
	int	*idx_b;
	int	len;
	int	in_a;
	int	in_b;
	int	chunk;
	int	*lmt;
}				t_ps;

/*
	FUNCTIONS: debug
*/
void	ps_display_all_tabs(t_ps *ps);
void	ps_display_rel_tab(t_ps *ps);
void	ps_display_chunks(t_ps *ps);

/*
	FUNCTIONS: main
*/
int		ps_malloc(t_ps *ps);
int		ps_clean_tab(t_ps *ps, t_bool success);
int		ps_fill_tab_a(t_ps *ps, int ac, char **av);
void	ps_sort_3(t_ps *ps);
void	ps_sort_5(t_ps *ps);
void	ps_sort_hundred(t_ps *ps);
void	ps_sort_max(t_ps *ps);

/*
	FUNCTIONS: tools
*/
void	ps_resort_chunk(t_ps *ps, int chunk);
void	ps_push_back(t_ps *ps);
t_bool	ps_is_in_chunk(t_ps *ps, int nb, int chunk);
void	ps_chunker(t_ps *ps);
int		ps_get_closest(t_ps	*ps, int chunk);

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
