NAME			=	cub3D

CFLAGS			=	-Wall -Wextra -g -fPIE

INC				=	-I inc/ -I libft/inc/ -I MLX42/include/MLX42/ 

SRC				=	src/main.c \
					src/init_data.c \
					src/images1.c \
					src/images2.c \
					src/movement.c \
					src/run_game.c \
					src/raycast.c \
					src/render.c \
					src/free_error_exit.c \
					src/extension.c\
					src/file.c \
					src/flood_fill.c \
					src/animation.c \
					src/map.c

OBJS 			=	${SRC:.c=.o}

START_MSG		=	.start_msg

LIBFT			=	libft/libft.a

MLX42			=	MLX42/libmlx42.a

BOLD			=	\033[1m
RED				=	\033[31;1m
GREEN			=	\033[32;1m
YELLOW			=	\033[33;1m
BLUE			=	\033[34;1m
MAGENTA			=	\033[35;1m
CYAN			=	\033[36;1m
NO_COLOR		=	\033[0m

${NAME}: ${LIBFT} ${MLX42} ${OBJS}
	@echo "${YELLOW}${BOLD}BUILDING GAME. PLEASE BE PATIENT... ${NO_COLOR}"
	@gcc $(CFLAGS) $(INC) $(OBJS) $(MLX42) $(LIBFT) -L/Users/$(USER)/.brew/opt/glfw/lib/ -lglfw -lm -o $(NAME)
	@echo "${GREEN}${BOLD}GAME COMPILED! ${NO_COLOR}"
	@echo "${CYAN}${BOLD}How to play? Enter ./cub3D <map> and enjoy!!! ${NO_COLOR}"

${LIBFT}:
	@echo "${YELLOW}${BOLD}BUILDING LIBFT. PLEASE BE PATIENT... ${NO_COLOR}"
	@make -C libft/ --silent
	@echo "${GREEN}${BOLD}LIBFT COMPILED! ${NO_COLOR}"

${MLX42}:
	@echo "${YELLOW}${BOLD}BUILDING MLX42. PLEASE BE PATIENT... ${NO_COLOR}"
	@make -C MLX42/ --silent
	@echo "${GREEN}${BOLD}MINILIBX COMPILED! ${NO_COLOR}"

START_MSG:
	@echo "${BLUE}${BOLD}WELCOME TO ${MAGENTA}${BOLD}CUB3D${NO_COLOR}${BLUE}${BOLD}, 42_MALAGA PROYECT FROM ${MAGENTA}${BOLD}JMARTOS-${NO_COLOR} ${BLUE}${BOLD}AND${NO_COLOR} ${MAGENTA}${BOLD}AROSAS-J${NO_COLOR} ${NO_COLOR}"
	@touch ${START_MSG}

src/%.o: src/%.c
	@gcc ${CFLAGS} ${INC} -c $< -o src/$(@F)

all: START_MSG ${NAME}

clean:
	@rm -rf ${OBJS}
	@make -C libft/ --silent clean
	@make -C MLX42/ --silent clean
	@echo "${GREEN}${BOLD}CLEANING PROTOCOL DONE! ${NO_COLOR}"

fclean: clean
	@rm -f ${NAME}
	@make -C libft/ --silent fclean
	@make -C MLX42/ --silent fclean
	@echo "${GREEN}${BOLD}FULL CLEANING PROTOCOL DONE! ${NO_COLOR}"

re: fclean all

.PHONY: all clean fclean re