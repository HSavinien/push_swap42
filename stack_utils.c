/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:27 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/25 20:41:51 by tmongell         ###   ########.fr       */
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
	new->next = stack;
	return (new);
}

size_t	get_stack_len(t_stack *s)
{
	int i;

	i = 0;
	while(s)
	{
		s = s->next;
		i ++;
	}
	return (i);
}
