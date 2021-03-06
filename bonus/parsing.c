/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/04 20:27:53 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_value(char *content)
{
	int	i;

	if (content[0] != '-' && content[0] != '+' && !ft_isdigit(content[0]))
		error("parameter contain non-atoiable values");
	i = 1;
	while (content[i])
	{
		if (!ft_isdigit(content[i ++]))
			error("parameters must be numbers only");
	}
	if ((content[0] == '+' || content[0] == '-') && !content[1])
		error("after the unsigned int, the uninted sign? I don't think so...");
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

int	get_nb_word(char *s)
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
	if (!av[0])
		error("empty argument");
	return (av);
}

t_stack	*read_args(int ac, int base_ac, char **av)
{
	t_stack	*element;
	int		*seen;
	int		*new_val;

	av = get_true_av(&ac, av);
	element = NULL;
	seen = ft_calloc(sizeof(int), ac);
	while (-- ac >= 0)
	{
		check_value(av[ac]);
		if (value_in_tab(ft_atoi(av[ac]), seen))
			error("duplicated values in stack");
		if (ft_atoi(av[ac]) > INT_MAX || ft_atoi(av[ac]) < INT_MIN)
			error("some numbers doesn't fit in type int. try other value");
		new_val = malloc(sizeof (int));
		if (!new_val)
			error("unplaned malloc error");
		*new_val = ft_atoi(av[ac]);
		element = stack_add_front(element, new_val);
	}
	give_index(element);
	if (base_ac == 2)
		free_dbl_ptr((void **)av);
	return (stupid_norm_free(seen, element));
}
