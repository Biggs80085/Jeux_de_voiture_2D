#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"


#define sX 800
#define sY 600
//**********PROJET 3eme ETAPE ; Yassine ZERBAN




int main(int argc, char *argv[])
{

	FILE * file;
	zone * sZone;


	int h, w, nombre;
	int sYDepart, sXDepart, sYArrive, sXArrive;
	float carAngle;
	char path[100], car[100];
	int circuit[6][8];
	int j, z;
	int i=1, k=0;
	float velocity = 0, velocity_limit= 3, angle_add;
	float x =100, y=200;
	int temps0 = 0,temps1, maxTours = 3, nowTour = 0, countdown = 3;



	file = fopen(argv[1], "r");
	if (file ==NULL)
		printf("ERREUR\n");
	else
	{

	//--------------------TAILLE--------------------


  if (file ==NULL)
  {
    printf("Le fichier ne s'ouvre pas \n");
    exit(EXIT_FAILURE);
  }
  fscanf(file, "%*s %d %d", &w, &h);

  fscanf(file, "%*s %s", path);

  fscanf(file, "%*s %d", &nombre);

  fscanf(file, "%*s %s", car);

  sZone =  malloc((nombre-2)*sizeof(zone));

  for(int i=0; i < nombre-2 ; ++i)
  {
    sZone[i].pathZone = malloc((nombre-2)*sizeof(sZone[i].pathZone));

    fscanf(file, "%*s %d %s", &sZone[i].numeroZone, sZone[i].pathZone);
  }

  fscanf(file, "%*s %d %d", &sXDepart, &sYDepart);

  fscanf(file, "%*s %d %d", &sXArrive, &sYArrive);

  fscanf(file, "%*s %f", &carAngle);

  for (int i = 0; i < h ; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      fscanf(file,"%d", &circuit[i][j]);
    }
  }

  fclose(file);


}
TTF_Init();
TTF_Font *f = TTF_OpenFont("selphia.ttf", 40);
// Lancement du SDL avec un deboggeur si jamais il y a une erreur...
  if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      SDL_Log("(?) ERROR1: %s\n", SDL_GetError());
      destroyElements(NULL, NULL, NULL);
      exit(EXIT_FAILURE);
    }
//creation du 'window' pour créer le renderer dedans...
SDL_Window *wdw = NULL;
			wdw = SDL_CreateWindow("Projet C_voitures", sX-(sX/2), sY-(sY/2), sX, sY, 0);


 // creation du renderer avec lequel on va afficher le contenu ( texture ,images, etc...)
SDL_Renderer *rdr = NULL;
			  rdr = SDL_CreateRenderer(wdw, -1, SDL_RENDERER_PRESENTVSYNC);

  if (wdw == NULL)
    {
      SDL_Log("(?) ERROR2: %s\n", SDL_GetError());
      destroyElements(NULL, NULL, NULL);
      exit(EXIT_FAILURE);
    }
  if (rdr == NULL)
    {
      SDL_Log("(?) ERROR3: %s\n", SDL_GetError());
      destroyElements(wdw, NULL, NULL);
      exit(EXIT_FAILURE);
    }

