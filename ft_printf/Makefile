# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/29 09:57:34 by mlokhors       #+#    #+#                 #
#    Updated: 2019/10/11 06:37:13 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRC_DIR = ./
OBJ_DIR = ./.obj/
FLAGS = -Wall -Werror -Wextra -I./
CC=gcc

OBJ_NAMES =  handle_char \
			 handle_float \
			 handle_float2 \
			 handle_float3 \
			 handle_float4 \
			 handle_int \
			 handle_memory \
			 handle_octal \
			 handle_octal2 \
			 handle_octal3 \
			 handle_hex \
			 handle_str \
			 handle_uint \
			 handle_percent \
			 handle_color \
			 handle_bits \
			 handle_bits2 \
			 padding \
			 widthprecision \
			 listbuff \
			 ft_itoa_base_len \
			 flags \
			 print_version \
			 make_print \


OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))
SRCS = $(patsubst %, $(SRC_DIR)/%.c, $(OBJ_NAMES))

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
		cp ./libft/libft.a $(NAME)
		ar crs $(NAME) $(OBJS)
		@echo succes

$(LIBFT) : 
		$(MAKE) -C ./libft/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -c -o $@ $< $(FLAGS)
clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re: fclean all
