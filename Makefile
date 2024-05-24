# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 13:34:29 by ymafaman          #+#    #+#              #
#    Updated: 2024/05/24 18:50:18 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRC= 	Mandatory/cub3d.c \
		Mandatory/get_next_line/get_next_line.c \
		Mandatory/get_next_line/get_next_line_utils.c \
		Mandatory/parsing/parse_line.c \
		Mandatory/parsing/scan_file.c \
		Mandatory/parsing/atoa.c \
		Mandatory/utils/errors.c \
		Mandatory/utils/calculations.c \
		Mandatory/utils/unit_detection.c \
		Mandatory/utils/draw_line.c \
		Mandatory/parsing/append_line.c \
		Mandatory/parsing/is_map_line.c \
		Mandatory/parsing/last_line.c \
		Mandatory/parsing/start_with.c \
		Mandatory/parsing/is_surrounded.c \
		Mandatory/parsing/adjst_mat.c \
		Mandatory/game_play/render_map.c \
		Mandatory/game_init/init.c \
		Mandatory/game_init/init_walls_assets.c \
		Mandatory/game_init/textur_loading.c \
		Mandatory/game_play/moves.c \
		Mandatory/game_play/player_movement.c \
		Mandatory/game_play/ray_cast_wall.c \
		Mandatory/game_play/horz_inter_wall.c \
		Mandatory/game_play/vert_inter_wall.c \
		Mandatory/game_play/window_draw.c \
		Mandatory/game_play/strip_drawing.c \
		Mandatory/game_play/strip_drawing_helper.c \

BSRC= 	Bonus/cub3d_bonus.c \
		Bonus/get_next_line/get_next_line.c \
		Bonus/get_next_line/get_next_line_utils.c \
		Bonus/parsing/parse_line_bonus.c \
		Bonus/parsing/scan_file_bonus.c \
		Bonus/parsing/atoa_bonus.c \
		Bonus/utils/errors_bonus.c \
		Bonus/utils/calculations_bonus.c \
		Bonus/utils/unit_detection_bonus.c \
		Bonus/utils/draw_line_bonus.c \
		Bonus/parsing/append_line_bonus.c \
		Bonus/parsing/is_map_line_bonus.c \
		Bonus/parsing/last_line_bonus.c \
		Bonus/parsing/start_with_bonus.c \
		Bonus/parsing/is_surrounded_bonus.c \
		Bonus/parsing/adjst_mat_bonus.c \
		Bonus/game_play/render_map_bonus.c \
		Bonus/game_init/init_bonus.c \
		Bonus/game_init/init_guns_assets_bonus.c \
		Bonus/game_init/init_walls_assets_bonus.c \
		Bonus/game_init/textur_loading_bonus.c \
		Bonus/game_play/actions_bonus.c \
		Bonus/game_play/moves_bonus.c \
		Bonus/game_play/player_movement_bonus.c \
		Bonus/game_play/ray_cast_wall_bonus.c \
		Bonus/game_play/horz_inter_wall_bonus.c \
		Bonus/game_play/vert_inter_wall_bonus.c \
		Bonus/game_play/window_draw_bonus.c \
		Bonus/game_play/strip_drawing_bonus.c \
		Bonus/game_play/strip_drawing_helper_bonus.c \
		Bonus/game_play/player_drawing_bonus.c \
		Bonus/game_play/mini_map_drawing.c \
		Bonus/game_play/ray_cast_door_bonus.c \
		Bonus/game_play/horz_inter_door_bonus.c \
		Bonus/game_play/vert_inter_door_bonus.c \

MOBJ= $(MSRC:.c=.o)

BOBJ= $(BSRC:.c=.o)

NAME= cub3d

BNAME= cub3d_bonus

CC= cc

CFLAGS= -Wall -Wextra -Werror   -Ofast#-fsanitize=address

COMPILING	= -I MLX/MLX42.h

BMLX_LIB = Bonus/MLX/libmlx42.a
BLIBFT = Bonus/libft/libft.a

MMLX_LIB = Mandatory/MLX/libmlx42.a
MLIBFT = Mandatory/libft/libft.a

MLINKING = $(MMLX_LIB) $(MLIBFT) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

BLINKING = $(BMLX_LIB) $(BLIBFT) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

all : $(NAME)

$(NAME) : $(MOBJ)
	@make -C Mandatory/libft
	$(CC) $(CFLAGS) $^ $(MLINKING) -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJ)
	@make -C Bonus/libft
	$(CC) $(CFLAGS) $^ $(BLINKING) -o $@

Bonus/%.o: Bonus/%.c  $(BMLX_LIB) Bonus/cub3d_bonus.h Bonus/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) $(COMPILING) -c $< -o $@

Mandatory/%.o: Mandatory/%.c  $(MMLX_LIB) Mandatory/cub3d.h Mandatory/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) $(COMPILING) -c $< -o $@

clean:
	rm -f $(MOBJ)
	rm -f $(BOBJ)
	@make clean -C Bonus/libft
	@make clean -C Mandatory/libft

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	@make fclean -C Bonus/libft
	@make fclean -C Mandatory/libft

re: fclean all

.PHONY: clean