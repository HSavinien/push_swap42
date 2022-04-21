/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:53:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/21 21:18:10 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
#include <stdio.h>//============================================================DEBUG
#include "library/libft/libft.h"
#include "library/printf/lib_printf.h"

//structures    --------------------------------------------------    structures

typedef struct	s_stack {
	int				content;
	struct s_stack	*next;
} t_stack;

//functions    ====================================================    functions

//parsing    --------------------------------------------------------    parsing

t_stack	*read_args(int ac, char **av);
void	check_value(char *content);
int		value_in_tab(int val, int *tab);
void	check_duplicate(int ac, char **av);

//utils    ------------------------------------------------------------    utils
t_stack	*stack_add_front(t_stack *stack, char *content);

//exit    --------------------------------------------------------------    exit

int error(char *msg);

//debug    ------------------------------------------------------------    debug

int	show_stack(t_stack *stack);
#endif
