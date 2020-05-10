# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iguidado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 11:15:40 by iguidado          #+#    #+#              #
#    Updated: 2020/02/07 22:58:04 by iguidado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Outing
NAME	=	libft.a

#Dir
INC	=	./include
D_OUT 	=	./outlib
D_MEM 	=	./mem
D_STR	=	./string
D_STD	=	./std
D_CTYPE	=	./ctype
D_LST	=	./list

#Files
S_OUT	=	ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_putstr_non_printable.c \
		ft_print_memory.c 

S_MEM	= 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c 

S_STR	=	ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strmapi.c 

S_CTYPE = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c 

S_STD	=	ft_atoi.c \
		ft_itoa.c 

S_LST =		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstmap.c \
		ft_lstiter.c 

HFILE = $(addprefix $(INC), /$(addsuffix .h, $(basename $(NAME))))

#Compile
CC = clang
HFLAG = -I $(INC)
DEBUG = -g3 -fsanitize=address
WFLAG = -Wall -Werror -Wextra

#Auto
SRC = $(S_OUT) \
      $(S_LST) \
      $(S_STD) \
      $(S_MEM) \
      $(S_STR) \
      $(S_CTYPE)


SRCS =	$(addprefix $(D_OUT)/, $(S_OUT)) \
	$(addprefix $(D_LST)/, $(S_LST)) \
	$(addprefix $(D_STD)/, $(S_STD)) \
	$(addprefix $(D_MEM)/, $(S_MEM)) \
	$(addprefix $(D_STR)/, $(S_STR)) \
	$(addprefix $(D_CTYPE)/, $(S_CTYPE))

OBJECT = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

%.o : %.c $(HFILE)
	$(CC) $(WFLAG) $(HFLAG) -o $@ -c $<

test: $(SRCS)
	$(CC) -o test $(WFLAG) $(HFLAG) $(SRCS)
	
debug: $(OBJECT)
	$(CC) -o debug $(DFLAG) $(WFLAG) $(HFLAG) $(SRCS)

clean:
	rm -f $(OBJECT) $(BONUS_OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
