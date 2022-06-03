/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:58:44 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:42:50 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sizeop(t_info **info)
{
	int		i;
	t_op	*current;

	i = 1;
	current = (*info)->begin_op;
	if (!current)
		return (0);
	while (current != (*info)->last_op)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	get_x(t_info **info, int prc)
{
	int		i;
	t_list	*current;

	current = (*info)->begin_a;
	i = ((*info)->size_a * prc) / 100;
	while (i--)
		current = current->next;
	return (current->content);
}

void	putx(t_info **info, int top, int bot)
{
	(*info)->tophalf = get_x(info, top);
	(*info)->bothalf = get_x(info, bot);
}

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

t_list	*getmin(t_list *list)
{
	t_list	*min;
	t_list	*current;
	t_list	*first;

	current = list;
	first = current;
	min = current;
	if (current && current->next)
		current = current->next;
	while (current && current != first)
	{
		if (min->content > current->content)
			min = current;
		current = current->next;
	}
	return (min);
}
