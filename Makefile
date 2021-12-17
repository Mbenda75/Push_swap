# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 15:43:25 by benmoham          #+#    #+#              #
#    Updated: 2021/12/17 19:06:38 by benmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_tri.c		\
				push_swap.c		\
				utils_action.c 	\
				utils_tri.c		\
				utils_libft.c	\
				utils_quicksort.c	\
				utils_list.c	\
				my_quicksort.c	\
				action_a.c 		\
				action_b.c		\
				ft_error.c 		\
				ft_split.c 		\
				

OBJS			= $(SRCS:.c=.o)

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) 

re:				fclean all


.PHONY:			all clean fclean c.o re 