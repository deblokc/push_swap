/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:15:33 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:51:25 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dorotate(t_info **info, int *min)
{
	if (min[1] < 0)
	{
		while (min[1]++)
			rra(info);
	}
	else
	{
		while (min[1]--)
			ra(info);
	}
	if (min[2] < 0)
	{
		while (min[2]++)
			rrb(info);
	}
	else if (min[2] > 0)
	{
		while (min[2]--)
			rb(info);
	}
}

int	*allneg(int ra, int rb, int *min)
{
	if (ra > rb)
	{
		if (-(rb) < min[0])
		{
			min[0] = -(rb);
			min[1] = ra;
			min[2] = rb;
		}
	}
	else
	{
		if (-(ra) < min[0])
		{
			min[0] = -(ra);
			min[1] = ra;
			min[2] = rb;
		}
	}
	return (min);
}

int	*halfneg(int ra, int rb, int *min)
{
	if (ra < 0 && rb >= 0)
	{
		if ((-ra + rb) < min[0])
		{
			min[0] = (-ra + rb);
			min[1] = ra;
			min[2] = rb;
		}
	}
	else if (rb < 0 && ra >= 0)
	{
		if ((-rb + ra) < min[0])
		{
			min[0] = (-rb + ra);
			min[1] = ra;
			min[2] = rb;
		}
	}
	return (min);
}

int	*noneg(int ra, int rb, int *min)
{
	if (ra > rb)
	{
		if (ra < min[0])
		{
			min[0] = ra;
			min[1] = ra;
			min[2] = rb;
		}
	}
	else
	{
		if (rb < min[0])
		{
			min[0] = rb;
			min[1] = ra;
			min[2] = rb;
		}
	}
	return (min);
}

int	*getrotation(t_info **info, int alg)
{
	int	i;
	int	*ra;
	int	*rb;
	int	*min;

	i = (*info)->size_b;
	ra = getra(info);
	rb = getrb(info);
	min = (int *)malloc(sizeof(int) * 3);
	if (!min)
		return (NULL);
	min[0] = 2147483647;
	min[1] = 0;
	min[2] = 0;
	while (i--)
	{
		if (getalg(info, alg, i))
		{
			min = ifstat(min, ra, rb, i);
		}
	}
	free(ra);
	free(rb);
	return (min);
}
