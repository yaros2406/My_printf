# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 19:01:49 by bshaquan          #+#    #+#              #
#    Updated: 2019/11/21 19:01:54 by bshaquan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

HEADER = libft.h get_next_line.h

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c  \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	  ft_strstr.c  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstdelone.c \
	  ft_lstnew.c ft_find_next_prime.c ft_is_prime.c ft_iterative_factorial.c ft_iterative_power.c ft_recursive_factorial.c \
	  ft_recursive_power.c ft_sort_integer_table.c ft_sqrt.c ft_strlcpy.c ft_strrev.c ft_swap.c ft_match.c ft_str_is_alpha.c \
	  ft_str_is_lowercase.c ft_str_is_numeric.c  ft_str_is_printable.c ft_str_is_uppercase.c ft_strcapitalize.c ft_strlowcase.c \
	  ft_itoa_base.c ft_isspace.c ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_isxdigit.c ft_strupcase.c get_next_line.c ft_printtab.c \
	  ft_strncpychr.c ft_strcpychr.c ft_intlen.c ft_putpstr_fd.c ft_countwchar.c

OBJ = $(SRC:.c=.o)

DSRC = src/
DOBJ = obj/
DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER))

all: $(NAME)

$(NAME): $(COBJ)
	@echo "Compiling the library" $(NAME)
	@ar ru $(NAME) $?
	@echo "Index optimization with ranlib"
	@ranlib $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
	@mkdir -p $(DOBJ)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compiling the function "$<

clean:
	@rm -rf $(DOBJ)
	@echo "Delete the objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Delete the library "$(NAME)

re: fclean all

.PHONY: all clean fclean re
