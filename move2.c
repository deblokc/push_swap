/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:32:30 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 15:39:58 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info **info)
{
	(*info)->begin_a = (*info)->begin_a->next;
	(*info)->last_a = (*info)->last_a->next;
	addop(info, newop("ra"));
}

void	rb(t_info **info)
{
	if ((*info)->size_b > 1)
	{
		(*info)->begin_b = (*info)->begin_b->next;
		(*info)->last_b = (*info)->last_b->next;
		addop(info, newop("rb"));
	}
}

void	rra(t_info **info)
{
	(*info)->begin_a = (*info)->last_a;
	(*info)->last_a = (*info)->last_a->prev;
	addop(info, newop("rra"));
}

void	rrb(t_info **info)
{
	if ((*info)->size_b > 1)
	{
		(*info)->begin_b = (*info)->last_b;
		(*info)->last_b = (*info)->last_b->prev;
		addop(info, newop("rrb"));
	}
}

void	sa(t_info **info)
{
	t_list	*tmp;

	tmp = (*info)->begin_a;
	(*info)->begin_a = (*info)->begin_a->next;
	tmp->next = (*info)->begin_a->next;
	tmp->prev = (*info)->begin_a;
	(*info)->begin_a->next->prev = tmp;
	(*info)->begin_a->next = tmp;
	(*info)->begin_a->prev = (*info)->last_a;
	(*info)->last_a->next = (*info)->begin_a;
	addop(info, newop("sa"));
}
