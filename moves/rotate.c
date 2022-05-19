/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 03:53:33 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_stack **src)
{
	t_stack	*last;

	last = stack_find_last(*src);
	last->next = *src;
	*src = (*src)->next;
	last->next->next = NULL;
}

void	mv_ra(t_stack **sa, t_stack **sb)
{
	do_rotate(sa);
	write(1, "ra\n", 3);
	(void) sb;
}

void	mv_rb(t_stack **sa, t_stack **sb)
{
	do_rotate(sb);
	write(1, "rb\n", 3);
	(void) sa;
}

void	mv_rr(t_stack **sa, t_stack **sb)
{
	do_rotate(sa);
	do_rotate(sb);
	write(1, "rr\n", 3);
}
