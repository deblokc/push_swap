/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:47:43 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:54:09 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getstreak(t_list *current)
{
	while (current->streak == -1)
		current = current->next;
	return (current->content);
}

int	getprevstreak(t_list *current)
{
	while (current->streak == -1)
		current = current->prev;
	return (current->content);
}

void	sanpb(t_info **info, t_list *current)
{
	if (current->next->streak != -1
		&& current->content > current->next->content
		&& current->content < getstreak(current->next->next))
	{
		current->streak = 1;
		sa(info);
	}
	else
		pb(info);
	(*info)->disorder--;
}

void	sanra(t_info **info, t_list *current)
{
	if (current->next->streak == -1
		&& current->next->content < current->content
		&& current->next->content > getprevstreak(current->prev))
	{
		current->next->streak = 1;
		sa(info);
		(*info)->disorder--;
	}
	else
		ra(info);
}

void	tri(t_info **info, int i)
{
	t_list	*current;
	int		*min;

	min = NULL;
	current = (*info)->begin_a;
	while ((*info)->disorder)
	{
		dostreak(info, current);
		current = (*info)->begin_a;
	}
	while ((*info)->size_b)
	{
		if ((current->content > (*info)->begin_b->content
				|| current == (*info)->min)
			&& current->prev->content < (*info)->begin_b->content)
			pa(info);
		min = getrotation(info, i);
		dorotate(info, min);
		current = (*info)->begin_a;
		if (min)
			free(min);
	}
	rotate(info);
}
