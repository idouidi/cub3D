# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 13:18:14 by idouidi           #+#    #+#              #
#    Updated: 2021/01/14 13:33:22 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/parsing/ft_utils_pars.c srcs/parsing/ft_utils2_pars.c srcs/parsing/ft_pars_info_map.c \
	   srcs/parsing/ft_pars_map.c  srcs/parsing/ft_parsing.c \
	   srcs/parsing/ft_adjust_map.c srcs/parsing/ft_set_info_map.c \
	   srcs/display/cub3d.c srcs/display/trgb.c \
	   srcs/display/display.c srcs/display/raycasting.c \
	   srcs/display/utils_display.c srcs/display/dda.c \
	   srcs/display/bitmap.c srcs/display/utils_display2.c \
	   srcs/display/sprites.c srcs/display/utils_sprites.c \

B_SRCS = srcs/bonus/parsing/ft_utils_pars_bonus.c srcs/bonus/parsing/ft_utils2_pars_bonus.c srcs/bonus/parsing/ft_pars_info_map_bonus.c \
	   srcs/bonus/parsing/ft_pars_map_bonus.c  srcs/bonus/parsing/ft_parsing_bonus.c \
	   srcs/bonus/parsing/ft_adjust_map_bonus.c srcs/bonus/parsing/ft_set_info_map_bonus.c \
	   srcs/bonus/display/cub3d_bonus.c srcs/bonus/display/trgb_bonus.c \
	   srcs/bonus/display/display_bonus.c srcs/bonus/display/raycasting_bonus.c \
	   srcs/bonus/display/utils_display_bonus.c srcs/bonus/display/dda_bonus.c \
	   srcs/bonus/display/bitmap_bonus.c srcs/bonus/display/utils_display2_bonus.c \
	   srcs/bonus/display/sprites_bonus.c srcs/bonus/display/utils_sprites_bonus.c \

LIBFTPATH	= project/libft 
LIBOBJ		= project/libft/libft.a
MLXOBJ		= mlx/libmlx.a
MLXPATH		= mlx/
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -march=native -flto 
MLXFLAGS	= -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
NAME		= cub3D
B_NAME		= cub3D_bonus
@B_OBJS		= $(B_SRCS:.c=.o)

all: $(NAME)
bonus: $(B_NAME)


$(NAME): $(@OBJS)
	@echo "\033[33m- Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "\033[32mDone."
	@echo "\033[33m- Compiling cub3d..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS}  main.c $(LIBOBJ) $(MLXOBJ) $(MLXFLAGS)
	@echo "\033[32mDone."
	@echo "\033[31m======================"
	@echo "     TIME TO PLAY"
	@echo "======================"


$(B_NAME): $(@B_OBJS)
ifeq ("$(shell ls -R | grep bonus.o)", "")
	@echo "\033[33m- Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "\033[32mDone."
	@echo "\033[33m- Compiling cub3d \033[35mWITH BONUS\033[33m..."
	@gcc ${CFLAGS} -o ${B_NAME} ${@B_OBJS} main.c $(LIBOBJ) $(MLXOBJ) $(MLXFLAGS)
	@echo "\033[32mDone."
	@echo "\033[31m================================"
	@echo "     TIME TO PLAY SERIOUSLY"
	@echo "================================"
endif

clean:
	rm -rf $(@OBJS) $(@B_OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(B_NAME)
	cd $(LIBFTPATH) && make fclean

re: fclean all


.PHONY: libft, all, clean, fclean, re
.SILENT:
