all: jogodavida

jogodavida: jogodavida.o 
	gcc jogodavida.o -o jogodavida

jogodavida.o: jogodavida.c
	gcc -c jogodavida.c

clean: 
	rm -rf *o jogodavida
