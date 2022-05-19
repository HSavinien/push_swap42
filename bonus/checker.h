/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:07:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 10:46:23 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>//======================================================DEBUG
# include <limits.h>

# include "../library/libft/libft.h"
# include "../library/printf/lib_printf.h"

//structures    ==================================================    structures

typedef struct s_stack {
	int				*content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lis {
	int		len;
	int		pos_num;
	int		first_index;
	int		last_index;
	t_stack	*pos;
}	t_lis;

typedef struct s_moves {
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_moves;

//functions    ====================================================    functions

//parsing    --------------------------------------------------------    parsing

t_stack	*read_args(int ac, char **av);
void	check_value(char *content);
int		value_in_tab(int val, int *tab);
void	give_index(t_stack *stk);

//utils    ------------------------------------------------------------    utils
//general
void	ft_swap(int *a, int *b);
void	ft_swap_ptr(void **a, void **b);
//stack
t_stack	*stack_add_front(t_stack *stack, int *content);
size_t	get_stack_len(t_stack *s);
int		is_stack_sorted(t_stack *stack);
t_stack	*stack_find_last(t_stack *s);

//movements    ----------------------------------------------------    movements
//subject functions
void	mv_sa(t_stack **sa, t_stack **sb);
void	mv_sb(t_stack **sa, t_stack **sb);
void	mv_ss(t_stack **sa, t_stack **sb);
void	mv_pa(t_stack **sa, t_stack **sb);
void	mv_pb(t_stack **sa, t_stack **sb);
void	mv_ra(t_stack **sa, t_stack **sb);
void	mv_rb(t_stack **sa, t_stack **sb);
void	mv_rr(t_stack **sa, t_stack **sb);
void	mv_rra(t_stack **sa, t_stack **sb);
void	mv_rrb(t_stack **sa, t_stack **sb);
void	mv_rrr(t_stack **sa, t_stack **sb);
//utils
void	do_swap(t_stack **src);
void	do_push(t_stack **src, t_stack **dst);
void	do_rotate(t_stack **src);
void	do_rev_rotate(t_stack **src);

//exit    --------------------------------------------------------------    exit

int		error(char *msg);

//debug    ------------------------------------------------------------    debug

int	show_stack(t_stack *sack);
#endif
