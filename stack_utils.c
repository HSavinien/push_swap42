/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:27 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/31 14:38:40 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_add_front(t_stack *stack, int *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error("unplaned malloc error");
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->index = 0;
	new->next = stack;
	return (new);
}

size_t	get_stack_len(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i ++;
	}
	return (i);
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

t_stack	*stack_find_last(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

t_stack	*copy_stack(t_stack *src)
{
	t_stack	*cpy;
	t_stack	*last;

	cpy = malloc(sizeof (t_stack));
	if (!cpy)
		error("unexpected malloc error");
	last = cpy;
	while (src->next)
	{
		last->content = src->content;
		last->index = src->index;
		last->next = malloc(sizeof(t_stack));
		last = last->next;
		src = src->next;
	}
	last->content = src->content;
	last->index = src->index;
	last->next=NULL;
	return (cpy);
}
