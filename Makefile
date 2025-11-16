NAME = solong.a

SOURCE = 	mapstuff.c \
		count_stuff.c \
		borders.c \
		main.c

HEADER = so_long.h

#CFLAGS += -Wall -Wextra -Werror

OBJECTS = $(SOURCE:.c=.o)

CC = cc

RM = rm -f

CREATION = ar rcs


.c.o:
	${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS} ${HEADER}
	${CREATION} ${NAME} ${OBJECTS}

clean:	
	${RM} ${OBJECTS}
fclean:	clean
		${RM} ${NAME}
re:		fclean all
all:	${NAME}
make:	make all


.PHONY: clean fclean re all
