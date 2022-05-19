/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:54:43 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 11:28:08 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_push(t_stack **src, t_stack **dst)
{
	t_stack	*save;

	if (!*src)
		return;
	save = *src;
	*src = (*src)->next;
	save->next = *dst;
	*dst = save;
}

void	mv_pa(t_stack **sa, t_stack **sb)
{
	do_push(sb, sa);
}

void	mv_pb(t_stack **sa, t_stack **sb)
{
	do_push(sa, sb);
}
