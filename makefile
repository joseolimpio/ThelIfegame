all: lifegame

lifegame: main.o 
  gcc	main.o -o lifegame

main.o: main.c
	gcc -c main.c

clean: 
	rm -rf *o lifegame	
