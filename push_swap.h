/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:53:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/02 14:02:33 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
#include <stdio.h>//============================================================DEBUG

# include "library/libft/libft.h"
# include "library/printf/lib_printf.h"
//# include "sorting/sorting.h"
//# include "moves/moves.h"

//structures    ==================================================    structures

typedef struct s_stack {
	int				*content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lss {
	int		len;
	int		pos_num;
	int		first_val;
	int		last_val;
	t_stack	*pos;
}	t_lss;

//functions    ====================================================    functions

//parsing    --------------------------------------------------------    parsing

t_stack	*read_args(int ac, char **av);
void	check_value(char *content);
int		value_in_tab(int val, int *tab);
t_stack	*build_stack_b(size_t len);

//utils    ------------------------------------------------------------    utils

t_stack	*stack_add_front(t_stack *stack, int *content);
size_t	get_stack_len(t_stack *s);
int		is_stack_sorted(t_stack *stack);

//sorting general    ----------------------------------------    sorting general

void	do_sorting(t_stack *sa, t_stack *sb);

//sorting utils    --------------------------------------------    sorting utils

//movements    ----------------------------------------------------    movements
//subject functions
int	mv_sa(t_stack *sa, t_stack *sb);
int	mv_sb(t_stack *sa, t_stack *sb);
int	mv_ss(t_stack *sa, t_stack *sb);
int	mv_pa(t_stack *sa, t_stack *sb);
int	mv_pb(t_stack *sa, t_stack *sb);
int	mv_ra(t_stack *sa, t_stack *sb);
int	mv_rb(t_stack *sa, t_stack *sb);
int	mv_rr(t_stack *sa, t_stack *sb);
int	mv_rra(t_stack *sa, t_stack *sb);
int	mv_rrb(t_stack *sa, t_stack *sb);
int	mv_rrr(t_stack *sa, t_stack *sb);
//utils
void	do_swap(t_stack *src);
void	do_push(t_stack *src, t_stack *dst);
void	do_rotate(t_stack *src);
void	do_rev_rotate(t_stack *src);

//exit    --------------------------------------------------------------    exit

int		error(char *msg);

//debug    ------------------------------------------------------------    debug

int		show_stack(t_stack *stack);

#endif
