/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/03 22:50:54 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	do_rev_rotate(t_stack *src)
{
	
}

void	mv_rra(t_stack *sa, t_stack *sb)
{
	do_rev_rotate(sa);
	ft_printf("rra\n");
	(void) sb;
}
void	mv_rrb(t_stack *sa, t_stack *sb)
{
	do_rev_rotate(sb);
	ft_printf("rrb\n");
	(void) sa;
}
void	mv_rrr(t_stack *sa, t_stack *sb)
{
	do_rev_rotate(sa);
	do_rev_rotate(sb);
	ft_printf("rrr\n");
}
