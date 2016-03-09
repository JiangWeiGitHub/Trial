CallBack: main.o test.o
	cc -o CallBack main.o test.o

main.o: main.c test.h
	cc -c main.c

test.o: test.c test.h
	cc -c test.c


#edit : main.o kbd.o command.o display.o 
#    cc -o edit main.o kbd.o command.o display.o

#main.o : main.c defs.h
#    cc -c main.c
#kbd.o : kbd.c defs.h command.h
#    cc -c kbd.c


.PHONY: clean
clean:
	rm *.o CallBack
