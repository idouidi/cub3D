# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 12:58:00 by idouidi           #+#    #+#              #
#    Updated: 2021/01/13 12:58:02 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = ft_islower.o ft_memcpy.o ft_putstr_fd.o ft_strlen.o ft_tolower.o \
	   ft_atoi.o ft_isprint.o ft_memmove.o ft_strmapi.o ft_toupper.o \
	   ft_bzero.o ft_isupper.o ft_memset.o ft_split.o ft_strncmp.o \
	   ft_calloc.o ft_itoa.o ft_putchar.o ft_strchr.o ft_strndup.o \
	   ft_isalnum.o ft_memalloc.o ft_putchar_fd.o ft_strdup.o \
	   ft_strnstr.o ft_isalpha.o ft_memccpy.o ft_putendl_fd.o \
	   ft_strjoin.o ft_strrchr.o ft_isascii.o ft_memchr.o \
	   ft_putnbr.o ft_strlcat.o ft_strtrim.o ft_isdigit.o \
	   ft_memcmp.o ft_putnbr_fd.o ft_strlcpy.o ft_substr.o \
	   ft_nbrlen.o ft_putstr.o get_next_line.o ft_strnew.o ft_epur.o ft_swap.o\

SRCS = ft_islower.c ft_memcpy.c ft_putstr_fd.c ft_strlen.c ft_tolower.c \
	   ft_atoi.c ft_isprint.c ft_memmove.c  ft_strmapi.c ft_toupper.c \
	   ft_bzero.c ft_isupper.c ft_memset.c ft_split.c ft_strncmp.c \
	   ft_calloc.c ft_itoa.c ft_putchar.c ft_strchr.c ft_strndup.c \
	   ft_isalnum.c ft_memalloc.c ft_putchar_fd.c ft_strdup.c \
	   ft_strnstr.c ft_isalpha.c ft_memccpy.c ft_putendl_fd.c \
	   ft_strjoin.c ft_strrchr.c ft_isascii.c ft_memchr.c \
	   ft_putnbr.c ft_strlcat.c ft_strtrim.c ft_isdigit.c \
	   ft_memcmp.c ft_putnbr_fd.c ft_strlcpy.c ft_substr.c \
	   ft_nbrlen.c ft_putstr.c get_next_line.c ft_strnew.c ft_epur.c ft_swap.c \

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

$(OBJS): $(SRCS)
	@gcc -Wall -Wextra -Werror $^ -c

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
