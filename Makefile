# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bena <bena@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:47:22 by becastro          #+#    #+#              #
#    Updated: 2022/05/06 20:57:32 by bena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
cc = gcc
AR = ar rc
RM	= rm -r
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address -g3
SRC_DIR = srcs/ft_
OBJ_DIR = obj/
FT = ft_

#files
SRC_FILES = printf printf_utils is_arg print_args getflags print_precision

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#rules

all: $(NAME)

$(NAME):$(OBJ)
	@make bonus -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "printf compiled"

OBJF = .cache_exists

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(LIBFT)/libft.a

re: fclean all
