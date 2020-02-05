# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsjoberg <lsjoberg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 16:45:59 by lsjoberg          #+#    #+#              #
#    Updated: 2020/02/03 17:55:15 by lsjoberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

EXE = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT_FOLDER = ./libft/

LIB = ./libft/libft.a

LIB_OBJ = ./libft/*.o

SRCS1 = ./srcs/ft_printf.c ./srcs/charperc.c ./srcs/conversions.c ./srcs/helper_conv.c \
		./srcs/helper_print.c ./srcs/helper_swap.c ./srcs/iffloat.c ./srcs/ifoctal.c \
		./srcs/modifier.c ./srcs/pointer.c ./srcs/string.c ./srcs/udecint.c \
		./srcs/ifhex.c ./srcs/ifint.c

SRCS2 = ./srcs/ft_printf.c ./srcs/charperc.c ./srcs/conversions.c \
		./srcs/helper_conv.c ./srcs/helper_print.c ./srcs/helper_swap.c ./srcs/iffloat.c \
		./srcs/ifoctal.c ./srcs/modifier.c ./srcs/pointer.c ./srcs/string.c ./srcs/udecint.c \
		./srcs/ifhex.c ./srcs/ifint.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS1)))

OBJS2 = $(subst .c,.o,$(subst srcs/,,$(SRCS2)))

INCL = -I ./includes/ -I ./libft/includes/



all: $(NAME)

$(NAME): $(SRCS1)
	@make -s -C $(LIBFT_FOLDER)
	@cp $(LIB) ./$(NAME)
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS1)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	@rm -f $(OBJS) $(LIB_OBJ)
	@make -s clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C libft
	
re: fclean all

run: 
	@gcc -c $(SRCS2) $(INCL)
	@gcc $(INCL) $(OBJS2) $(LIB) -o $(EXE)
	
printf: clean run
		@rm -f $(OBJS2)
		@make -s clean -C libft

.PHONY: clean fclean re all