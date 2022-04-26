/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/25 20:42:35 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*build_stack_b(size_t len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (len --)
		stack_b = stack_add_front(stack_b, 0);
	return (stack_b);
}

void	check_value(char *content)
{
	if (content[0] != '-' && content[0] != '+' && !ft_isdigit(content[0]))
		error("parameter contain non-atoiable values");
}

int	value_in_tab(int val, int *tab)
{
	int			i;
	static int	nb_zero;

	i = 0;
	if (!val)
		nb_zero ++;
	if (nb_zero > 1)
		return (1);
	while (tab[i])
	{
		if (tab[i] == val)
			return (1);
		i ++;
	}
	tab[i] = val;
	return (0);
}

t_stack	*read_args(int ac, char **av)
{
	t_stack	*element;
	int		*seen;
	int		*new_val;

	element = NULL;
	seen = malloc(sizeof(int) * ac);
	ft_bzero(seen, ac * sizeof (int));
	ac --;
	while (ac)
	{
		check_value(av[ac]);
		if (value_in_tab(ft_atoi(av[ac]), seen))
			error("duplicated values in stack");
		if ((int)ft_atoi(av[ac]) != ft_atoi(av[ac]))
			error("some numbers doesn't fit in type int. try other value");
		new_val = malloc(sizeof (int));
		if (!new_val)
			error("unplaned malloc error");
		*new_val = ft_atoi(av[ac]);
		element = stack_add_front(element, new_val);
		ac --;
	}
	return (element);
}
