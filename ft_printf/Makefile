# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mito <mito@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:28:04 by mito              #+#    #+#              #
#    Updated: 2023/11/22 11:43:14 by mito             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c print_digit.c print_ptr.c print_format.c\
		  print_str.c print_char.c print_u_int.c print_hexa_upper.c\
		  print_ptr.c print_ptraddress.c

OBJS	= $(SRCS:.c=.o)

cc	= gcc

CFLAGS	= -Wall -Wextra -Werror

AR	= ar rcs

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
