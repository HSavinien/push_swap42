/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/20 21:26:00 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_value(char *content)
{
	if(content[0] != '-' && content[0] != '+' && !ft_isdigit(content[0]))
		error("parameter contain non-atoiable values");
}

int		value_in_tab(int val, int *tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		if (tab[i] == val)
			return (1);
		i ++;
	}
	return (0);
}

t_stack	*stack_add_front(t_stack *stack, char* content)
{
	t_stack	*new;

	check_value(content);
	new = malloc(sizeof(t_stack));
	new->content = ft_atoi(content);
	new->next = stack;
	return (new);
}

t_stack	*read_args(int ac, char **av)
{
	t_stack	*element;
	int *values;

	element = NULL;
	values = malloc(sizeof (int) * ac);
	ft_bzeros(values, ac * sizeof (int));
	ac --;
	while (ac)
	{
		element = stack_add_front(element, av[ac]);
		if (value_in_tab(element->content, i))
			error("arguments contain duplicated values");
		ac --
	}
	if 
	return (element);
}
