/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/02 18:53:33 by tmongell         ###   ########.fr       */
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

int		get_nb_word(char *s)
{
	int	i;
	int	nb_str;

	if (ft_strlen(s) == 0)
		return (0);
	i = 1;
	nb_str = 1;
	while (s[i])
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i - 1]))
			nb_str ++;
		i ++;
	}
	if (ft_isspace(s[i - 1]))
		nb_str --;
	return (nb_str);
}

char	**get_true_av(int *ac, char **av)
{
	if (*ac > 2)
	{
		-- *ac;
		return (av + 1);
	}
	*ac = get_nb_word(av[1]);
	av = ft_split_word(av[1]);
	return (av);
}

t_stack	*read_args(int ac, char **av)
{
	t_stack	*element;
	int		*seen;
	int		*new_val;

	av = get_true_av(&ac, av);
	element = NULL;
	seen = malloc(sizeof(int) * ac);
	ft_bzero(seen, ac * sizeof (int));
	ac --;
	while (ac >= 0)
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
