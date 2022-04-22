/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:01:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/22 20:53:35 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_add_front(t_stack *stack, char *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->content = ft_atoi(content);
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
