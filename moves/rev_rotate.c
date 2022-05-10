/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:20:16 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/10 17:06:56 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*stack_get_penultimate(t_stack *s)
{
	while (s->next->next)
		s = s->next;
	return (s);
}

void	do_rev_rotate(t_stack **src)
{
	t_stack	*tmp;

	tmp = stack_get_penultimate(*src);
	tmp->next->next = *src;
	*src = tmp->next;
	tmp->next = NULL;
}

void	mv_rra(t_stack **sa, t_stack **sb)
{
	do_rev_rotate(sa);
	write(1, "rra\n", 4);
	(void) sb;
}

void	mv_rrb(t_stack **sa, t_stack **sb)
{
	do_rev_rotate(sb);
	write(1, "rrb\n", 4);
	(void) sa;
}

void	mv_rrr(t_stack **sa, t_stack **sb)
{
	do_rev_rotate(sa);
	do_rev_rotate(sb);
	ft_printf("rra\n");
}
