# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 19:32:15 by jchoi             #+#    #+#              #
#    Updated: 2022/02/16 16:57:58 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm
RMFLAGS = -f
AR		= ar
ARFLAGS = crs
INCLUDES	= ft_printf.h\
			  libft.h 

PF_SRCS = ft_printf.c\
		  ft_pf_utils.c

SRCS_1	= ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_strlen.c\
		  ft_memset.c\
		  ft_bzero.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strncmp.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strnstr.c\
		  ft_calloc.c\
		  ft_strdup.c\
		  ft_atoi.c
		  
SRCS_2	= ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c

SRCS_BN = ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c

SRCS		= $(LIBFT_SRCS) $(PF_SRCS)

LIBFT_SRCS	= $(SRCS_1)\
			  $(SRCS_2)\
			  $(SRCS_BN)

OBJS	= $(SRCS:.c=.o)


all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(INCLUDES)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re
