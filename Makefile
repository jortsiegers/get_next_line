# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: jsiegers <jsiegers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/25 00:22:23 by jsiegers      #+#    #+#                  #
#    Updated: 2022/01/07 21:21:01 by jsiegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS	= 
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}
NAME	= get_next_line.a
ILINE	= ${addprefix -Ilibs/, ${LIBS}}
LIBP	= ${join ${addprefix libs/, ${LIBS}},${addsuffix .a, ${addprefix /, ${LIBS}}}}

.c.o:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c ${ILINE} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@rm -rf tmp
	@mkdir tmp
	@for lib in ${LIBS};\
	do\
		echo Checking if $${lib} is compiled...;\
		cd libs/$${lib} && make > /dev/null 2>&1;\
		cd ../../tmp;\
		ar -x ../libs/$${lib}/$${lib}.a;\
		ar -t ../libs/$${lib}/$${lib}.a | xargs ar rc ../${NAME} && cd ..;\
	done
	@echo Compiling ${NAME}
	@ar rc ${NAME} ${OBJS}
	@rm -rf tmp

all: ${NAME}

clone:
	@for lib in ${LIBS};\
	do\
		git clone git@github.com:jortsiegers/$${lib}.git libs/$$lib > /dev/null 2>&1;\
		cd libs/$${lib} && make clone > /dev/null 2>&1;\
		echo Cloning $${lib}...;\
	done

clean:
	@for lib in ${LIBS};\
	do\
		cd libs/$${lib} && make clean > /dev/null 2>&1;\
	done
	@echo Cleaning ${NAME}...;
	@rm -f ${OBJS}

fclean:
	@for lib in ${LIBS};\
	do\
		cd libs/$${lib} && make fclean > /dev/null 2>&1;\
	done
	@echo FCleaning ${NAME}...;
	@rm -f ${OBJS}
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o clone
