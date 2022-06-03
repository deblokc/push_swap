/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkermove2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:40:12 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 06:13:35 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_checker *info)
{
	if (info->size_a)
	{
		info->begin_a = info->begin_a->next;
		info->last_a = info->last_a->next;
	}
}

void	rb(t_checker *info)
{
	if (info->size_b)
	{
		info->begin_b = info->begin_b->next;
		info->last_b = info->last_b->next;
	}
}

void	rr(t_checker *info)
{
	ra(info);
	rb(info);
}

void	rra(t_checker *info)
{
	if (info->size_a)
	{
		info->begin_a = info->last_a;
		info->last_a = info->last_a->prev;
	}
}

void	rrb(t_checker *info)
{
	if (info->size_b)
	{
		info->begin_b = info->last_b;
		info->last_b = info->last_b->prev;
	}
}
