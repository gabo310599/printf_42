# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 16:33:59 by gojeda            #+#    #+#              #
#    Updated: 2025/04/11 16:34:01 by gojeda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
SRC     = ft_printf.c \
			printf_utils.c \
			printf_utils_base.c \
			printf_hex_parse.c
OBJ     = ${SRC:.c=.o}
RM      = rm -f
AR      = ar rcs

all: ${NAME}

$(NAME): ${OBJ}
	@${AR} ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