//creation de la texture....
SDL_Texture *bg = NULL;

    bg = IMG_LoadTexture(rdr, path);
    if (bg == NULL)
    {
       SDL_Log("(?) ERROR3:%s\n", SDL_GetError());
       destroyElements(wdw, rdr, NULL);
       exit(EXIT_FAILURE);
    }


     SDL_Texture * route = NULL;


    SDL_Texture * voiture = NULL;
    voiture = IMG_LoadTexture(rdr, car);
    if (voiture == NULL)
    {
       SDL_Log("(?) ERROR4:%s\n", SDL_GetError());
       destroyElements(wdw, rdr, NULL);
       exit(EXIT_FAILURE);
    }
    SDL_Rect rectVoiture = {135, 235, 30, 60};
    rectVoiture.x = x, rectVoiture.y = y;

		SDL_Event events;
		int isFileOpen = 0;

			SDL_Texture *menuAff = IMG_LoadTexture(rdr, "../img/menuIMG.png") ;
			SDL_RenderCopy(rdr, menuAff,NULL, NULL);


	 while(!isFileOpen)
     {

        while(SDL_PollEvent(&events))
        {

                //fonction du menu
								SDL_RenderPresent(rdr);

            switch(events.type)
            {

                case SDL_KEYDOWN:
                switch(events.key.keysym.sym)
                {
                    case SDLK_1:


  //-------------------------------course----------------------------------------------------------
                    while (!isFileOpen) {
                    	temps1 = SDL_GetTicks();
						while (SDL_PollEvent(&events)){
							switch (events.type) {
								case SDL_QUIT:
									isFileOpen = 1;
									break;
								case SDL_KEYDOWN:
									switch (events.key.keysym.sym) {
										case SDLK_ESCAPE:
											isFileOpen = 1;
											break;
										case SDLK_UP:
											velocity = velocity + 0.1;
											break;
										case SDLK_DOWN:
											velocity = velocity - 0.1;
											break;
										case SDLK_RIGHT:
											angle_add = 1;
											break;
										case SDLK_LEFT:
											angle_add = -1;
											break;
									}
									break;
								case SDL_KEYUP:
									switch (events.key.keysym.sym) {

										case SDLK_UP:
										if (velocity > 0 )
											velocity =0;
											break;
										case SDLK_DOWN:
										if (velocity < 0 )
											velocity = 0;
											break;
										case SDLK_RIGHT:
											angle_add = 0;
											break;
										case SDLK_LEFT:
											angle_add = 0;
											break;
									}
						}

				}

				carAngle = carAngle + angle_add;

				if (velocity > velocity_limit)
						velocity = velocity_limit;
						carAngle = carAngle + angle_add;
						x += velocity*sin(carAngle/180*3.14);
						y += -velocity*cos(carAngle/180*3.14);

						rectVoiture.x = x, rectVoiture.y = y;
              SDL_RenderClear(rdr);


				SDL_RenderCopy(rdr, bg, NULL, NULL);

				for (i = 0; i < h; i++)
				{
					for (j = 0; j < w ; j++)
					{
						SDL_Rect rectRoute = {100*j, 100*i, 100, 100};
						if(circuit[i][j] != 0)
								{
									z = circuit[i][j];
									route = IMG_LoadTexture(rdr, sZone[z].pathZone);
									SDL_RenderCopy(rdr, route , NULL, &rectRoute);
								 }
						}
				}

				if(countdown >=0)
				{
					cd(rdr, f, countdown);
					countdown--;
				}

				SDL_RenderCopyEx(rdr, voiture, NULL, &rectVoiture, carAngle, NULL, SDL_FLIP_NONE);

				if(temps1 > 0)
            		info(rdr, f ,temps1);
        		else
          			looser(rdr, f);

          		nbTour(rdr, f, nowTour , maxTours);

          		if(rectVoiture.x>sXArrive*sX/w
         		 && rectVoiture.x<sXArrive*sX/w + sX/w
          		&& rectVoiture.y >sYArrive*sY/h
          		&& rectVoiture.y <sYArrive*sY/h + sY/h)
       			 {
            		if(nowTour< 3 && (temps1 -temps0) > 10000)
                		nowTour++;

					else if(nowTour==3)
                    	podium(rdr, f);

            		temps0=temps1;
        }

				SDL_RenderPresent(rdr);
        		}

//--------------------------


//***********************************************

//**********************************************
   				 destroyElements(wdw,rdr,bg);
				free(sZone);
				break;
  //-------------------------------------------------------------------------------------------------


                            case SDLK_2:


  //---------------------------------------contre la montre--------------------------------------------------
                while (!isFileOpen) {
				while (SDL_PollEvent(&events)){
          temps1= 2000000 - SDL_GetTicks();
						switch (events.type) {
							case SDL_QUIT:
								isFileOpen = 1;
								break;
							case SDL_KEYDOWN:
									switch (events.key.keysym.sym) {
										case SDLK_ESCAPE:
												isFileOpen = 1;
												break;
											case SDLK_UP:
													velocity = velocity + 0.1;
													break;
											case SDLK_DOWN:
													velocity = velocity - 0.1;
													break;
											case SDLK_RIGHT:
													angle_add = 1;
													break;
											case SDLK_LEFT:
													angle_add = -1;
													break;


									}
									 break;
								case SDL_KEYUP:
									switch (events.key.keysym.sym) {

										case SDLK_UP:
												if (velocity > 0 )
											velocity =0;
											break;
										case SDLK_DOWN:
											if (velocity < 0 )
											velocity = 0;
											break;
										case SDLK_RIGHT:
											angle_add = 0;
											break;
										case SDLK_LEFT:
											angle_add = 0;
											break;
									}
						}

				}

				carAngle = carAngle + angle_add;

				if (velocity > velocity_limit)
						velocity = velocity_limit;
						carAngle = carAngle + angle_add;
						x += velocity*sin(carAngle/180*3.14);
						y += -velocity*cos(carAngle/180*3.14);

						rectVoiture.x = x, rectVoiture.y = y;
            SDL_RenderClear(rdr);


							SDL_RenderCopy(rdr, bg, NULL, NULL);

				for (i = 0; i < h; i++)
				{
					for (j = 0; j < w ; j++)
					{
								SDL_Rect rectRoute = {100*j, 100*i, 100, 100};
						if(circuit[i][j] != 0)
								{
										 z = circuit[i][j];
										 route = IMG_LoadTexture(rdr, sZone[z].pathZone);
										 SDL_RenderCopy(rdr, route , NULL, &rectRoute);
								 }
						}
				}
				if(countdown >=0)
        {
          cd(rdr, f, countdown);
          countdown--;
        }

        SDL_RenderCopyEx(rdr, voiture, NULL, &rectVoiture, carAngle, NULL, SDL_FLIP_NONE);

            if(temps1 > 0)
                info(rdr, f ,temps1);
            else
                looser(rdr, f);

              nbTour(rdr, f, nowTour , maxTours);

              if(rectVoiture.x>sXArrive*sX/w
             && rectVoiture.x<sXArrive*sX/w + sX/w
              && rectVoiture.y >sYArrive*sY/h
              && rectVoiture.y <sYArrive*sY/h + sY/h)
             {
                if(nowTour< 3 && (temps1 -temps0) > 10000)
                    nowTour++;

          else if(nowTour==3)
                      podium(rdr, f);

                temps0=temps1;
        }


        SDL_RenderPresent(rdr);

		}

//--------------------------

   				 destroyElements(wdw,rdr,bg);
				free(sZone);


  //-------------------------------------------------------------------------------------------------
                                break;


                            case SDLK_3:
                                isFileOpen = 1;
                                break;
                        }
                        break;
                    case SDL_KEYUP:
                        break;
                    case SDL_QUIT:
                        isFileOpen = 1;
                        break;
                    default:
                        break;
                }

        }
    }


    //------------------------------------------------------------------------------
		SDL_DestroyTexture(menuAff);
    return EXIT_SUCCESS;
}
