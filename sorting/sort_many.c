/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/17 15:16:30 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_moves	*optimise_mv(t_moves *mvs)
{

}

static t_moves	*count_moves(t_stack *node, t_stack *sa, t_stack *sb)
{
	t_moves	*mvs;
	
	mvs = init_mvs();
	





	return(optimise_mv(mvs));
}

static t_moves	*find_best_moves(t_stack *sa, t_stack *sb)
{
	t_stack	*curent;
	t_moves	*tmp_mvs;
	t_moves	*true_mvs;
	
	true_mvs = count_moves(current, sa, sb);
	curent = sb->next;
	while(current)
	{
		tmp_mvs = count_moves(current, sa, sb);
		if (tmp_mvs->total < true_mvs)
			ft_swap_ptr(true_mvs, tmp_mvs);
		free(tmp_mvs);
		current = current->next;
	}
	return (true_mvs);
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

find best move :
current = sb;
while current node :
	tmp_mvs = count_moves(current, sa, sb)
	optimise_mv()
	if tmp_moves->total < true_mvs
		swap_ptr(true_mvs, tmp_mvs)	
	free(tmp_moves)
	current = curent->next;
return true_moves



count_moves : 



*/
