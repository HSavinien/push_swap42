/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:13:32 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/25 15:15:48 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_moves	*init_mvs(void)
{
	t_moves	*mvs;

	mvs = malloc(sizeof (t_moves));
	mvs->ra = 0;
	mvs->rb = 0;
	mvs->rr = 0;
	mvs->rra = 0;
	mvs->rrb = 0;
	mvs->rrr = 0;
	mvs->total = 0;
	return (mvs);
}

int	find_pos_in_stack(t_stack *element, t_stack *stk)
{
	int	i;

	i = 0;
	while (stk && stk != element)
	{
		stk = stk->next;
		i ++;
	}
	if (!stk)
		return (-1);
	return (i);
}

//return a positive number if the move is rotate, a  negative if it's rev_rotate
int	nb_mvs_to_top(t_stack *node, t_stack *stk)
{
	int	nb_mvs;
	int	pos;

	if (!node || !stk)
		return (0);
	pos = find_pos_in_stack(node, stk);
	nb_mvs = 0;
	if (pos <= (int)get_stack_len(stk) / 2)
	{
		while (pos --)
			nb_mvs ++;
	}
	else
	{
		while (pos ++ < (int)get_stack_len(stk))
			nb_mvs --;
	}
	return (nb_mvs);
}

void	do_good_rotate(t_stack **sa, t_stack **sb)
{
	t_stack	*last;

	last = stack_find_last(*sa);
	if(last->index < (*sa)->index)
		mv_rra(sa, sb);
}

void	do_moves(t_moves *mvs, t_stack **sa, t_stack **sb)
{
	while (mvs->ra -- > 0)
		mv_ra(sa, sb);
	while (mvs->rra -- > 0)
		mv_rra(sa, sb);
	while (mvs->rb -- > 0)
		mv_rb(sa, sb);
	while (mvs->rrb -- > 0)
		mv_rrb(sa, sb);
	while (mvs->rr -- > 0)
		mv_rr(sa, sb);
	while (mvs->rrr -- > 0)
		mv_rrr(sa, sb);
	mv_pa(sa, sb);
	if (!is_stack_sorted(*sa))
		do_good_rotate(sa, sb);
}
