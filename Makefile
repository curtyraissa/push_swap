# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 14:02:11 by rcurty-g          #+#    #+#              #
#    Updated: 2025/01/09 12:40:37 by rcurty-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -rf
SRCS = $(addprefix $(SRC_DIR)/, main.c radix_sort.c operations.c utils.c small_sort.c)
OBJS = $(SRCS:.c=.o)
HEADERS = -I include -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Executable $(NAME) created successfully."

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft compiled successfully."

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compiled $< into $@."

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaned object files."

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Cleaned executable and libraries."

re: fclean all
	@echo "Rebuilt project."


