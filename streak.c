/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:50:50 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 14:48:26 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rem_double(t_info **info)
{
	t_list	*current;
	t_list	*tmp;

	tmp = (*info)->min;
	while (tmp != (*info)->min->prev)
	{
		current = (*info)->min;
		while (current != (*info)->min->prev)
		{
			if (current != tmp && current->streak != -1
				&& current->streak == tmp->streak)
			{
				(*info)->disorder++;
				current->streak = -1;
			}
			current = current->next;
		}
		if (current != tmp && current->streak != -1
			&& current->streak == tmp->streak)
		{
			(*info)->disorder++;
			current->streak = -1;
		}
		tmp = tmp->next;
	}
}

void	get_move(t_info **info)
{
	t_list	*current;
	t_list	*tmp;

	tmp = (*info)->min;
	current = tmp->next;
	while (current != tmp)
	{
		if (current->streak == tmp->streak - 1
			&& current->content > tmp->content)
		{
			tmp = current;
		}
		else if (current->streak <= tmp->streak && current->streak != -1)
		{
			(*info)->disorder++;
			current->streak = -1;
		}
		current = current->next;
	}
	current = current->next;
}

void	streak(t_info **info)
{
	t_list	*current;
	t_list	*tmp;

	(*info)->disorder = 0;
	current = (*info)->min->prev;
	current->streak = 1;
	while (current != (*info)->min)
	{
		current = current->prev;
		current->streak = 1;
		tmp = current->next;
		while (tmp != (*info)->min)
		{
			if (current->content < tmp->content
				&& current->streak < tmp->streak + 1)
				current->streak = tmp->streak + 1;
			tmp = tmp->next;
		}
	}
	get_move(info);
	rem_double(info);
}
