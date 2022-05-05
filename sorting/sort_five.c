/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:24:11 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/05 20:34:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *sa, t_stack *sb)
{
	while (get_stack_len(sa) > 3)
		mv_pb(&sa, &sb);
	sort_three(sa, sb);
	//reinject, in the good position, the two value in sb;
	
}
