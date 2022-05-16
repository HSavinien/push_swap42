/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/16 21:09:25 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_moves	*find_best_moves(t_stack *sa, t_stack *sb)
{
	
}

void	sort_many(t_stack *sa, t_stack *sb)
{
	t_moves	*mvs;
	while (get_stack_len(sa) > 3)
		mv_pb(&sa, &sb);
	while (*sb)
	{
		mvs = find_best_moves(sa, sb);
		do_mvs(mvs, &sa, &sb);
	}
	show_stack(sa);
	show_stack(sb);
}


/*
do best push :
find best move
do move


find best move :
current = sb;
while current node :
	tmp_mvs = count_moves(current, sa, sb)
	optimise_mv()
	if tmp_moves->total < true_moves
		swap_ptr(true_moves, tmp_moves)	
	free(tmp_moves)
	current = curent->next;
return true_moves

