/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:53:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/04 20:23:11 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>//===========================================================DEBUG
# include <limits.h>

# include "library/libft/libft.h"
# include "library/printf/libftprintf.h"

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

t_stack	*read_args(int ac, int base_ac, char **av);
void	check_value(char *content);
int		value_in_tab(int val, int *tab);
void	give_index(t_stack *stk);
t_stack	*stupid_norm_free(int *seen, t_stack *stk);

//utils    ------------------------------------------------------------    utils
//general
void	ft_swap(int *a, int *b);
void	ft_swap_ptr(void **a, void **b);
void	free_dbl_ptr(void	**tab);
//stack
t_stack	*stack_add_front(t_stack *stack, int *content);
size_t	get_stack_len(t_stack *s);
int		is_stack_sorted(t_stack *stack);
t_stack	*stack_find_last(t_stack *s);
void	destroy_stack(t_stack *stk);
void	destroy_main_stack(t_stack *stk);
t_stack	*copy_stack(t_stack *src);

//sorting    --------------------------------------------------------    sorting
//general
void	do_sorting(t_stack *sa, t_stack *sb);
void	sort_five(t_stack *sa, t_stack *sb);
t_stack	*sort_three(t_stack *sa, t_stack *sb);
void	sort_many(t_stack *sa, t_stack *sb);

//utils
int		find_smallest(const t_stack *stk);
t_moves	*init_mvs(void);
int		find_pos_in_stack(t_stack *element, t_stack *stk);
void	do_moves(t_moves *mvs, t_stack **stk, t_stack **sb);
int		nb_mvs_to_top(t_stack *node, t_stack *stk);
void	do_final_rotate(t_stack **sa, t_stack **sb);

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

int		show_stack(t_stack *stack);
void	show_both_stack(t_stack *sa, t_stack *sb, char *msg);
int		get_integrity_code(t_stack	*stk);

#endif
