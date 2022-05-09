/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:24:11 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/09 21:25:25 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_smallest(t_stack *stk)
{
	int		smallest;
	int		pos;
	int		i;

	if (!stk)
		return (- 1);
	pos = 0;
	i = 0;
	smallest = *stk->content;
	while (stk)
	{
		if (*stk->content < smallest)
		{
			smallest = *stk->content;
			pos = i;
		}
		i ++;
		stk = stk->next;
	}
	return (pos);
}

void	push_smallest(t_stack **sa, t_stack **sb)
{
	int	smallest_pos;

	smallest_pos = find_smallest(*sa);
	if ((size_t) smallest_pos < get_stack_len(*sa) / 2)
		while (smallest_pos --)
			mv_ra(sa, sb);
	else
		while (smallest_pos --)
			mv_rra(sa, sb);
	mv_pb(sa, sb);
	
}

void	sort_five(t_stack *sa, t_stack *sb)
{
	while (get_stack_len(sa) > 3)
	push_smallest(&sa, &sb);
	sort_three(sa, sb);
	mv_pa(&sa, &sb);
	mv_pa(&sa, &sb);
	show_stack(sa);//debug
}
