/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:01:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/22 21:57:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_add_front(t_stack *stack, char *content)
{
	t_stack	*new;
	int		val;

	new = malloc(sizeof(t_stack));
	if (!content)
		new->content = NULL;
	else
	{
		val = ft_atoi(content);
		new->content = memcpy(malloc(sizeof(int)), &val, sizeof(int));
	}
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
