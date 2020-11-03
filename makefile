a.out : main.o display.o
	gcc -o a.out main.o display.o

main.o : src/main.c include/display.h 
	gcc -c src/main.c
display.o : src/display.c include/display.h
	gcc -c src/display.c
clean :
	rm a.out main.o display.o
