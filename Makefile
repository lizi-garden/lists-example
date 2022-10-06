C_FLAG=-g

build:main.o lists.o
	$(CC) main.o lists.o -o lists $(C_FLAG)

main.o:main.c
	$(CC) -c main.c $(C_FLAG)

lists.o:lists.c lists.h
	$(CC) -c lists.c $(C_FLAG)

clean:
	rm lists main.o lists.o

.PHONY: build clean
