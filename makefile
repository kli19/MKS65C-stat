all: stat.o
	gcc stat.o

stat.o: stat.c
	gcc -c stat.c

clean:
	rm *.o
	rm a.out
	rm *.txt

run:
	./a.out
