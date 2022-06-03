/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:03:02 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 17:03:39 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate2(t_info **info, t_list *current)
{
	while (current != (*info)->min)
	{
		rra(info);
		current = (*info)->begin_a;
	}
}

void	rotate(t_info **info)
{
	t_list	*current;
	int		i;

	i = 0;
	current = (*info)->begin_a;
	while (current != (*info)->min)
	{
		current = current->next;
		i++;
	}
	current = (*info)->begin_a;
	if (i <= (*info)->size_a / 2)
	{
		while (current != (*info)->min)
		{
			ra(info);
			current = (*info)->begin_a;
		}
	}
	else
		rotate2(info, current);
}

int	getcont(t_info **info)
{
	t_list	*current;

	current = (*info)->last_a;
	while (current->streak == -1)
		current = current->prev;
	return (current->content);
}

int	take_begin2(t_info **info, t_list *target, int ra)
{
	t_list	*current;

	current = (*info)->begin_a;
	while (!(target->content < current->content
			&& target->content > current->prev->content))
	{
		current = current->next;
		ra++;
	}
	return (ra);
}

int	take_begin(t_info **info, t_list *target)
{
	int		ra;
	int		rra;
	t_list	*current;

	current = (*info)->begin_a;
	ra = 0;
	rra = 0;
	if (target->content > (*info)->min->prev->content)
	{
		while (current != (*info)->min)
		{
			current = current->next;
			ra++;
		}
	}
	else
		ra = take_begin2(info, target, ra);
	rra = (*info)->size_a - ra;
	if (ra > rra)
		return (-rra);
	return (ra);
}
