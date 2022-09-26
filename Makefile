NAME		=	cub3D

SRC_D		=	srcs
GNL_D		=	gnl
LIBFT_D		=	libft

SRCS		=	${SRC_D}/init/map_reader.c \
				${SRC_D}/init/map_validate.c \
				${SRC_D}/init/color_reader.c \
				${SRC_D}/init/player_pos.c \
				${SRC_D}/init/init_pic.c \
				${SRC_D}/raycast/update_screen.c \
				${SRC_D}/raycast/second.c \
				${SRC_D}/raycast/first.c \
				${SRC_D}/raycast/third.c \
				${SRC_D}/raycast/fourth.c \
				${SRC_D}/raycast/utils.c \
				${SRC_D}/raycast/raycast.c \
				${SRC_D}/raycast/mini_map.c \
				${SRC_D}/raycast/wall_collion.c \
				${SRC_D}/raycast/mouse_move.c \
				${SRC_D}/raycast/hit_tmp_1.c \
				${SRC_D}/raycast/hit_tmp_2.c \
				${SRC_D}/raycast/hit_tmp_3.c \
				${SRC_D}/raycast/hit_tmp_4.c \
				${SRC_D}/moves/turning.c \
				${SRC_D}/moves/WASD.c \
				${SRC_D}/init/pic_validate.c \
				${SRC_D}/init/map_fixer.c \
				${SRC_D}/init/pic_reader.c \
				${SRC_D}/init/color_pos_checker.c \
				\
				${GNL_D}/get_next_line.c \
				${GNL_D}/get_next_line_utils.c \
				\
				main.c

OBJS		=	${SRCS:.c=.o}

INCLUDE		=	./include/cub3d.h \
				./minilibx/mlx_int.h \
				./minilibx/mlx_new_window.h \
				./minilibx/mlx_opengl.h \
				./minilibx/mlx_png.h \
				./minilibx/mlx.h

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-framework OpenGL -framework AppKit

MLX_PATH	=	./minilibx/libmlx.a
LIBFT_PATH	=	./libft/libft.a

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ${dir ${LIBFT_PATH}}
	${MAKE} -C ${dir ${MLX_PATH}}
	cp ${MLX_PATH} .
	${CC} ${CFLAGS} ${LIBFT_PATH} ${MLX_PATH} ${OBJS} ${MLX_FLAGS} -o ${NAME}

%.c: %.o
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${MAKE} clean -C ${dir ${LIBFT_PATH}}
	${MAKE} clean -C ${dir ${MLX_PATH}}
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ${dir ${LIBFT_PATH}}
	${RM} ${NAME}
	${RM} libmlx.a

re: fclean all

norm:
	norminette include main.c srcs gnl libft

.PHONY: all clean fclean re
