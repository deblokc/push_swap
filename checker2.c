/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:02:59 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 12:51:19 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_size(t_list *list)
{
	int		i;
	t_list	*current;

	i = 0;
	current = list;
	if (current->next)
	{
		while (current)
		{
			current = current->next;
			i++;
		}
		return (i);
	}
	return (1);
}

int	inlist(t_list *list, long long tmp)
{
	while (list)
	{
		if (list->content == tmp)
			return (1);
		list = list->next;
	}
	return (0);
}

int	checkarg(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (j == 0)
		{
			if (str[j] == '-')
			{
				if (!str[j])
					return (1);
				else
					j++;
			}
		}
		if (!ft_isdigit(str[j]))
			return (1);
		j++;
	}
	if (j == 0)
		return (1);
	return (0);
}

int	checkop(char *op)
{
	if (!ft_strncmp(op, "ra\n", 4))
		return (1);
	if (!ft_strncmp(op, "rb\n", 4))
		return (1);
	if (!ft_strncmp(op, "rra\n", 4))
		return (1);
	if (!ft_strncmp(op, "rrb\n", 4))
		return (1);
	if (!ft_strncmp(op, "rr\n", 4))
		return (1);
	if (!ft_strncmp(op, "rrr\n", 4))
		return (1);
	if (!ft_strncmp(op, "pa\n", 4))
		return (1);
	if (!ft_strncmp(op, "pb\n", 4))
		return (1);
	if (!ft_strncmp(op, "sa\n", 4))
		return (1);
	if (!ft_strncmp(op, "sb\n", 4))
		return (1);
	if (!ft_strncmp(op, "ss\n", 4))
		return (1);
	return (0);
}

int	checkint(int ac, char **av, t_list **list)
{
	long long	tmp;

	while (--ac > 0)
	{
		if (checkarg(av[ac]))
			return (0);
		tmp = ft_atoi(av[ac]);
		if (tmp < -2147483648 || tmp > 2147483647 || inlist(*list, tmp))
			return (0);
		else
			ft_lstadd_front(list, ft_lstnew(tmp));
	}
	return (1);
}
