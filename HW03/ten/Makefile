TARGET = ten.out
OBJS = ten.o 
CFLAGS = -Wall -lpthread

all: ${TARGET}
${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean:
	rm -f ${TARGET} ${OBJS}
