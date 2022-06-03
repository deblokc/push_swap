/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:32:20 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/03 19:44:13 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeop(t_info **info)
{
	t_op	*current;
	t_op	*tmp;

	current = (*info)->begin_op;
	while (current != (*info)->last_op)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
}

void	freeinfo(t_info **info)
{
	t_list	*current;
	t_list	*tmp;

	current = (*info)->begin_a;
	while (current != (*info)->last_a)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	freeop(info);
}
