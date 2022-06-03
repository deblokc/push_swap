/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:03:15 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 15:25:18 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	*newop(char *content)
{
	t_op	*new;

	new = (t_op *)malloc(sizeof(t_op) * 1);
	if (!new)
		return (NULL);
	new -> next = NULL;
	new -> prev = NULL;
	new -> content = content;
	return (new);
}

void	addop(t_info **info, t_op *new)
{
	if ((*info)->last_op)
	{
		new->prev = (*info)->last_op;
		(*info)->last_op->next = new;
	}
	else if (!(*info)->begin_op)
		(*info)->begin_op = new;
	(*info)->last_op = new;
}

void	printop(t_info **info)
{
	t_op	*current;

	current = (*info)->begin_op;
	if (current)
	{
		while (current != (*info)->last_op)
		{
			ft_putstr_fd(current->content, 1);
			ft_putchar_fd('\n', 1);
			current = current->next;
		}
		ft_putstr_fd(current->content, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	combinop(t_info **info)
{
	t_op	*current;
	t_op	*last;

	last = (*info)->last_op;
	current = (*info)->begin_op;
	while (current != (*info)->last_op)
	{
		if (!ft_strncmp(current->content, "ra", 3))
			ratorr(current, last);
		if (!ft_strncmp(current->content, "rb", 3))
			rbtorr(current, last);
		if (!ft_strncmp(current->content, "rra", 3))
			rratorrr(current, last);
		if (!ft_strncmp(current->content, "rrb", 3))
			rrbtorrr(current, last);
		if (!ft_strncmp(current->content, "rr", 3))
			xandx(current, last, "rr", "rrr");
		if (!ft_strncmp(current->content, "rrr", 3))
			xandx(current, last, "rrr", "rr");
		current = current->next;
	}
}
