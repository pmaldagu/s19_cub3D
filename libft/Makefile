 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 09:46:31 by pmaldagu          #+#    #+#              #
#    Updated: 2020/01/15 16:52:17 by pmaldagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
   	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_utoa_base.c \
	ft_free.c

SBONUS = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		
NAME = libft.a

OBJS = $(SRC:%.c=%.o)

BOBJS = $(SBONUS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

RM = rm -rf

HEADER = ./

BHEADER = ./libft.h

TEST = ./test/main.c


all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)   

bonus:
	$(GCC) $(CFLAGS) -I$(BHEADER) -c $(SBONUS)
	ar rc $(NAME) $(BOBJS)

test: re
	$(GCC) $(CFLAGS) -I$(HEADER) $(TEST) $(NAME)
	./a.out
	$(RM) ./a.out


lib: all clean

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re bonus
