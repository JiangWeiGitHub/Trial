AbstractFactory: main.o
	g++ -o AbstractFactory main.o

main.o: main.cpp AbstractFactory.h
	g++ -c main.cpp

.PHONY: clean
clean:
	rm *.o AbstractFactory

