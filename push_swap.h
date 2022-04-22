/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:53:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/22 21:17:40 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
#include <stdio.h>//============================================================DEBUG
# include "library/libft/libft.h"
# include "library/printf/lib_printf.h"

//structures    --------------------------------------------------    structures

typedef struct s_stack {
	int				content;
	struct s_stack	*next;
}t_stack;

//functions    ====================================================    functions

//parsing    --------------------------------------------------------    parsing

t_stack	*read_args(int ac, char **av);
void	check_value(char *content);
int		value_in_tab(int val, int *tab);
t_stack	*build_stack_b(size_t len);

//utils    ------------------------------------------------------------    utils

t_stack	*stack_add_front(t_stack *stack, char *content);
size_t	get_stack_len(t_stack *s);

//sorting general    ----------------------------------------    sorting general

void	do_sorting(t_stack *stack_a, t_stack *stack_b);

//exit    --------------------------------------------------------------    exit

int		error(char *msg);

//debug    ------------------------------------------------------------    debug

int		show_stack(t_stack *stack);
#endif
