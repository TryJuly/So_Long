#################################################################################################################
#                                           VARIABLES SET                                                       #
#################################################################################################################
NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

EXTRA = -Lmlx_linux -L${MINILIBX} -Imlz_linux -lXext -lX11 #-lm -lz

SRCS = main.c map_check.c map_check_v2.c valid_extension.c tool_player.c free.c tool_mlx.c
 
INCLUDES = so_long.h

LIBFT = ./libft/
LIBFT_A= ./libft.a

MINILIBX = ./minilibx-linux
MINILIBX_A = ./libmlx.a

LIB = ${MINILIBX_A} ${LIBFT_A}

OBJS = ${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}
OBJ_DIR = objets
#################################################################################################################
#                                           RULES COMPILATION                                                   #
#################################################################################################################
all: ${LIBFT_A} ${MINILIBX_A} ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB} ${EXTRA} -I ${INCLUDES} -o ${NAME}

${OBJ_DIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${OBJ_DIR}
	${CC} ${FLAGS} -c $< -o $@

${LIBFT_A}:
	@make -C ${LIBFT}
	@cd ${LIBFT} && mv ${LIBFT_A} ..

${MINILIBX_A}:
	@make -C ${MINILIBX}
	@cd ${MINILIBX} && mv ${MINILIBX_A} ..
#################################################################################################################
#                                           RULES CLEAN                                                         #
#################################################################################################################
clean:
	rm -rf ${OBJ_DIR}/ ${OBJS}

clean_lib:
	@make clean -C ${LIBFT}
	@make clean -C ${MINILIBX}

fclean: clean
	rm -rf ${NAME}

fclean_lib: clean_lib
	@make fclean -C ${LIBFT}
	@rm -rf ${LIBFT_A}
	@make clean -C ${MINILIBX}
	@rm -rf ${MINILIBX_A}

re: fclean fclean_lib all
#################################################################################################################
#                                           NO RELINK                                                           #
#################################################################################################################

.PHONY: all clean fclean re clean_lib fclean_lib