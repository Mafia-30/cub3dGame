# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 13:34:29 by ymafaman          #+#    #+#              #
#    Updated: 2024/05/19 21:07:37 by ymafaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		Bonus/parsing/store_doors_info_bonus.c \
		Bonus/game_play/render_map.c \
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
		Bonus/game_play/doors_detection_bonus.c \
		Bonus/game_play/strip_drawing_bonus.c \
		Bonus/game_play/strip_drawing_helper_bonus.c \
		Bonus/game_play/player_drawing_bonus.c \
		Bonus/game_play/mini_map_drawing.c \
		Bonus/game_play/ray_cast_door_bonus.c \
		Bonus/game_play/horz_inter_door_bonus.c \
		Bonus/game_play/vert_inter_door_bonus.c \
		
		

BOBJ= $(BSRC:.c=.o)

BNAME= cube3d_bonus

CC= cc
CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address #remove
COMPILING	= -I MLX/MLX42.h

BMLX_LIB = Bonus/MLX/libmlx42.a
BLIBFT = Bonus/libft/libft.a

BLINKING = $(BMLX_LIB) $(BLIBFT) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

bonus: $(BNAME)

$(BNAME): $(BOBJ)
	@make -C Bonus/libft
	$(CC) $(CFLAGS) $^ $(BLINKING) -o $@

Bonus/%.o: Bonus/%.c  $(BMLX_LIB) Bonus/cub3d_bonus.h Bonus/get_next_line/get_next_line.h
	$(CC) $(CFLAGS) $(BCOMPILING) -c $< -o $@

clean:
	rm -f $(MOBJ)
	rm -f $(BOBJ)
	@make clean -C Bonus/libft
	# @make clean -C Mandatory/libft

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	@make fclean -C Bonus/libft
	# @make flean -C Mandatory/libft

re: fclean all

.PHONY: clean fclean all re