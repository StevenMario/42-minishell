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
			./init_cmd/init_cmd_utils_2.c\
			./init_cmd/init_cmd.c\
			./init_cmd/init_rfile.c\
			./init_cmd/init_rfile_utils.c\
			./builtins/env/env_utils.c\
			./builtins/env/env_utils_2.c\
			./builtins/env/m_env.c\
			./builtins/m_echo.c\
			./init_cmd/gestion_herdoc.c\
			./init_cmd/processing_utils.c\
			./init_token/expand_token.c\
			./init_token/expand_utils.c\
			./builtins/export/m_export.c\
			./builtins/exit/m_exit.c\
			./builtins/exit/exit_utils.c\
			./builtins/export/export_utils.c\
			./builtins/m_unset.c\
			./builtins/m_pwd.c\
			./builtins/m_cd.c\
			./execution/exec_no_builtins.c\
			./execution/exec_no_builtins_utils.c\
			./execution/exec_builtins.c\
			./execution/exec.c\
			./execution/exec_utils.c\
			./execution/exec_redir.c\
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

run: re
	clear
	./$(NAME)
	
gdb: re
	clear
	gdb ./$(NAME)

leak: re
	clear
	valgrind --suppressions=readline.sup --leak-check=full --show-leak-kinds=all ./$(NAME)

leak\:%: re
	clear
	valgrind --suppressions=$(subst leak:,,$@).sup --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re