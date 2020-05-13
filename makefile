a.exe: main.o prob7.o
	gcc -o a main.o prob7.o

main.o: main.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c main.c

prob7.o: prob7.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c prob7.c
clean:
	del a.exe main.o prob7.o