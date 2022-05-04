/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:01:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/04 00:01:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*a = *a - *b;
	*b = *a - *b;
}

void	ft_swap_ptr(void **a, void **b)
{
	void	*c;
	c = *a;
	*a = *b;
	*b = c;
}

int	is_stack_sorted(t_stack *stack)
{
	int	nb;
	nb = *stack->content;
	stack = stack->next;
	while (stack && stack->content)
	{
		if (*stack->content < nb)
			return (0);
		nb = *stack->content;
		stack = stack->next;
	}
	return (1);
}
