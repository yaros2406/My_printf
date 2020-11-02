# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 18:54:34 by bshaquan          #+#    #+#              #
#    Updated: 2020/01/16 18:43:05 by bshaquan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I includes

CINC = includes/ft_printf.h libft/includes/libft.h

SRC = ft_printf.c recast_int.c recast_char.c recast_double.c recast_string.c \
		recast_tabstring.c recast_other.c lst_init.c lst_putdouble.c lst_putoption.c \
		utils.c put_string.c put_color.c

OBJ = $(SRC:.c=.o)

DSRC = src/
DOBJ = obj/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))

all: $(NAME)

$(NAME): $(COBJ)
	@echo "Compiling the executable file" $(NAME)
	@ar ru $(NAME) $? libft/obj/*.o
	@ranlib $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CINC)
	@make -C libft/ all
	@mkdir -p $(DOBJ)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compiling the function "$<

clean:
	@make -C libft/ clean
	@mkdir -p $(DOBJ)
	@rm -rf $(DOBJ)
	@echo "Delete the objects"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "Delete the library "$(NAME)

re: fclean all

.PHONY: all clean fclean re
