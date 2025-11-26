NAME = solong.a

SOURCE = 	mapstuff.c \
		count_stuff.c \
		borders.c \
		main.c

HEADER = so_long.h

CFLAGS += -Wall -Wextra -Werror -g -lmlx -lX11 -lXext -lm

OBJECTS = $(SOURCE:.c=.o)

CC = cc

RM = rm -f

CREATION = ar rcs


.c.o:
	${CC} libft/libft.a ${CFLAGS} -I . -c $< -o ${<:.c=.o} 

#${NAME}: ${OBJECTS} ${HEADER}
#	${CREATION} ${NAME} ${OBJECTS}

clean:	
	${RM} ${OBJECTS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
all:	${NAME}
make:	make all
aout:
	cc *c libft/libft.a -g -lmlx -lX11 -lXext -lm -Wall -Wextra -Werror


.PHONY: clean fclean re all
