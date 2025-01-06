# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 17:12:05 by mgomes-s          #+#    #+#              #
#    Updated: 2024/12/17 09:45:57 by mgomes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

CC= cc

CFLAGS= -Wall -Werror -Wextra

LIBX= -lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm ./minilibx-linux/libmlx.a

SRC= main.c mandelbrot.c julia.c aux.c init.c

OBJ= $(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE= \033[1;34m
PURPLE= \033[1;35m
RESET=\033[0m

all: $(NAME)
	@ echo "                                   "
	@ echo "$(GREEN)✅ Build completed!$(RESET)"
	@ echo "                                   "
	@ echo "_______________________________________"
	@ echo "                Fractol                "
	@ echo "|                                     |"
	@ echo "|  For Mandelbrot:                    |"
	@ echo "|  $(BLUE)./fractol mandelbrot$(RESET)               |"
	@ echo "|                                     |"
	@ echo "|  For Julia:                         |"
	@ echo "|  $(PURPLE)./fractol julia  <num>$(RESET)             |"
	@ echo "|                                     |"
	@ echo "| $(RED)<num>: num can only be worth 1 or 2$(RESET) |"
	@ echo "|                                     |"
	@ echo "_______________________________________"


.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

fractol: $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBX) -o fractol

clean:
	@ rm -f $(OBJ)
	@ echo "                                      "
	@ echo "$(RED)🗑️  successfully deleted$(RESET)"
	@ echo "                                      "


fclean: clean
	@ rm -f fractol

re: fclean all