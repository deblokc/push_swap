/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:40:12 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 06:11:11 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb2(t_checker *info, t_list *tmpb)
{
	if (tmpb)
	{
		info->begin_b->next = tmpb;
		info->begin_b->next->prev = info->begin_b;
		info->begin_b->prev = info->last_b;
		info->last_b->next = info->begin_b;
	}
	else
	{
		info->begin_b->next = info->begin_b;
		info->begin_b->prev = info->begin_b;
		info->last_b = info->begin_b;
	}
	info->size_a--;
	info->size_b++;
}

void	pb(t_checker *info)
{
	t_list	*tmpb;

	if (info->size_a)
	{
		tmpb = info->begin_b;
		info->begin_b = info->begin_a;
		if (info->size_a == 1)
		{
			info->begin_a = NULL;
			info->last_a = NULL;
		}
		else
		{
			info->begin_a = info->begin_a->next;
			info->begin_a->prev = info->last_a;
			info->last_a->next = info->begin_a;
		}
		pb2(info, tmpb);
	}
}

void	pa2(t_checker *info, t_list *tmpa)
{
	if (tmpa)
	{
		info->begin_a->next = tmpa;
		info->begin_a->next->prev = info->begin_a;
		info->begin_a->prev = info->last_a;
		info->last_a->next = info->begin_a;
	}
	else
	{
		info->begin_a->next = info->begin_a;
		info->begin_a->next->prev = info->begin_b;
		info->begin_a->prev = info->begin_a;
		info->last_a = info->begin_a;
	}
	info->size_b--;
	info->size_a++;
}

void	pa(t_checker *info)
{
	t_list	*tmpa;

	if (info->size_b)
	{
		tmpa = info->begin_a;
		info->begin_a = info->begin_b;
		if (info->size_b == 1)
		{
			info->begin_b = NULL;
			info->last_b = NULL;
		}
		else
		{
			info->begin_b = info->begin_b->next;
			info->begin_b->prev = info->last_b;
			info->last_b->next = info->begin_b;
		}
		pa2(info, tmpa);
	}
}
