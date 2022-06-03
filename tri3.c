/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:06:05 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 11:39:04 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	go_begin_b(t_info **info, t_list *target)
{
	int		rb;
	int		rrb;
	t_list	*current;

	current = target;
	rb = 0;
	rrb = 0;
	while (current != (*info)->begin_b)
	{
		current = current->prev;
		rb++;
	}
	current = target;
	rrb = (*info)->size_b - rb;
	if (rb > rrb)
		return (-rrb);
	return (rb);
}

int	*getra(t_info **info)
{
	t_list	*current;
	int		i;
	int		j;
	int		*tabra;

	tabra = (int *)malloc(sizeof(int) * (*info)->size_b + 1);
	i = (*info)->size_b;
	while (i--)
	{
		j = i;
		current = (*info)->begin_b;
		while (j--)
			current = current->next;
		tabra[i] = take_begin(info, current);
	}
	return (tabra);
}

int	*getrb(t_info **info)
{
	t_list	*current;
	int		i;
	int		j;
	int		*tabrb;

	tabrb = (int *)malloc(sizeof(int) * (*info)->size_b + 1);
	i = (*info)->size_b;
	while (i--)
	{
		j = i;
		current = (*info)->begin_b;
		while (j--)
			current = current->next;
		tabrb[i] = go_begin_b(info, current);
	}
	return (tabrb);
}

void	removeop(t_info **info, int total)
{
	t_op	*current;

	current = (*info)->last_op;
	while (total--)
		current = current->prev;
	current->next = NULL;
	(*info)->last_op = current;
}
