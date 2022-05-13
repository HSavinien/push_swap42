/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_LIS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/13 20:41:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lis	*init_lis()
{
	t_lis	*lis;
	lis = malloc(sizeof (t_lis));
	lis->len = 0;

	return (lis);
}

t_lis	*get_lis(t_stack *stk)
{
	t_lis	*tmp_lis;
	t_lis	*final_lis;
	t_stack	*current;
	int		i;
	
	tmp = init_lis();
	final = init_lis();
	current = stk
	tmp->pos = 0;
	while (current)
	{
		i = 0;
		tmp->first_index = current->index;
		while ()
	}
}

void	lis_to_botom(t_stack **sa)
{
	
}

void	do_best_push(t_stack **sa, t_stack **sb)
{
	
}

void	sort_many(t_stack *sa, t_stack *sb)
{
	t_lis	*lis;
	lis = get_lis(sa);
	if (lis->len > 3)
	{
		lis_to_botom(lis, &sa);
		while (*sa->content != lis->first_val)
			mv_pb(&sa, &sb);
	}
	while (get_stack_len(sa) > 3 || (lis && lis->len > 3))
		mv_pb(&sa, &sb);


	while (get_stack_len(*sb))
		do_best_push(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
}
