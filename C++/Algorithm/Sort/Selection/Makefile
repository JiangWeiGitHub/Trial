build : main.o Selection.o
	g++ -o build main.o Selection.o

main.o : main.cpp Selection.h
	g++ -g -c main.cpp

Selection.o : Selection.h Selection.cpp
	g++ -g -c Selection.cpp

clean :
	rm *.o build