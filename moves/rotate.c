/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/03 22:49:31 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	do_rotate(t_stack *src)
{
	
}

void	mv_ra(t_stack *sa, t_stack *sb)
{
	do_rotate(sa);
	ft_printf("ra\n");
	(void) sb;
}
void	mv_rb(t_stack *sa, t_stack *sb)
{
	do_rotate(sb);
	ft_printf("rb\n");
	(void) sa;
}
void	mv_rr(t_stack *sa, t_stack *sb)
{
	do_rotate(sa);
	do_rotate(sb);
	ft_printf("rr\n");
}
