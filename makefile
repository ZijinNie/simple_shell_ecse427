CC= gcc
CFLOAGS = -I





all: shell.o shellmemory.o interpreter.o
	%(CC) -o mysh shell.o shellmemory.o interpreter.o
shell.o: shell.c
	gcc -c shell.c
shellmemory.o: shellmemory.c
	gcc -c shellmemory.c
interpreter.o: interpreter.c
	gcc -c interpreter.c
