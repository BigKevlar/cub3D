NAME			= test

CFLAGS			= -Wall -Wextra -Werror -g

INC				= -I libft/inc/ -I MLX42/include/MLX42/

SRC				= draw_line.c

OBJS 			= ${SRC:.c=.o}

LIBFT			= libft/libft.a

MLX42			= MLX42/libmlx42.a

BOLD			=\033[1m
RED				=\033[31;1m
GREEN			=\033[32;1m
YELLOW			=\033[33;1m
BLUE			=\033[34;1m
NO_COLOR		=\033[0m

${NAME}: ${LIBFT} ${MLX42} ${OBJS}
	@echo "${GREEN}${BOLD} GAME SUCCESSFULLY COMPILED ${NO_COLOR}"
	@gcc $(CFLAGS) $(INC) $(OBJS) -o $(NAME) $(MLX42) $(LIBFT) -lglfw -lm
	@echo "${GREEN}${BOLD} WELCOME TO "CUB3D", 42_MALAGA PROYECT FROM ${BLUE}${BOLD}JMARTOS-${NO_COLOR} ${GREEN}${BOLD}AND${NO_COLOR} ${BLUE}${BOLD}AROSAS-J${NO_COLOR} ${NO_COLOR}"

${LIBFT}:
	@echo "${YELLOW}${BOLD} BUILDING LIBFT. PLEASE BE PATIENT... ${NO_COLOR}"
	@make -C libft/ --silent
	@echo "${GREEN}${BOLD} LIBFT COMPILED ${NO_COLOR}"

${MLX42}:
	@echo "${YELLOW}${BOLD} BUILDING MLX42. PLEASE BE PATIENT... ${NO_COLOR}"
	@make -C MLX42/ --silent
	@echo "${GREEN}${BOLD} MINILIBX COMPILED ${NO_COLOR}"

%.o: %.c
	@gcc ${CFLAGS} ${INC} -c $< -o $(@F)

all: ${NAME}

clean:
	@echo "${YELLOW}${BOLD} CLEANING PROTOCOL. PLEASE BE PATIENT... ${NO_COLOR}"
	@rm -rf ${OBJS}
	@make -C libft/ --silent clean
	@make -C MLX42/ --silent clean

fclean: clean
	@rm -f ${NAME}
	@make -C libft/ --silent fclean
	@make -C MLX42/ --silent fclean

re: fclean all

.PHONY: all clean fclean re