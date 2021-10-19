all: main.o poke.o
	gcc -o pokemon main.o poke.o

main.o: main.c poke.h
	gcc -c main.c

poke.o: poke.c poke.h
	gcc -c poke.c

run:
	./pokemon

clean:
	rm *.o
	rm *~
