# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 11:50:24 by tnaton            #+#    #+#              #
#    Updated: 2022/02/08 06:16:15 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath ft_%.c libft
vpath %.h libft
vpath ft_%.o libft

source = push_swap.c move.c resolve.c streak.c instruct.c tri.c resolve2.c\
		 instruct2.c move2.c move3.c tri2.c tri3.c tri4.c tri5.c free.c\
		 tomanyfunction.c

sourcebonus = checker.c get_next_line_utils.c get_next_line.c checkermove.c\
			  checkermove2.c checkermove3.c checker2.c
 
LIBFT = libft/libft.a

NAME = push_swap

CHECKER = checker

objects = $(source:.c=.o)

objectsbonus = $(sourcebonus:.c=.o)

$(NAME): $(objects) $(LIBFT)
	gcc $(objects) $(LIBFT) -o $@

$(CHECKER): $(objectsbonus) $(LIBFT)
	gcc -g $(objectsbonus) $(LIBFT) -o $@

$(objects) : push_swap.h

$(objectsbonus) : checker.h get_next_line.h

-include libft/Makefile

ft_%.o : ft_%.c
	gcc $(CFLAGS) -c $< -o $@

$(LIBFT) : $(SRCS) $(BONUS) libft.h
	$(MAKE) bonus -C ./libft

.PHONY: bonus
bonus : $(CHECKER)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	rm -rf $(objects) $(objectsbonus)

.PHONY: fclean
fclean: 
	rm -rf $(NAME) $(CHECKER) $(objects) $(objectsbonus)
	$(MAKE) fclean -C ./libft

.PHONY: re
re : fclean all

.SECONDARY : $(objects) $(objectsbonus)
