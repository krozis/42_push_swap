/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:11 by krozis            #+#    #+#             */
/*   Updated: 2022/05/25 13:52:47 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_hundred(t_ps *ps)
{
	ps->chunk = 5;
	ps_chunker(ps);
	ps_display_chunks(ps);
	/*
	//1 - Division en 5 troncons
	
	//2.1 - Scan A de haut en bas

	//2.2 - Scan A de bas en haut

	//2.3 - Comparer pour savoir lequel est le plus proche

	//3 - Vider le troncon dans B en verifiant au fur a mesure que le
	//		troncon est trie dans B (ordre inverse = opti?)

	//4 - Idem pour chaque troncon

	//5 - rebasculer les troncons dans l'ordre
	*/
}
