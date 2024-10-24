NAME = minishell
CC = cc -g
LIBFT_N = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC = 		./src/utils.c\
			./init_token/init_token.c\
			./init_token/token_utils.c\
			./init_token/assigne_type_token.c\
			./init_token/init_utils.c\
			./init_cmd/init_cmd_utils.c\
			./init_cmd/init_cmd.c\
			./init_cmd/init_rfile.c\
			./init_cmd/init_rfile_utils.c\
			./builtins/env/env_utils.c\
			./src/main.c
			
LIBFT_D = ./libft
OBJ = $(SRC:.c=.o)

all : $(NAME)
	
$(NAME) : $(SRC)
	@ make -C $(LIBFT_D)
	@ test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
	@ $(CC) $(CFLAGS) $(SRC) -L $(LIBFT_D) -l ft -o $(NAME) -lreadline
	@ echo "Make[OK]"
clean:
	@ make clean -C $(LIBFT_D)
	@ rm -f $(OBJ)
	@ echo "Make clean [OK]"

fclean: clean
	@ make fclean -C $(LIBFT_D)
	@ rm -f $(NAME)
	@ echo "Make clean [OK]"
	
re: fclean all

.PHONY: all clean fclean re