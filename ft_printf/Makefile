# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/25 20:22:36 by mlokhors       #+#    #+#                 #
#    Updated: 2019/09/29 06:45:28 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a


HEADER = ../includes/
NEW_PATH = ../
SRC_DIR = ./
OBJ_DIR = ./.obj/
LIBFT_A = ../libft.a
FLAGS = -Wall -Werror -Wextra

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

$(NAME) : $(OBJS)
		ar crs $(NAME) $(OBJS)
		mv $(NAME) ../

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -c -o $@ $< $(FLAGS) -I../includes -L$(LIBFT_A) -lft
		
clean:
		rm -rf $(OBJ_DIR)
		
fclean: clean
		rm -f $(NAME)
		
re: fclean all