/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/02 15:26:23 by tmongell         ###   ########.fr       */
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
			printf("\033[1m%d\033[0m(%d) | ", stack->index, *stack->content);
		else
			printf("(null) | ");
		stack = stack->next;
		i ++;
	}
	printf("\n");
	return (i);
}

void	show_both_stack(t_stack *sa, t_stack *sb, char *msg)
{
	printf("%s\n", msg);
	printf("sa : ");
	show_stack(sa);
	printf("sb : ");
	show_stack(sb);
}
