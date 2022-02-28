#ifndef FONCTION_H
#define FONCTION_H




#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>



#define sX 800
#define sY 600


typedef struct zone
{
	int numeroZone;
	char *pathZone;
}zone;




void destroyElements(SDL_Window *wdw, SDL_Renderer *rdr, SDL_Texture *txtr);

void podium(SDL_Renderer *rdr, TTF_Font *f);

void looser(SDL_Renderer *rdr, TTF_Font *f);

void cd(SDL_Renderer *rdr, TTF_Font *f, int commencer);

void nbTour(SDL_Renderer * rdr ,TTF_Font *f, int nowTour, int maxTour);

void info(SDL_Renderer *rdr, TTF_Font *f, int timee);

#endif
