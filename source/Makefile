jeucourse : main.o fonction.o
			gcc main.c $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf -o jeucourse

main.o : main.c fonction.h
			gcc -c main.c fonction.h

fonction.o : fonction.c fonction.h
			gcc -c fonction.c fonction.h

clear : jeucourse
			rm -f *.o
