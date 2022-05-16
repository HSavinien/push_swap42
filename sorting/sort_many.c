/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/13 20:41:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_best_push(t_stack **sa, t_stack **sb)
{
	
}

void	sort_many(t_stack *sa, t_stack *sb)
{
	while (get_stack_len(sa) > 3)
		mv_pb(&sa, &sb);
	while (get_stack_len(*sb))
		do_best_push(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
}
