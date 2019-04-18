#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")



#include <iostream>

using namespace std;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


//Starts up SDL and creates window
bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

//Loads media
bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

bool loadMedia2() {
	bool success = true;
	//Load 2nd splash image
	gHelloWorld = SDL_LoadBMP("POOTIS.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "POOTIS.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

bool loadMedia3() {
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("USSREMBLEM.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "USSREMBLEM.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main(int argc, char* args[]) {
	//Start up SDL and create window
	int cntinu = 0;
	do {
		if (!init())
		{
			printf("Failed to initialize!\n");
		}
		else
		{
			//Load media
			if (!loadMedia())
			{
				printf("Failed to load media!\n");
			}
			else
			{
				int tfmenu;
				cout << "Please select a sound" << endl << " " << endl << "1 - Scout Demon Taunt" << endl << "2 - Soldier Demon Threat" << endl << "3 - Pyro" << endl << "4 - Demoman Demonic Screaming" << endl << "5 - Heavy Sad" << endl << "6 - Engineer" << endl << "7 - Medic" << endl << "8 - Sniper Good Shot Hurty" << endl << "9 - Spy" << endl << "10 - USSR Anthem Earrape" << endl;
				cin >> tfmenu;


				//Deallocate surface & Change Image
				SDL_FreeSurface(gHelloWorld);
				gHelloWorld = NULL;
				if (tfmenu == 5) {
					gHelloWorld = SDL_LoadBMP("POOTIS.bmp");
				}
				else if (tfmenu == 10) {
					gHelloWorld = SDL_LoadBMP("USSREMBLEM.bmp");
				}
				//Apply the new image
				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);

				//Play Sound
				if (tfmenu == 5) {
					PlaySound("defopoot.wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				else if (tfmenu == 4) {
					PlaySound("When DeadFace queues as Demoman.wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				else if (tfmenu == 10) {
					PlaySound("Soviet National Anthem (EAR RAPE)(1).wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				else if (tfmenu == 1) {
					PlaySound("scout_revenge03.wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				else if (tfmenu == 8) {
					PlaySound("sniper_niceshot02.wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				else if (tfmenu == 2) {
					PlaySound("soldier_taunts07.wav", NULL, SND_FILENAME);
					SDL_DestroyWindow(gWindow);
				}
				cout << "Select new?: " << endl << "0 yes 1 no" << endl;
				cin >> cntinu;
				
			}
		}
	} while (cntinu == 0);
	//Free resources and close SDL
	close();



	return 0;
}