/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:02:59 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 06:15:01 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	useop(char *op, t_checker *info)
{
	if (!ft_strncmp(op, "ra\n", 4))
		ra(info);
	if (!ft_strncmp(op, "rb\n", 4))
		rb(info);
	if (!ft_strncmp(op, "rra\n", 4))
		rra(info);
	if (!ft_strncmp(op, "rrb\n", 4))
		rrb(info);
	if (!ft_strncmp(op, "rr\n", 4))
		rr(info);
	if (!ft_strncmp(op, "rrr\n", 4))
		rrr(info);
	if (!ft_strncmp(op, "pa\n", 4))
		pa(info);
	if (!ft_strncmp(op, "pb\n", 4))
		pb(info);
	if (!ft_strncmp(op, "sa\n", 4))
		sa(info);
	if (!ft_strncmp(op, "sb\n", 4))
		sb(info);
	if (!ft_strncmp(op, "ss\n", 4))
		ss(info);
}

void	sorted(t_checker *info)
{
	t_list	*current;

	current = info->begin_a;
	if (info->size_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (current != info->last_a)
	{
		if (current->content > current->next->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		current = current->next;
	}
	write(1, "OK\n", 3);
}

void	initinfo(t_checker *info, t_list **a)
{
	info->begin_a = *a;
	info->size_a = ft_size(info->begin_a);
	info->last_a = ft_lstlast(info->begin_a);
	info->begin_a->prev = info->last_a;
	info->last_a->next = info->begin_a;
	info->size_b = 0;
	info->begin_b = NULL;
	info->last_b = NULL;
}

void	operation(t_list **a)
{
	t_checker	*info;
	char		*op;

	info = (t_checker *)malloc(sizeof(t_checker));
	if (!info)
		return ;
	initinfo(info, a);
	op = get_next_line(0);
	while (op)
	{
		if (!checkop(op))
		{
			write(2, "Error\n", 6);
			return ;
		}
		useop(op, info);
		free(op);
		op = get_next_line(0);
	}
	sorted(info);
	free(info);
}

int	main(int ac, char **av)
{
	t_list		*a;

	a = NULL;
	if (ac != 1)
	{
		if (checkint(ac, av, &a))
			operation(&a);
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
