# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 22:08:03 by htinisha          #+#    #+#              #
#    Updated: 2020/05/29 16:20:23 by htinisha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isdigit.c ft_memccpy.c ft_split.c \
ft_strlcat.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memchr.c \
ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_strtrim.c \
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_isalpha.c \
ft_itoa.c ft_memcmp.c ft_memset.c ft_strchr.c ft_substr.c \
ft_strrchr.c ft_calloc.c ft_isascii.c ft_strlcpy.c \
ft_atoi.c ft_memcpy.c ft_putendl_fd.c ft_putstr_fd.c \
ft_strdup.c ft_strjoin.c ft_tolower.c ft_strmapi.c

OBJ = $(SRC:.c=.o)

INCLUDE = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

so:
		gcc -fPIC -c $(SRC)
		gcc -shared -o libft.so $(OBJ)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c $(INCLUDE)
		gcc $(FLAGS) -o $@ -c $< 

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all