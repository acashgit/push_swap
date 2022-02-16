# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acash <acash@student.21-school.r>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 15:08:09 by acash             #+#    #+#              #
#    Updated: 2021/11/20 15:08:10 by acash            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME1 = checker
GCC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c \
		push_swap_utils.c \
		push_swap_listop.c \
		push_swap_aegcheck.c \
		easy_sort.c \
		act.c \
		act2.c \
		act3.c \
		ft_hardsort.c \
		ft_split.c \
		ft_split_utils.c \
		score.c \
		bonus1.c \

SRCS1 = checker.c \
		push_swap_utils.c \
		push_swap_listop.c \
		push_swap_aegcheck.c \
		easy_sort.c \
		act.c \
		act2.c \
		act3.c \
		ft_split.c \
		ft_split_utils.c \
		bonus1.c \
		get_next_line.c \

OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)

all:  $(NAME) $(NAME1)

$(NAME): $(OBJS) push_swap.h Makefile
	@$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME1): $(OBJS1) push_swap.h Makefile
	@$(GCC) $(CFLAGS) $(OBJS1) -o $(NAME1)

clean:
	rm -f $(OBJS) $(OBJS1)

fclean: clean
	rm -f $(NAME) $(NAME1) 

re: fclean all

.PHONY: all clean fclean re