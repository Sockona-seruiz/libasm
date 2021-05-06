NAME = libasm.a

ASM = nasm
ASMFLAG = -fmacho64

SRC =	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

SRCBONUS = ft_list_size_bonus.s

OBJ_BONUS = $(OBJ) $(SRCBONUS:.s=.o)
OBJ = $(SRC:.s=.o)

%.o: 		%.s
			${ASM} ${ASMFLAG} $< -o $@

${NAME}:	${OBJ}
			ar rcs ${NAME} ${OBJ}

all:		${NAME}

bonus :	${OBJ_BONUS}
			ar rcs ${NAME} ${OBJ_BONUS}

clean:
			rm -f ${OBJ}

fclean: 	clean
			rm -f ${NAME}

re: 		fclean all

.PHONY : clean all re fclean bonus