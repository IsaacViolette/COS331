TARGET = ss.out
OBJS = ss.o 
CFLAGS = -Wall

all: ${TARGET}
${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean:
	rm -f ${TARGET} ${OBJS}
