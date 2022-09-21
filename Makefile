
build:main.o numlists.o
	$(CC) main.o numlists.o -o numlists

main.o:main.c
	$(CC) -c main.c

numlists.o:numlists.c numlists.h
	$(CC) -c numlists.c

clean:
	rm numlists main.o numlists.o

.PHONY: build clean
