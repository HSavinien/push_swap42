/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:31:20 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/29 14:27:06 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//analize the input and call the best algo depending on the number list. for now, it mostly discriminate between short/long array
void	do_sorting(stack *sa, stack *sb)
{
	if (is_stack_sorted(sa))
		exit(0);
	if (get_stack_len(sa) )
}
