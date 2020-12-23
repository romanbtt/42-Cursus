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



typedef	struct 		s_img
{
	void			*img;
	char			*addr;
	int         	bpp;
    int         	line_length;
    int         	endian;
}					t_img;


typedef struct		s_map
{
	int				resWH[2];
	int				floor_color;
	int			 	ceiling_color;
	char 			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	char			*texture_sprite;
	int				nb_row;
	char			*map;
	char			**map_2d;
	int				count_id;
	int				max_col;
}					t_map;

typedef struct		s_player {
	int			pos_XY[2];
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;
}					t_player;

typedef struct		s_struct
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_player		player;
	t_img			img;
}					t_struct;

typedef void	(*t_array_func_id)(char *, t_struct *);

int		get_next_line(int fd, char **line);

void 	get_identifier(char *line, t_struct *cub3d);
void 	get_map(char *line, t_struct *cub3d);
void	read_file(char *file, t_struct *cub3d);

int	 	is_space(char c);

void	identifier_n(char *line, t_struct *cub3d);
void	identifier_s_so(char *line, t_struct *cub3d);
void	identifier_w(char *line, t_struct *cub3d);
void	identifier_e(char *line, t_struct *cub3d);
void	identifier_r(char *line, t_struct *cub3d);
void	identifier_f(char *line, t_struct *cub3d);
void	identifier_c(char *line, t_struct *cub3d);

int		initialize_window(t_struct *cub3d, int argc);
void 	check_arguments(int argc, char **argv);

void	is_valid_map(t_struct *cub3d);
int		create_trgb(int t, int r, int g, int b);
void	exit_success(void);
void	trigger_keys(int keycode, t_struct *cub3d);

void	update();
void	draw_rectangle();
void    my_mlx_pixel_put(t_struct *cub3d, int x, int y, int color);
void	release_keys(int keycode, t_struct *cub3d);


#endif