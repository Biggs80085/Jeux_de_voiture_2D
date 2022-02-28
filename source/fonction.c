#include "fonction.h"





void destroyElements(SDL_Window *wdw, SDL_Renderer *rdr, SDL_Texture *txtr) {
	if ( wdw != NULL || rdr != NULL || txtr != NULL )
	SDL_DestroyRenderer(rdr);
	SDL_DestroyTexture(txtr);
	SDL_DestroyWindow(wdw);

    SDL_Quit();
}


void podium(SDL_Renderer *rdr, TTF_Font *f)
{
	SDL_Surface *surfaceT;
    SDL_Texture *textureT;
    SDL_Color couleurF = {255,255,255,255};
    SDL_Rect rect = {sX/2-150,sY/2-75,300,150};

    surfaceT = TTF_RenderText_Solid(f, "T AS GAGNE", couleurF);

    textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);

    SDL_RenderCopy(rdr, textureT, NULL, &rect);
    //SDL_RenderPresent(rdr);

    SDL_FreeSurface(surfaceT);
    SDL_DestroyTexture(textureT);
}

void looser(SDL_Renderer *rdr, TTF_Font *f)
{
	SDL_Surface *surfaceT;
    SDL_Texture *textureT;
    SDL_Color couleurF = {255,255,255,255};
    SDL_Rect rect = {sX/2-150,sY/2-75,300,150};

    surfaceT = TTF_RenderText_Solid(f, "T AS PERDU", couleurF);

    textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);

    SDL_RenderCopy(rdr, textureT, NULL, &rect);
    //SDL_RenderPresent(rdr);

    SDL_FreeSurface(surfaceT);
    SDL_DestroyTexture(textureT);
}


void cd(SDL_Renderer *rdr, TTF_Font *f, int commencer)
{

      SDL_Surface *surfaceT;
      SDL_Texture *textureT;

      SDL_Color couleurF = {0, 0, 0, 0};
      SDL_Rect rect;
      rect.w = 250;
      rect.h = 300;
      rect.x = sX/2-rect.w / 2;
      rect.y = sY/2-rect.h / 2;

      switch (commencer)
      {
        case 3:
            surfaceT = TTF_RenderText_Solid(f, "3", couleurF);
            textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);
            SDL_RenderCopy(rdr, textureT, NULL, &rect);
            SDL_RenderPresent(rdr);
            SDL_Delay(1000);
            break;

        case 2:
            surfaceT = TTF_RenderText_Solid(f, "2", couleurF);
            textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);
            SDL_RenderCopy(rdr, textureT, NULL, &rect);
            SDL_RenderPresent(rdr);
            SDL_Delay(1000);
            break;

        case 1:
            surfaceT = TTF_RenderText_Solid(f, "1", couleurF);
            textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);
            SDL_RenderCopy(rdr, textureT, NULL, &rect);
            SDL_RenderPresent(rdr);
            SDL_Delay(1000);
            break;

        case 0:
            surfaceT = TTF_RenderText_Solid(f, "GO", couleurF);
            textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);
            SDL_RenderCopy(rdr, textureT, NULL, &rect);
            SDL_RenderPresent(rdr);
            SDL_Delay(200);
            break;

        default:
            break;
        }
    SDL_FreeSurface(surfaceT);
    SDL_DestroyTexture(textureT);
}



void nbTour(SDL_Renderer * rdr ,TTF_Font *f, int nowTour, int maxTour)
{

	  SDL_Rect rect;
      rect.w = 150;
      rect.h = 75;
      rect.x = rect.w / 2;
      rect.y = rect.h / 2;

      SDL_Color couleurF = {0, 0, 0, 0};
      SDL_Surface *surfaceT;
      SDL_Texture *textureT;
      char text[200];

      sprintf(text , "%d/%d ",nowTour,  maxTour);

      surfaceT = TTF_RenderText_Solid(f, text, couleurF);
      textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);
      SDL_RenderCopy(rdr, textureT, NULL, &rect);
      //SDL_RenderPresent(rdr);

      SDL_FreeSurface(surfaceT);
      SDL_DestroyTexture(textureT);
}


void info(SDL_Renderer *rdr, TTF_Font *f, int timee)
{

    SDL_Rect rect= {400-100/2,10,100,50};

    SDL_Color couleurF = {255,255,255,255};
    SDL_Surface *surfaceT;
    SDL_Texture *textureT;
    char text[255];

    int second = (timee/1000) % 60;
    int minute = (timee/1000) / 60;


    sprintf(text, "%.2d:%.2d ", minute, second);


    surfaceT = TTF_RenderText_Solid(f, text, couleurF);

    textureT = SDL_CreateTextureFromSurface(rdr, surfaceT);

    SDL_RenderCopy(rdr, textureT, NULL, &rect);
    //SDL_RenderPresent(rdr);

    SDL_FreeSurface(surfaceT);
    SDL_DestroyTexture(textureT);
}
