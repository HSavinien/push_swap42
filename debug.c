/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/03 18:36:52 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	show_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content)
			ft_printf("\033[1m%d\033[0m(%d) | ", stack->index, *stack->content);
		else
			ft_printf("(null) | ");
		stack = stack->next;
		i ++;
	}
	ft_printf("\n");
	return (i);
}

void	show_both_stack(t_stack *sa, t_stack *sb, char *msg)
{
	ft_printf("%s\n", msg);
	ft_printf("sa : ");
	show_stack(sa);
	ft_printf("sb : ");
	show_stack(sb);
}

int	get_integrity_code(t_stack	*stk)
{
	int	integrity;

	integrity = 0;
	while (stk)
	{
		integrity += *(stk->content) * stk->index;
		stk = stk->next;
	}
	return (integrity);
}
