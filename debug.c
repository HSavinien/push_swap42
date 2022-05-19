/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 03:59:19 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	show_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content)
			printf("\033[1m%d\033[0m(%d) | ", *stack->content, stack->index);
		else
			printf("(null) | ");
		stack = stack->next;
		i ++;
	}
	printf("\n");
	return (i);
}

void	test_push(t_stack *sa, t_stack *sb)
{
	mv_pb(&sa, &sb);
	mv_pb(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
	mv_pa(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
	mv_pa(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
}

void	test_swap(t_stack *sa, t_stack *sb)
{
	mv_sa(&sa, &sb);
	mv_sb(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
	mv_ss(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
}

void	test_rotate(t_stack *sa, t_stack *sb)
{
	mv_ra(&sa, &sb);
	show_stack(sa);
	mv_rb(&sa, &sb);
	show_stack(sb);
	mv_rr(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
	mv_rra(&sa, &sb);
	show_stack(sa);
	mv_rrb(&sa, &sb);
	show_stack(sb);
	mv_rrr(&sa, &sb);
	show_stack(sa);
	show_stack(sb);
}

void	test_moves(t_stack *sa, t_stack *sb)
{
	printf("\033[1;4mtesting push function :\033[0m \n\n");
	test_push(sa, sb);
	printf("\033[1;4mtesting swap function :\033[0m \n\n");
	test_swap(sa, sb);
	printf("\033[1;4mtesting rotate function :\033[0m \n\n");
	test_rotate(sa, sb);
}
