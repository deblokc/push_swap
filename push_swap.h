/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:13:02 by tnaton            #+#    #+#             */
/*   Updated: 2022/02/07 16:24:12 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

t_list	*getmin(t_list *list);
void	printlist(t_info **info);
void	resolve(t_list **list_a, int *enter);
void	streak(t_info **info);
void	ra(t_info **info);
void	rb(t_info **info);
void	rra(t_info **info);
void	rrb(t_info **info);
void	sa(t_info **info);
void	sb(t_info **info);
void	pa(t_info **info);
void	pb(t_info **info);
void	rr(t_info **info);
void	rrr(t_info **info);
void	ss(t_info **info);
t_op	*newop(char *content);
void	addop(t_info **info, t_op *new);
void	printop(t_info **info);
void	tri(t_info **info, int i);
void	combinop(t_info **info);
int		ft_size(t_list *list);
t_list	*getmin(t_list *list);
void	xandx(t_op *current, t_op *last, char *s1, char *s2);
void	rrbtorrr(t_op *current, t_op *last);
void	ratorr(t_op *current, t_op *last);
void	rbtorr(t_op *current, t_op *last);
void	rratorrr(t_op *current, t_op *last);
void	ra(t_info **info);
void	rb(t_info **info);
void	rra(t_info **info);
void	rrb(t_info **info);
void	sa(t_info **info);
void	rr(t_info **info);
void	rrr(t_info **info);
void	ss(t_info **info);
void	rotate(t_info **info);
int		getcont(t_info **info);
int		take_begin(t_info **info, t_list *target);
int		go_begin_b(t_info **info, t_list *target);
int		*getra(t_info **info);
int		*getrb(t_info **info);
void	removeop(t_info **info, int total);
void	dorotate(t_info **info, int *min);
int		(*getf(int i))(t_info **info, int val);
int		condition(int (*f)(t_info **, int val), t_info **info, int i);
int		*getrotation(t_info **info, int alg);
void	freeinfo(t_info **info);
void	freeop(t_info **info);
void	freelist(t_list *list);
int		get_x(t_info **info, int prc);
int		getalg(t_info **info, int alg, int i);
int		sizeop(t_info **info);
int		get_x(t_info **info, int prc);
void	putx(t_info **info, int top, int bot);
int		*ifstat(int *min, int *ra, int *rb, int i);
int		*halfneg(int ra, int rb, int *min);
int		*noneg(int ra, int rb, int *min);
int		*allneg(int ra, int rb, int *min);
void	dostreak(t_info **info, t_list *current);
void	sanpb(t_info **info, t_list *current);
void	sanra(t_info **info, t_list *current);
int		checkarg(char *str);
int		inlist(t_list *list, long long tmp);
char	*get_next_line(int fd);

#endif
