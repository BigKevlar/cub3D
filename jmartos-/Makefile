NAME			= cub3D

CFLAGS			= -Wall -Wextra -Werror -g

INC				= -I inc/ -I ../libft/inc -I ../MLX42/include/MLX42

SRC				=	src/cub3D.c 

OBJS 			= ${SRC:.c=.o}

LIBFT			= ./libft/libft.a

MLX42			= ./MLX42/libmlx42.a

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
BLUE			=\033[34;1m
NO_COLOR		=\033[0m

${NAME}: ${LIBFT} ${MLX42} ${OBJS}
	@echo "${GREEN}${BOLD} GAME SUCCESSFULLY COMPILED ${END}"
	@gcc $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) -I inc -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@echo "${GREEN}${BOLD} WELCOME TO "CUB3D", 42_MALAGA PROYECT FROM ${BLUE}${BOLD} JMARTOS- ${END} AND ${BLUE}${BOLD} AROSAS-J ${END} ${END}"

${LIBFT}:
	@echo "${YELLOW}${BOLD} BUILDING LIBFT. PLEASE BE PATIENT... ${END}"
	@make -C ../libft/ --silent
	@echo "${GREEN}${BOLD} LIBFT COMPILED ${END}"

${MLX42}:
	@echo "${YELLOW}${BOLD} BUILDING MINILIBX, FROM CODAM-CODING-COLLEGE. PLEASE BE PATIENT... ${END}"
	@make -C ../MLX42/ --silent
	@echo "${GREEN}${BOLD} MINILIBX COMPILED ${END}"

src/%.o: src/%.c
	@gcc ${CFLAGS} ${INC} -c $< -o src/$(@F)

all: ${NAME}

clean:
	@rm -rf ${OBJS}
	@make -C ../libft/ clean
	@make -C ../MLX42/ clean
	@echo "${RED}${BOLD} CLEAN PROTOCOL: DELETING .o FILES... ${END}"

fclean: clean
	@rm -f ${NAME}
	@make -C ../libft/ fclean
	@make -C ../MLX42/ fclean
	@echo "${RED}${BOLD} FCLEAN PROTOCOL: DELETING .a FILES... ${END}"

re: fclean all
	@echo "${GREEN}${BOLD} RE PROTOCOL: RECOMPILATION SUCCESSFULL ${END}"

.PHONY: all clean fclean re