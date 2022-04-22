/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:09 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/22 21:59:13 by tmongell         ###   ########.fr       */
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
			printf("%d | ", *stack->content);
		else
			printf("(null) | ");
		stack = stack->next;
		i ++;
	}
	printf("\n");
	return (i);
}
