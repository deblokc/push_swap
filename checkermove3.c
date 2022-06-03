/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermove3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:40:12 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 06:14:38 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_checker *info)
{
	rra(info);
	rrb(info);
}

void	sa(t_checker *info)
{
	t_list	*tmp;

	if (info->size_a > 1)
	{
		if (info->size_a == 2)
			ra(info);
		else
		{
			tmp = info->begin_a;
			info->begin_a = info->begin_a->next;
			tmp->next = info->begin_a->next;
			tmp->prev = info->begin_a;
			info->begin_a->next->prev = tmp;
			info->begin_a->next = tmp;
			info->begin_a->prev = info->last_a;
			info->last_a->next = info->begin_a;
		}
	}
}

void	sb(t_checker *info)
{
	t_list	*tmp;

	if (info->size_b > 1)
	{
		if (info->size_b == 2)
			rb(info);
		else
		{
			tmp = info->begin_b;
			info->begin_b = info->begin_b->next;
			tmp->next = info->begin_b->next;
			tmp->prev = info->begin_b;
			info->begin_b->next->prev = tmp;
			info->begin_b->next = tmp;
			info->begin_b->prev = info->last_b;
			info->last_b->next = info->begin_b;
		}
	}
}

void	ss(t_checker *info)
{
	sa(info);
	sb(info);
}
