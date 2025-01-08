# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:25:59 by aaghzal           #+#    #+#              #
#    Updated: 2025/01/08 13:24:05 by aaghzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
SRCS := close_handler.c ft_atodbl.c ft_atoi_bonus.c ft_map.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_render.c ft_strcmp.c \
		init_fractal.c power_complex.c print_error.c sum_complex.c
SRCSM := mouse_handler.c main.c key_handler.c
SRCSB := mouse_handler_bonus.c main_bonus.c key_handler_bonus.c
BUILD_DIR := build/
OBJS := ${addprefix $(BUILD_DIR),$(SRCS:.c=.o)}
OBJSM := ${addprefix $(BUILD_DIR),$(SRCSM:.c=.o)}
OBJSB := ${addprefix $(BUILD_DIR),$(SRCSB:.c=.o)}
CFLAGS := -Wall -Wextra -Werror -Imlx
.BONUS := $(BUILD_DIR).bonus
NAME := fractol

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)
 
$(NAME): $(OBJS) $(OBJSM)
	$(if $(wildcard $(.BONUS)),@rm -f $(.BONUS) $(OBJSB))
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^

$(BUILD_DIR)%.o: %.c fractol_bonus.h
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(BUILD_DIR) $(.BONUS)

$(.BONUS): $(OBJS) $(OBJSB) 
	$(if $(wildcard $(.BONUS)),,@rm -f $(OBJSM))
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^
	@touch $(.BONUS)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(if $(wildcard $(.BONUS)),bonus,all)

.PHONY : all clean fclean re bonus
