# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 12:28:38 by agoomany          #+#    #+#              #
#    Updated: 2018/03/03 22:48:23 by agoomany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC	=		clang

NAME =		libft.a

SOURCES =	ft_strdup.c						\
			ft_bzero.c						\
			ft_strchr.c						\
			ft_strstr.c						\
			ft_strcmp.c						\
			ft_strncmp.c					\
			ft_atoi.c						\
			ft_putchar_fd.c					\
			ft_putstr_fd.c					\
			ft_putendl_fd.c					\
			ft_putnbr_fd.c					\
			ft_strtrim.c					\
			ft_strjoin.c					\
			ft_strsub.c						\
			ft_itoa.c						\
			ft_ltoa.c						\
			ft_strsplit.c					\
			get_next_line.c					\
			ft_strjoin_sep.c				\
			ft_add_in_darray.c				\
			ft_size_darray.c				\
			ft_free_darray.c				\
			ft_ishex.c						\
			ft_atol.c						\
			ft_isalldigit.c					\
			ft_isalldigit_sign.c			\
			ft_merge_array.c				\
			ft_print_darray.c				\
			ft_strnew.c						\
			ft_strlen.c						\
			ft_strcpy.c						\
			ft_strcat.c						\
			ft_strdel.c						\
			ft_strndup.c					\
			ft_strsplit_trim.c				\
			ft_isdigitpoint.c				\

HEADERS	= -Iincludes/

OBJECTS	= $(patsubst %.c,srcs/%.o,$(SOURCES))

WFLAGS	= -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	@echo "[\033[32m✔\033[0m] $@"

%.o: %.c
	$(CC) $(WFLAGS) $(HEADERS) -c -o $@ $^
	@echo "\033[0m[\033[32m✔\033[0m]$@ \033[0m"

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
