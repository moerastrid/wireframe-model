NAME := fdf
CFLAGS := -g -Wall -Werror -Wextra
SRC = src/main.c\
	src/fill.c\
	src/wrap.c\
	src/colors.c\
	src/line.c\
	src/keypress.c\
	get_next_line_copy/get_next_line.c\
	get_next_line_copy/get_next_line_utils.c\
	src/libftfunctions.c\
	src/libftsplit.c\
	src/map.c\
	src/math.c\

GREEN = \x1b[32m
RESET = \033[0m
RED   = \x1b[31m

OBJ := $(patsubst src/%.c,obj/%.o,$(SRC))

all : $(NAME)

libmlx42.a :
	make -C MLX42/
	ln -s MLX42/libmlx42.a

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -o $@ -c $< -I MLX42/include -I ./

$(NAME) : $(OBJ) libmlx42.a
	$(CC) $(OBJ) libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

clean:
	@test -e obj && rm -fr obj && rm -fr libmlx42.a && make fclean -C MLX42/ || echo "$(GREEN)clean: No objects to clean$(RESET)"''

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all/ LIB/ clean/ fclean/ re/