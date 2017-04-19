#ifndef SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_gfxPrimitives.h"
#define SDL
#endif
struct mario {
    int x;
    int y, y0;
    int vx, vy, vy0;
    int status;
    int walk_counter;
    bool is_hidden;
    int hidden_counter;
    SDL_Surface* image;
    void change_mario_surface(SDL_Surface** DATA_OBJECTS_LOCATION);
    void grow();
    void shrink();
};

struct object{
    int x,y;
};

struct enemy
{
	int startx, endx;
	int x, y;
	int v;
	int status;
	void move_enemy();
	void change_enemy_surface(SDL_Surface** DATA_OBJECTS_LOCATION);
	int walk_counter;
	SDL_Surface* image;
};