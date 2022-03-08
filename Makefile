SRCS		= srcs/ft_printf.c \
			  converters/char.c \
			  converters/digit.c \
			  converters/hexa.c \
			  converters/hexa_cap.c \
			  converters/noarg.c \
			  converters/integer.c \
			  converters/string.c \
			  converters/pointer.c \
			  converters/unsigned.c \
			  flags/minimum_width.c \
			  flags/precision.c \
			  srcs/ft_printf_utils.c \
			  srcs/ft_params_handler.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

LIB			= libft.a

LIBHEADER	= libft.h

LIBDIR		= libft/

HEADERS		= includes/

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

CC			= gcc

AR			= ar rcs

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):	$(LIB) $(OBJS)
			$(AR) $(LIB) $(OBJS)
			@cp $(LIB) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BOBJS) $(LIB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

$(LIB):	
			@cd $(LIBDIR) && make bonus
			@cd $(LIBDIR) && make clean
			@cd $(LIBDIR) && mv $(LIB) ../

.PHONY:		all clean fclean c.o re


