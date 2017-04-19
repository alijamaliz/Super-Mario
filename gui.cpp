#include "gui.h"
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
}
void show_tree(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[20]->h,DATA_OBJECTS_SURFACES[20],DATA_SCREEN );
}
void show_box(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,y,DATA_OBJECTS_SURFACES[32],DATA_SCREEN);
}
void show_pipe(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[23]->h,DATA_OBJECTS_SURFACES[23],DATA_SCREEN );
}
void show_cloud(int x, int y, int DATA_SCROLL_POSITION, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,y,DATA_OBJECTS_SURFACES[25],DATA_SCREEN );
}
void show_coin(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,y,DATA_OBJECTS_SURFACES[30],DATA_SCREEN );
}
void show_bush(int x, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[27]->h,DATA_OBJECTS_SURFACES[27],DATA_SCREEN );
}
void show_mushroom(int x,int y, int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    apply_surface(x + DATA_SCROLL_POSITION,y,DATA_OBJECTS_SURFACES[22],DATA_SCREEN );
}
void show_earth(int DATA_SCROLL_POSITION, SDL_Surface** DATA_OBJECTS_SURFACES,SDL_Surface* DATA_SCREEN)
{
    int w = DATA_OBJECTS_SURFACES[31]->w;
    for (int i = 0; i < (get_levels_width() / w) + 1; i++)
        apply_surface((i*w) + DATA_SCROLL_POSITION,get_screen_height() - get_earth_height(),DATA_OBJECTS_SURFACES[31],DATA_SCREEN );
}
void show_text(string text, int x, int y, SDL_Surface* DATA_SCREEN, TTF_Font *DATA_FONT, int size)
{
    SDL_Color textColor = {255,255,255};
    if(text == "Super Mario")
    {
        textColor.r = 0;
        textColor.g = 217;
        textColor.b = 151;
    }
    DATA_FONT = TTF_OpenFont( "resources/fonts/SCRIPTBL.TTF", size );
    SDL_Surface* text_surface = TTF_RenderText_Solid( DATA_FONT, text.c_str(), textColor );
    apply_surface( x, y, text_surface, DATA_SCREEN);
    SDL_FreeSurface( text_surface );
    TTF_CloseFont( DATA_FONT );
}
void show_level(int level, int DATA_SCROLL_POSITION, object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN)
{
    show_earth(DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<5;i++)
        show_cloud(DATA_LOCATION_OBJECTS[level-1][2][i].x,DATA_LOCATION_OBJECTS[level-1][2][i].y,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<5;i++)
        show_tree(DATA_LOCATION_OBJECTS[level-1][0][i].x,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<3;i++)
        show_box(DATA_LOCATION_OBJECTS[level-1][1][i].x,DATA_LOCATION_OBJECTS[level-1][1][i].y,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<1;i++)
        show_mushroom(DATA_LOCATION_OBJECTS[level-1][3][i].x,DATA_LOCATION_OBJECTS[level-1][3][i].y,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<3;i++)
        show_bush(DATA_LOCATION_OBJECTS[level-1][4][i].x,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<10;i++)
        show_coin(DATA_LOCATION_OBJECTS[level-1][5][i].x,DATA_LOCATION_OBJECTS[level-1][5][i].y,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
    for(int i=0;i<2;i++)
        show_pipe(DATA_LOCATION_OBJECTS[level-1][6][i].x,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES, DATA_SCREEN);
}
void show_mario(mario myMario, SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN)
{
    myMario.change_mario_surface(DATA_OBJECTS_SURFACES);
    apply_surface(myMario.x, myMario.y, myMario.image, DATA_SCREEN);
}
void show_score_text(int &DATA_SCORE, SDL_Surface* DATA_SCREEN,TTF_Font *DATA_FONT)
{
    stringstream score;
    score<<"Score: "<< DATA_SCORE;
    show_text(score.str(), 10, get_screen_height() - 30, DATA_SCREEN, DATA_FONT, 22);
}
void show_level_text(int &DATA_LEVEL, SDL_Surface* DATA_SCREEN,TTF_Font *DATA_FONT)
{
    stringstream level;
    level<<"Level: "<< DATA_LEVEL;
    show_text(level.str(), get_screen_width() - 80, get_screen_height() - 30, DATA_SCREEN, DATA_FONT, 22);
}
void show_enemy(enemy &myEnemy,SDL_Surface** DATA_OBJECTS_SURFACES, SDL_Surface* DATA_SCREEN, int DATA_SCROLL_POSITION)
{
    myEnemy.move_enemy();
    myEnemy.change_enemy_surface(DATA_OBJECTS_SURFACES);
    apply_surface(myEnemy.x + DATA_SCROLL_POSITION, myEnemy.y, myEnemy.image, DATA_SCREEN);
}