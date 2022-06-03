/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:04:58 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 12:11:24 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(t_list *list)
{
	int		max;
	t_list	*current;
	t_list	*first;

	current = list;
	first = current;
	max = current->content;
	if (current && current->next)
		current = current->next;
	while (current && current != first)
	{
		if (max < current->content)
			max = current->content;
		current = current->next;
	}
	return (max);
}

void	reset(t_info **info, int *enter)
{
	t_list	*current;
	int		i;

	i = 0;
	current = (*info)->begin_a;
	while (current != (*info)->last_a)
	{
		current->content = enter[i++];
		current->streak = 0;
		current = current->next;
	}
	current->content = enter[i];
	current->streak = 0;
	(*info)->min = getmin((*info)->begin_a);
	freeop(info);
	(*info)->begin_op = NULL;
	(*info)->last_op = NULL;
}

int	getbestalg(t_info **info, int *enter)
{
	int		list[5];
	int		i;

	i = 0;
	while (i++ < 4)
	{
		reset(info, enter);
		streak(info);
		tri(info, i);
		combinop(info);
		list[i] = sizeop(info);
		if (i == 1 || i == 2)
			putx(info, 90, 10);
		if (i == 3)
			putx(info, 66, 33);
	}
	putx(info, 90, 10);
	if (list[1] <= list[2] && list[1] <= list[3] && list[1] <= list[4])
		return (1);
	else if (list[2] <= list[1] && list[2] <= list[3] && list[2] <= list[4])
		return (2);
	else if (list[3] <= list[1] && list[3] <= list[2] && list[3] <= list[4])
		return (3);
	putx(info, 66, 33);
	return (4);
}

void	initinfo(t_info **info)
{
	(*info)->size_b = 0;
	(*info)->disorder = 0;
	(*info)->begin_b = NULL;
	(*info)->last_b = NULL;
	(*info)->begin_op = NULL;
	(*info)->last_op = NULL;
}

void	resolve(t_list **list_a, int *enter)
{
	t_info	*info;
	int		alg;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return ;
	info->begin_a = *list_a;
	info->last_a = ft_lstlast(info->begin_a);
	info->min = getmin(info->begin_a);
	info->max = getmax(info->begin_a);
	info->size_a = ft_size(info->begin_a);
	info->begin_a->prev = info->last_a;
	info->last_a->next = info->begin_a;
	initinfo(&info);
	streak(&info);
	alg = getbestalg(&info, enter);
	reset(&info, enter);
	streak(&info);
	tri(&info, alg);
	combinop(&info);
	printop(&info);
	freeinfo(&info);
	free(info);
}
