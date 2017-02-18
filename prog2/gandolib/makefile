nomefile: main.o gandolib.o
	gcc -o nomefile -g main.o gandolib.o

main.o: main.c gandolib.h
	gcc -c -g main.c

gandolib.o: gandolib.c gandolib.h
	gcc -c -g -Wfatal-errors gandolib.c
