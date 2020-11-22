a.out : main.o display.o bot.o
	gcc -o a.out main.o display.o bot.o

main.o : src/main.c include/display.h  include/bot.h
	gcc -c src/main.c
display.o : src/display.c include/display.h
	gcc -c src/display.c
bot.o : src/bot.c include/bot.h
	gcc -c src/bot.c

clean :
	rm a.out main.o display.o bot.o
