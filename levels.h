#ifndef CONFIG
#include "config.h"
#define CONFIG
#endif
#ifndef STRUCTS
#include "structs.h"
#define STRUCTS
#endif
#ifndef SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_gfxPrimitives.h"
#define SDL
#endif
void setup_levels(object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES);
void setup_enemy(enemy &myEnemy, SDL_Surface** DATA_OBJECTS_SURFACES, int DATA_LEVEL);