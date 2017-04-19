#ifndef SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_gfxPrimitives.h"
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
#ifndef STRUCTS
#include "structs.h"
#define STRUCTS
#endif
#include "sstream"
using namespace std;
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void show_tree(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_box(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_pipe(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_cloud(int x, int y, int DATA_SCROLL_POSITION, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN);
void show_coin(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_bush(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_mushroom(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_earth(int DATA_SCROLL_POSITION, SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN);
void show_text(string text, int x, int y, SDL_Surface* DATA_SCREEN, TTF_Font *DATA_FONT, int size);
void show_level(int level, int DATA_SCROLL_POSITION, object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN);
void show_mario(mario myMario, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN);
void show_score_text(int &DATA_SCORE, SDL_Surface* DATA_SCREEN,TTF_Font *DATA_FONT);
void show_level_text(int &DATA_LEVEL, SDL_Surface* DATA_SCREEN,TTF_Font *DATA_FONT);
void show_enemy(enemy &myEnemy,SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN, int DATA_SCROLL_POSITION);