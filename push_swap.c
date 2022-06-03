/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:36:41 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:39:33 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inlist(t_list *list, long long tmp)
{
	while (list)
	{
		if (list->content == tmp)
			return (1);
		list = list->next;
	}
	return (0);
}

int	checkarg(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (j == 0)
		{
			if (str[j] == '-')
			{
				if (!str[j])
					return (1);
				else
					j++;
			}
		}
		if (!ft_isdigit(str[j]))
			return (1);
		j++;
	}
	if (j == 0)
		return (1);
	return (0);
}

void	freelist(t_list *list)
{
	t_list	*current;
	t_list	*tmp;

	current = list;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	printerror(int *enter, t_list *list)
{
	write(2, "Error\n", 6);
	free(enter);
	freelist(list);
	return (0);
}

int	main(int ac, char **av)
{
	t_list		*list;
	long long	tmp;
	int			*enter;

	list = NULL;
	if (ac != 1)
	{
		enter = (int *)malloc(sizeof(int) * ac - 1);
		if (!enter)
			return (1);
		while (--ac > 0)
		{
			if (checkarg(av[ac]))
				return (printerror(enter, list));
			tmp = ft_atoi(av[ac]);
			if (tmp < -2147483648 || tmp > 2147483647 || inlist(list, tmp))
				return (printerror(enter, list));
			else
				ft_lstadd_front(&list, ft_lstnew(tmp));
			enter[ac - 1] = tmp;
		}
		resolve(&list, enter);
		free(enter);
	}
}
