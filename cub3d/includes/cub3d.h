#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <float.h>


# define PI 3.14159265
# define FOV (60 * (PI / 180))
# define TITLE_WIN "Cub3D of Robitett - Learning Purpose"

typedef struct		s_pos
{
	float				x;
	float				y;

}					t_pos;


typedef struct		s_sprites
{
	float			dir;
	float				pl_dist;
	int			size;
	int				offset_x;
	int				offset_y;
	float			pos_x;
	float			pos_y;
}					t_sprites;

typedef struct		s_wall
{
	float 			perp_dist;
	float			dist_proj_plane;
	float 			proj_wall_height;
	int				strp_height;
	int				top_strp;
	int				btm_strp;
	int				offset_x;
	int				offset_y;
	float			top_dist;
	int				color;

}					t_wall;

typedef struct		s_helper_ray
{
	float			ray_angle;
	int				id;
	float 			hit_x;
	float 			hit_y;
	float 			dist;
	float			intcp_x;
	float			intcp_y;
	float			step_x;
	float			step_y;
	float			chk_x;
	float			chk_y;
	bool			hit;
}					t_helper_ray;




typedef	struct 		s_img
{
	void			*img;
	char			*addr;
	int         	bpp;
    int         	line_length;
    int         	endian;
	int 			width;
	int				height;
}					t_img;

typedef	struct 		s_texture
{
	t_img			sp;
	t_img			no;
	t_img			so;
	t_img			ea;
	t_img			we;
	t_img			curr;
}					t_texture;

typedef struct		s_map
{
	int				width;
	int				height;
	int				fl_rgb;
	int			 	ceil_rgb;
	char 			*text_no;
	char			*text_so;
	char			*text_we;
	char			*text_ea;
	char			*text_sp;
	unsigned int	row_len;
	char			*map_1d;
	char			**map_2d;
	int				count_id;
	unsigned int	col_len;
	int				tile_size;
	float			scalemap;
	int				sp_qty;
}					t_map;

typedef struct		s_player
{
	int				turn_direction;
	int				walk_fwd_bwd;
	int				walk_rgt_lft;
	float			rot_angle;
	float			rot_speed;
	float			walk_speed;
	t_pos			pos;
}					t_player;

typedef struct		s_ray
{
	float			ray_angle;
	float			hit_x;
	float			hit_y;
	float			dist;
	bool			hit_vert;
	bool			hit_horz;
	bool			isray_up;
	bool			isray_down;
	bool			isray_left;
	bool			isray_right;
}					t_ray;


typedef struct		s_struct
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_player		player;
	t_img			img;
	t_ray			*ray;
	t_sprites		*sprites;
	t_texture		text;
}					t_struct;

typedef void	(*t_array_func_id)(char *, t_map *);

static void		setup_game(t_struct *cub);
static void		check_resolution(t_struct *cub);
static void		initialisation_game(t_struct *cub);

void			process_map_file(t_struct *cub, char *file);
static bool		is_empty_line(char *line);
static bool		is_map_identifier(char c);
static bool		is_line_map(char *line);
static bool		is_missing_identifier(t_map map, char *line);

void			is_map_valid(t_map *map, t_sprites *sp, t_player *pl);
static void		check_sides_map(t_map *map, int row, int col, int curr_col_len);
static bool		is_char_allowed(char c);

void			exit_faillure(char *error);
int				exit_game(void);

void			insert_pixel(t_img *img, int x, int y, int color);
int				pick_pixel(t_img *img, int x, int y);
float			normalize_angle(float angle);
bool			is_wall_at(t_map *map, int x, int y);
float			dist_btw_pts(float x1, float x2, float y1, float y2);

void			get_info_player(t_map *map, t_player *pl, int row, int col);
static void		get_player_angle(t_player *pl , char angle);

void			get_info_sprites(t_struct *cub);

void			get_line_map(t_map *map, char *line);

void			get_map_identifier(t_map *map, char *line);
void			identifier_w(char *line, t_map *map);
void			identifier_e(char *line, t_map *map);
void			identifier_so(char *line, t_map *map);
void			identifier_n(char *line, t_map *map);
void			identifier_s_so(char *line, t_map *map);
void			identifier_r(char *line, t_map *map);
void			identifier_c(char *line, t_map *map);
void			identifier_f(char *line, t_map *map);
static void		put_in_rgb(char **array, int rgb[3]);

int				get_next_line(int fd, char **line);
static int		return_value(char **remainder, char **line, int ret, int fd);
static int		process_line(char **remainder, char **line);

void 			get_texture(t_struct *cub);
static void		get_data_addr(t_texture *text);
static void		check_path_text(t_texture *text);

void			key_event(t_struct *cub);
static int		release_keys(int keycode, t_struct *cub);
static int 		trigger_keys(int keycode, t_struct *cub);

void			move_player(t_map *map, t_player *pl);
static bool		is_collision_at(t_map *map, float x, float y);

void			raycasting(t_struct *cub);
static void		casting_ray(t_map *map, t_ray *ray, t_player *pl);
static void		select_shortest(t_ray *ray, t_helper_ray *horz,
					t_helper_ray *vert);
void			vertical_casting(t_map *map, t_ray *ray, t_helper_ray *vert,
					t_player *pl);
static void 	increment_vert(t_map *map, t_ray *ray, t_helper_ray *vert);
void			horizontal_casting(t_map *map, t_ray *ray, t_helper_ray *horz,
					t_player *pl);
void 			increment_horz(t_map *map, t_ray *ray, t_helper_ray *horz);

void			render_projection(t_struct *cub);
static void		calc_wall_height(t_struct *cub, t_wall *wall, int col);
static void		select_texture(t_texture *text, t_ray *ray);
void			print_floor(t_struct *cub, t_wall *wall, int col);
void			print_ceiling(t_struct *cub, t_wall *wall, int col);
void			print_wall(t_struct *cub, t_wall *wall, int col);

int				update_game(t_struct *cub);

#endif