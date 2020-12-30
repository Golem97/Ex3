CC= gcc
AR=ar
FLAGS= -Wall

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c
	
txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c
	
.PHONY: clean all

clean:
	rm -f *.o isort txtfind

