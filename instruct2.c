/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:21:27 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 18:42:39 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ratorr(t_op *current, t_op *last)
{
	t_op	*tmp;

	tmp = current;
	while (!ft_strncmp(tmp->content, "ra", 3) && tmp != last)
		tmp = tmp->next;
	if (!ft_strncmp(tmp->content, "rb", 3))
	{
		current->content = "rr";
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
	}
}

void	rbtorr(t_op *current, t_op *last)
{
	t_op	*tmp;

	tmp = current;
	while (!ft_strncmp(tmp->content, "rb", 3) && tmp != last)
		tmp = tmp->next;
	if (!ft_strncmp(tmp->content, "ra", 3))
	{
		current->content = "rr";
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
	}
}

void	rratorrr(t_op *current, t_op *last)
{
	t_op	*tmp;

	tmp = current;
	while (!ft_strncmp(tmp->content, "rra", 3) && tmp != last)
		tmp = tmp->next;
	if (!ft_strncmp(tmp->content, "rrb", 3))
	{
		current->content = "rrr";
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
	}
}

void	rrbtorrr(t_op *current, t_op *last)
{
	t_op	*tmp;

	tmp = current;
	while (!ft_strncmp(tmp->content, "rrb", 3) && tmp != last)
		tmp = tmp->next;
	if (!ft_strncmp(tmp->content, "rra", 3))
	{
		current->content = "rrr";
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
	}
}

void	xandx(t_op *current, t_op *last, char *s1, char *s2)
{
	t_op	*tmp;

	tmp = current;
	while (!ft_strncmp(tmp->content, s1, 3) && tmp != last)
		tmp = tmp->prev;
	if (!ft_strncmp(tmp->content, s2, 3))
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		free(current);
	}
}
