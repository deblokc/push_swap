/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tomanyfunction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:50:13 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 15:54:02 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ifstat(int *min, int *ra, int *rb, int i)
{
	if (ra[i] < 0 && rb[i] < 0)
		min = allneg(ra[i], rb[i], min);
	else if ((ra[i] < 0 && rb[i] >= 0) || (rb[i] < 0 && ra[i] >= 0))
		min = halfneg(ra[i], rb[i], min);
	else
		min = noneg(ra[i], rb[i], min);
	return (min);
}

void	dostreak(t_info **info, t_list *current)
{
	if (current->streak == -1)
		sanpb(info, current);
	else
		sanra(info, current);
}
