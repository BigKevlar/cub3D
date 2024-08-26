NAME	= map
LIBMLX	= ./MLX42

HEADERS	= -I map.h -I $(LIBMLX)/include
LIBGL	= -lglfw -L"/Users/arosas-j/.brew/opt/glfw/lib" -lm
LIBS	= $(LIBGL) $(LIBMLX)/libmlx42.a
SRCS	= game_to_window.c map.c moves.c textures.c draw_line.c
OBJS	= $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	
re: clean all

.PHONY: all, clean, fclean, re, libmlx