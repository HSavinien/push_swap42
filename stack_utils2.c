/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:40:53 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/04 20:18:20 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	destroy_stack(t_stack *stk)
{
	t_stack	*next;

	while (stk)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
}

void	destroy_main_stack(t_stack *stk)
{
	t_stack	*next;

	while (stk)
	{
		next = stk->next;
		free(stk->content);
		free(stk);
		stk = next;
	}
}
