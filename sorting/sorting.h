/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:20:53 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/29 20:09:20 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "../push_swap.h"

//structures    --------------------------------------------------    structures

typedef struct s_lss {
	int		len;
	int		pos_num;
	int		first_val;
	int		last_val;
	t_stack	*pos;
}	t_lss;

void	do_sorting(t_stack sa, t_stack sb);



#endif
