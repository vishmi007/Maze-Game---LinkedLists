CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o array.o control.o terminal.o LinkedList.o
EXEC = maze

ifdef DARK
CFLAGS += -D DARK
DARK : clean $(EXEC)
endif


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c array.h
	$(CC) $(CFLAGS) main.c -c 
array.o : array.c array.h 
	$(CC) $(CFLAGS) array.c -c 
control.o : control.c control.h array.h terminal.h
	$(CC) $(CFLAGS) control.c -c
terminal.o : terminal.c terminal.h 
	$(CC) $(CFLAGS) terminal.c -c
LinkedList.o : LinkedList.c LinkedList.h 
	$(CC) $(CFLAGS) LinkedList.c -c


clean :
	rm -f $(EXEC) $(OBJ)
