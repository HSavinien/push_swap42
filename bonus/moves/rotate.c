/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 10:58:14 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_rotate(t_stack **src)
{
	t_stack	*last;

	if (!*src || !(*src)->next)
		return;
	last = stack_find_last(*src);
	last->next = *src;
	*src = (*src)->next;
	last->next->next = NULL;
}

void	mv_ra(t_stack **sa, t_stack **sb)
{
	do_rotate(sa);
	(void) sb;
}

void	mv_rb(t_stack **sa, t_stack **sb)
{
	do_rotate(sb);
	(void) sa;
}

void	mv_rr(t_stack **sa, t_stack **sb)
{
	do_rotate(sa);
	do_rotate(sb);
}
