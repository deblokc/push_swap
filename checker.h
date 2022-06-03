/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:24:55 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/08 12:52:34 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"

typedef struct s_checker
{
	t_list	*begin_a;
	t_list	*last_a;
	t_list	*begin_b;
	t_list	*last_b;
	int		size_a;
	int		size_b;
}				t_checker;

char	*get_next_line(int fd);
void	ra(t_checker *info);
void	rb(t_checker *info);
void	rra(t_checker *info);
void	rrb(t_checker *info);
void	rr(t_checker *info);
void	rrr(t_checker *info);
void	pa(t_checker *info);
void	pb(t_checker *info);
void	sa(t_checker *info);
void	sb(t_checker *info);
void	ss(t_checker *info);
int		checkint(int ac, char **av, t_list **list);
int		checkop(char *op);
int		checkarg(char *str);
int		inlist(t_list *list, long long tmp);
int		ft_size(t_list *list);

#endif
