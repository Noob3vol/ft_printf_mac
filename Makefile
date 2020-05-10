
#Name
NAME = libftprintf.a

LIB = libft.a

SRC = ft_printf.c\
	ftpf_get_format.c\
	ftpf_process_type.c\
	ftpf_ruler.c\
	ftpf_putf.c\
	ftpf_nbr.c\
	ftpf_prefix.c

MAIN_TEST = test.c

HDR	= ft_printf.h
HDR_LIB = libft.h

# Dir

D_LIB = libft
D_INC_LIB = include
D_SRC = src
D_INC = include

# Path

P_HDR = $(D_INC)/$(HDR)
P_HDR_LIB = $(D_LIB)/$(D_INC_LIB)/$(HDR_LIB)

# Auto-variable
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(D_SRC)/, $(SRC))
OBJS = $(SRCS:.c=.o)
INC = $(D_INC)
L_INC = $(D_LIB)/$(D_INC_LIB)

# Compiler

CC = clang
# flag

F_DBG = -g3 -fsanitize=address
F_WAR = -Wall -Werror -Wextra
F_INC = -I$(L_INC) -I$(INC)
FLAG = $(F_DBG) $(F_WAR) $(F_INC)

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test : $(NAME) $(P_HDR_LIB) $(P_HDR)
	$(CC) $(FLAG) $(MAIN_TEST) $(NAME) $(D_LIB)/$(LIB)

%.o : %.c
	$(CC) $(F_WAR) $(F_INC) -o $@ -c $< 

$(LIB) :
	make -C $(D_LIB)

clean :
	rm -f $(OBJS)
	make clean -C $(D_LIB)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(D_LIB)

re : fclean all

.PHONY: all clean fclean re 
