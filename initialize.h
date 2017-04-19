#ifndef SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#define SDL
#endif
#ifndef STRING
#include "string"
#define STRING
#endif
#ifndef CONFIG
#include "config.h"
#define CONFIG
#endif
using namespace std;
bool init_sdl();
bool init_screen(SDL_Surface* DATA_SCREEN);
bool init_sounds(Mix_Chunk **DATA_SOUNDS);
SDL_Surface *load_image( string filename );
bool init_surfaces(SDL_Surface** DATA_OBJECTS_SURFACES);
bool init_fonts();
bool free_fonts();
bool free_sounds(Mix_Chunk **DATA_SOUNDS, Mix_Music *music);