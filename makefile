a.exe: main.o prob1extra.o
	gcc -o a main.o prob1extra.o

main.o: main.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c main.c

prob1extra.o: prob1extra.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c prob1extra.c
clean:
	del a.exe main.o prob1extra.o