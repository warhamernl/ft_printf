# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/25 20:22:36 by mlokhors       #+#    #+#                 #
#    Updated: 2019/09/25 23:10:25 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NEW_PATH = ../
SRC_DIR = ./
OBJ_DIR = ./.obj/
LIBFT_A = libft.a
FLAGS = -Wall -Werror -Wextra -I

OBJ_NAMES =  handle_char \
			 handle_float \
			 handle_float2 \
			 handle_float3 \
			 handle_int \
			 handle_memory \
			 handle_octal \
			 handle_octal2 \
			 handle_shex \
			 handle_str \
			 handle_uhex \
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

OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))
SRCS = $(patsubst %, $(SRC_DIR)/%.c, $(OBJ_NAMES))

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
		ar crs $(NAME) $(OBJS) $(LIBFT_A)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -c -o $@ $< $(FLAGS)  -lft -I../includes
		
clean:
		rm -rf $(OBJ_DIR)
		
fclean: clean
		rm -f $(NAME)
		
re: fclean all