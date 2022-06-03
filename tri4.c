/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:11:19 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:44:08 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pushmid(t_info **info, int i)
{
	t_list	*current;
	int		temp;

	current = (*info)->begin_b;
	while (i--)
		current = current->next;
	temp = current->content;
	current = (*info)->begin_b;
	while (current != (*info)->last_b)
	{
		if (current->content < (*info)->tophalf
			&& current->content > (*info)->bothalf)
		{
			if (temp < (*info)->tophalf && temp > (*info)->bothalf)
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	gettop(t_info **info)
{
	t_list	*current;

	current = (*info)->begin_b;
	while (current != (*info)->last_b)
	{
		if (current->content > (*info)->tophalf)
			return (1);
		current = current->next;
	}
	return (0);
}

int	getbot(t_info **info)
{
	t_list	*current;

	current = (*info)->begin_b;
	while (current != (*info)->last_b)
	{
		if (current->content > (*info)->bothalf)
			return (1);
		current = current->next;
	}
	return (0);
}

int	triple(t_info **info, int i)
{
	t_list	*current;

	current = (*info)->begin_b;
	while (i--)
		current = current->next;
	if (gettop(info))
	{
		if (current->content < (*info)->tophalf)
			return (0);
	}
	else if (getbot(info))
	{
		if (current->content < (*info)->bothalf)
			return (0);
	}
	return (1);
}

int	getalg(t_info **info, int alg, int i)
{
	if (alg == 1)
		return (1);
	if (alg == 2)
		return (pushmid(info, i));
	if (alg == 3)
	{
		if ((*info)->size_a < (*info)->size_b)
		{
			if (pushmid(info, i))
				return (1);
			return (0);
		}
		return (1);
	}
	return (triple(info, i));
}
