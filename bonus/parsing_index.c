/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:31:31 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 08:46:41 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*find_next_smallest(t_stack *stk)
{
	t_stack	*smallest_found;

	smallest_found = stk;
	while (smallest_found->index)
		smallest_found = smallest_found->next;
	while (stk)
	{
		if (*smallest_found->content > *stk->content && !stk->index)
			smallest_found = stk;
		stk = stk->next;
	}
	return (smallest_found);
}

void	give_index(t_stack *stk)
{
	t_stack	*curent;
	int		index;
	int		len;

	len = get_stack_len(stk);
	index = 1;
	while (index <= len)
	{
		curent = find_next_smallest(stk);
		curent->index = index;
		index ++;
	}
}
