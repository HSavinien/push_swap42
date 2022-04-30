/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:22:49 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/30 17:37:17 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "../push_swap.h"


//subject moves
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

#endif
