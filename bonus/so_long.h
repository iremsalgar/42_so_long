# ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define PLAYER_W "./bonus/image/back.xpm"
# define PLAYER_A "./bonus/image/left.xpm"
# define PLAYER_S "./bonus/image/front.xpm"
# define PLAYER_D "./bonus/image/right.xpm"
# define BACKGROUND "./bonus/image/sea.xpm"
# define WALL "./bonus/image/wall.xpm"
# define EGG "./bonus/image/egg.xpm"
# define EXIT "./bonus/image/exit.xpm"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY 17
# define X_EVENT_FOCUS_IN 9

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list{
    char            *x;
    struct s_list    *next;
}t_list;

typedef struct s_img
{
    void    *wall;
    void    *background;
	void	*exit;
    void    *player_w;
    void    *player_a;
    void    *player_s;
    void    *player_d;
	void	*egg;
	int		eggadd;
	int		exit_chk;
}   t_img;

typedef struct s_data
{
	int		x_pos;
	int 	y_pos;
	void	*mlx;
	void	*mlx_window;
	t_img	*img;
	char	**map;
	int		line_width;
	int		line_height;
	int		move;
	int		player_direction;
	int		p_chk;
	int		finish;
	int		p_x;
	int		p_y;
}	t_info;

void		xpm_control(void);
void		xpm_control_two(void);
char		*get_next_line(int fd);
char		*get_line(char *line);
t_list		*ft_lstnew(void);
char		*ft_controller(char *str, const char c, t_list *y);
int			ft_chk(const char *a, int chker, int c);
char		*ft_strjoin(char *s1, const char *s2);
char		*ft_strdup_two(const char *s1);
char		*ft_cutter(char *str, char c, int i);
void		print_screen(t_info *data);
void		check_materials(t_info *map);
int			main(int argc, char**argv);
char 		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
int			take_image(t_info *info_img);
void		take_and_put_bridge(t_info *info_img, int x, int y);
void		put_image(t_info *img, void *img_type, int x, int y);
void		exit_game(t_info *map, int d);
void		destroy_image(t_info *map);
void		read_map(t_info *map, char *ber_file);
void		detect_component(t_info *map);
void		for_image(t_info *img);
void    	map_update(t_info *new_map);
void    	map_and_put_bridge(t_info *new_map, int x, int y);
void    	map_update_p(t_info *game);
void		update_direction(int player_direction, t_info *move);
void		update_player(int keycode, t_info *game);
int			key_press(int keycode, t_info *move);
int			char_move_top(t_info *move);
int			char_move_down(t_info *move);
int			char_move_left(t_info *move);
int			char_move_right(t_info *move);
void    	*ft_calloc(size_t count, size_t size);

#endif
