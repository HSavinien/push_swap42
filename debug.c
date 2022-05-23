/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/20 14:58:46 by tmongell         ###   ########.fr       */
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
