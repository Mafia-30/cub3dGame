#ifndef CUB3D_BONUS_H
 #define CUB3D_BONUS_H

# include "MLX/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <signal.h>


typedef struct s_color
{
	int r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct s_point
{
	double x;
	double y;
} t_point;

typedef struct s_gun
{
    uint32_t* gun_pixels[5];
}    t_gun;


typedef struct s_door
{
	t_point	pos;
	int		first_pixel_x;
}	t_door;

typedef struct s_player
{
	double	x;
	double	y;
	int		turn_dir; // -1 for left, 1 for right
	int		turn_dir_mouse; // -1 for left, 1 for right
	int		walk_dir; // -1 for back, 1 for front
	int		walk_sid; // -1 for left, 1 for right
	double	rotation_angle; // in radian
	double	move_speed;
	double		FOV;
	int		rays_num;
	double	rotation_speed;
	mlx_image_t* player_imgs[5];
	uint32_t* player_pixels[5];
	mlx_image_t *rays;
	int shooting;
	int gun_image_id;
    int gun_id;
	t_gun    guns[4];
	char **knife;
	char **gun;
	char **aka;
	char **machine;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			map_x;
	int			map_y;
	int			empty_line_in_map;
	t_player 	player;
	mlx_image_t *win_image;
	int 		mini_map_size;
	t_door		*doors;
	int			doors_num;
}	t_map;

typedef struct s_drawable_doors
{
	double	ray_distance;
	double door_height;
	char	inter_type;
	int		hitten_door_index;
	int		hitten_door_index_2;
	t_point	index;
	t_point inter_door;
	struct s_drawable_doors *next;
	struct s_drawable_doors *prev;
}	t_drawable_doors;


typedef struct s_game
{
	char intersection_type;
	t_point inter;
	uint32_t *no_pixels;
	uint32_t *so_pixels;
	uint32_t *we_pixels;
	uint32_t *ea_pixels;
	char	*no_texture; 
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	t_map	map;
	int     tile_size;
	int		win_width;
	int		win_height;
	mlx_t	*mlx;
	t_point inter_door;
	uint32_t *door_pixels;
	bool allow_door_drawing;
	char    *door_texture;
	char intersection_type_door;
	double dpp;
	int		hitten_door_index;
	int		found_doors;
}	t_game;


// parsing/scan_file.c
void		scan_file(t_game *game, char *file);


//parse_line.c
void		parse_line(t_game *game, char *line);
void        parse_texture(char *line, char **texture);
void        parse_color(char *line, int *color);




// utils/errors.c
void		error_exit(char *message);
void		free_game(t_game *game);


//utils/ft_atoi.c
int			cub_atoi(const char *str, char c);


//utils/get_next_line.c
char*			get_next_line(int fd);



// utils/clean.c
void		free_game(t_game *game);


//utils/init.c
void		init_game(t_game *game);


//utils/is_map_line.c
int is_map_line(t_game *game, char *line);


//utils/append_line.c
void		append_line(t_game *game, char *line);


//utils/strdup.c
// char		*ft_strdup(char *str);



//mini_map/render_map.c
// void render_map(t_game *game);


//utils/last_line.c
char* last_line(char **map);



//utils/start_with.c
int start_with(char *line, char c1, char c2);

//utils/is_surrounded.c
void is_surrounded(t_map *map);

// utils/adjust_matrix.c
void adjust_matrix(t_map *map);

void    store_doors_info(t_game *game);
// calculations
double distanceBetweenPoints(double x1, double y1, double x2, double y2);
// draw a line
void draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2);

//texutes loading 
void init_arm(t_game *game, char *gun[5]);
void init_player_img(t_game *game);
void init_map(t_game *game);
uint32_t *load_texture(t_game *game, char *path, int w, int h);

void render_map(t_game *game);

//hooks
void actions(mlx_key_data_t keydata, void *param);
void my_loop_hook(void *param);
void update_pos_dir(t_game *game);


//unit detection
int hasWallAt(t_game *game, double x, double y);
int hasDoorAt(t_game *game, double x, double y);

//ray_casting
void draw_intersect(t_game *game, double ray_angle, double *ray_distance);
void draw_intersect_door(t_game *game, double ray_angle, double *ray_distance);
double	get_vert_distance(t_game *game, double ray_angle, bool *foundVertHit, t_point *vert_intersect);
double	get_horz_distance(t_game *game, double ray_angle, bool *foundHorzHit, t_point *horz_intersect);
double	get_horz_door_distance(t_game *game, double ray_angle, bool *foundHorzHit, t_point *horz_intersect);
double	get_vert_door_distance(t_game *game, double ray_angle, bool *foundHorzHit, t_point *horz_intersect);

//drawing
void display_all(t_game *game);
t_drawable_doors *get_drawable_doors(t_game *game, double ray_angle);
void draw_strip(t_point startPoint, double height, t_game *game);
int get_texture_x(t_game *game);
int get_texture_y(int y, double height, t_game *game);
void draw_player(t_game *game);
void draw_mini_map(t_game *game);


#endif

