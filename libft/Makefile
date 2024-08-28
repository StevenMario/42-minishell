NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES =	ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_bzero.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strchr.c \
		ft_free_str.c\
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_substr.c \
		ft_strjoin.c \
		get_next_line_utils.c\
		get_next_line.c\
		ft_striteri.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_split.c\
		ft_print_char.c\
		print_int.c\
		print_str.c\
		print_unsigned_dec.c\
		print_hex.c\
		print_adress_hex.c\
		ft_printf.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) libft.h
	ar rc $(NAME) $(OFILES)
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
