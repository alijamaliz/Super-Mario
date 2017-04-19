#include "structs.h"
void mario::change_mario_surface(SDL_Surface** DATA_OBJECTS_SURFACES)
{
    image = DATA_OBJECTS_SURFACES[status];
}
void mario::grow()
{
    if (status < 10) 
    	status += 10;
}
void mario::shrink()
{
    if (status > 9) 
    	status -= 10;
}
void enemy::move_enemy()
{
    if (x > endx)
    {
        v*=(-1);
        status = 37;
    }
    if (x < startx)
    {
        v*=(-1);
        status = 34;
    }
    x += v;
}
void enemy::change_enemy_surface(SDL_Surface** DATA_OBJECTS_SURFACES)
{
    image = DATA_OBJECTS_SURFACES[status];
}