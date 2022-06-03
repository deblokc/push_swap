/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:11:14 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 15:41:42 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_info **info)
{
	t_list	*tmp;

	tmp = (*info)->begin_b;
	(*info)->begin_b = (*info)->begin_b->next;
	if ((*info)->size_b > 2)
		tmp->next = (*info)->begin_b->next;
	else
	{
		tmp->next = (*info)->begin_b;
		(*info)->last_b = tmp;
	}
	(*info)->begin_b->next = tmp;
	(*info)->begin_b->prev = (*info)->last_b;
	(*info)->last_b->next = (*info)->begin_b;
	addop(info, newop("sb"));
}

void	pa2(t_info **info, t_list *tmpa)
{
	if (tmpa)
	{
		(*info)->begin_a->next = tmpa;
		(*info)->begin_a->next->prev = (*info)->begin_a;
		(*info)->begin_a->prev = (*info)->last_a;
		(*info)->last_a->next = (*info)->begin_a;
	}
	else
	{
		(*info)->begin_a->next = (*info)->begin_a;
		(*info)->begin_a->next->prev = (*info)->begin_b;
		(*info)->begin_a->prev = (*info)->begin_a;
		(*info)->last_a = (*info)->begin_a;
	}
	(*info)->size_b--;
	(*info)->size_a++;
	addop(info, newop("pa"));
}

void	pa(t_info **info)
{
	t_list	*tmpa;

	tmpa = (*info)->begin_a;
	(*info)->begin_a = (*info)->begin_b;
	if ((*info)->size_b > 2 && (*info)->begin_b->content == (*info)->min_b)
		(*info)->min_b = getmin((*info)->begin_b)->content;
	if ((*info)->size_b == 1)
	{
		(*info)->begin_b = NULL;
		(*info)->last_b = NULL;
	}
	else
	{
		(*info)->begin_b = (*info)->begin_b->next;
		(*info)->begin_b->prev = (*info)->last_b;
		(*info)->last_b->next = (*info)->begin_b;
	}
	pa2(info, tmpa);
}

void	pb2(t_info **info, t_list *tmpb)
{
	if (tmpb)
	{
		(*info)->begin_b->next = tmpb;
		(*info)->begin_b->next->prev = (*info)->begin_b;
		(*info)->begin_b->prev = (*info)->last_b;
		(*info)->last_b->next = (*info)->begin_b;
		if ((*info)->begin_b->content < (*info)->min_b)
			(*info)->min_b = (*info)->begin_b->content;
	}
	else
	{
		(*info)->begin_b->next = (*info)->begin_b;
		(*info)->begin_b->prev = (*info)->begin_b;
		(*info)->last_b = (*info)->begin_b;
		(*info)->min_b = (*info)->begin_b->content;
	}
	(*info)->size_a--;
	(*info)->size_b++;
	addop(info, newop("pb"));
}

void	pb(t_info **info)
{
	t_list	*tmpb;

	tmpb = (*info)->begin_b;
	(*info)->begin_b = (*info)->begin_a;
	if ((*info)->size_a == 1)
	{
		(*info)->begin_a = NULL;
		(*info)->last_a = NULL;
	}
	else
	{
		(*info)->begin_a = (*info)->begin_a->next;
		(*info)->begin_a->prev = (*info)->last_a;
		(*info)->last_a->next = (*info)->begin_a;
	}
	pb2(info, tmpb);
}
