CallBack: main.o test.o
	cc -o CallBack main.o test.o

main.o: main.c test.h
	cc -c main.c

test.o: test.c test.h
	cc -c test.c

.PHONY: clean
clean:
	rm *.o CallBack
