all: hw10.o
	gcc -o hw10 hw10.o

hw10.o: hw10.c
	gcc -c hw10.c

run:
	./hw10

clean:
	rm *.o
	rm *~
