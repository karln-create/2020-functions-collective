a.exe: main.o prob6.o
	gcc -o a main.o prob6.o

main.o: main.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c main.c

prob6.o: prob6.c root.h
	gcc -Wall -Wextra -Wconversion -std=gnu11 -g -c prob6.c
clean:
	del a.exe main.o prob6.o