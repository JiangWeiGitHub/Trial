SimpleFactory: main.o
	g++ -o SimpleFactory main.o

main.o: main.cpp factory.h
	g++ -c main.cpp

.PHONY: clean
clean:
	rm *.o SimpleFactory

