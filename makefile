all: jogodavida

lifegame: main.o 
  gcc	main.o -o jogodavida

main.o: main.c
	gcc -c main.c

clean: 
	rm -rf *o jogodavida
