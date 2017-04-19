//ITNOA
#include "iostream"
#include "math.h"
#include "time.h"
#include "stdlib.h"
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
#include "initialize.h"
#include "levels.h"
#ifndef CONFIG
#include "config.h"
#define CONFIG
#endif
#ifndef STRUCTS
#include "structs.h"
#define STRUCTS
#endif
#include "gui.h"
using namespace std;
void play_sound(string name, Mix_Chunk **DATA_SOUNDS)
{
    if (name == "coin")
        Mix_PlayChannel( -1, DATA_SOUNDS[0], 0 );
    else if (name == "jump")
        Mix_PlayChannel( -1, DATA_SOUNDS[1], 0 );
    else if (name == "powerup")
        Mix_PlayChannel( -1, DATA_SOUNDS[2], 0 );
    else if (name == "powerdown")
        Mix_PlayChannel( -1, DATA_SOUNDS[3], 0 );
    else if (name == "die")
        Mix_PlayChannel( -1, DATA_SOUNDS[4], 0 );
    else if (name == "gameover")
        Mix_PlayChannel( -1, DATA_SOUNDS[5], 0 );
    else if (name == "stage_clear")
        Mix_PlayChannel( -1, DATA_SOUNDS[6], 0 );
    else if (name == "world_clear")
        Mix_PlayChannel( -1, DATA_SOUNDS[7], 0 );
}
void exit_game(Mix_Chunk **DATA_SOUNDS, Mix_Music *music, bool& quit)
{
    free_sounds(DATA_SOUNDS, music);
    free_fonts();
    quit = true;
}
void colorize_background(SDL_Surface* DATA_SCREEN)
{
    SDL_FillRect( DATA_SCREEN, &DATA_SCREEN->clip_rect, SDL_MapRGB( DATA_SCREEN->format,0,154,217));
}
void next_level(int &DATA_LEVEL, int &DATA_SCROLL_POSITION, mario &myMario, int &DATA_SCORE, enemy &myEnemy, SDL_Surface** DATA_OBJECTS_SURFACES)
{
    DATA_SCORE += DATA_LEVEL * 100;
    DATA_LEVEL++;
    DATA_SCROLL_POSITION = 0;
    setup_enemy(myEnemy, DATA_OBJECTS_SURFACES, DATA_LEVEL);
    myMario.x = 100;
    myMario.y = myMario.y0;
    myMario.status = 1;
    myMario.change_mario_surface(DATA_OBJECTS_SURFACES);
    myMario.y0 = get_screen_height() - get_earth_height() - myMario.image->h + 5;
}
void get_coin(int &DATA_SCORE, Mix_Chunk **DATA_SOUNDS)
{
    DATA_SCORE++;
    play_sound("coin", DATA_SOUNDS);
}
void get_mushroom(int &DATA_SCORE, mario myMario, Mix_Chunk **DATA_SOUNDS)
{
    DATA_SCORE += 10;
    myMario.status += 10;
    play_sound("powerup", DATA_SOUNDS);
}
void check_collision_by_coins(mario myMario,object* coin_location,int DATA_SCROLL_POSITION,SDL_Surface* coin,int &DATA_SCORE, Mix_Chunk **DATA_SOUNDS)
{
	for(int i=0;i<10;i++)
	{
        if(myMario.y>coin_location[i].y)
        {
            if(abs(myMario.x-DATA_SCROLL_POSITION-coin_location[i].x)<myMario.image->w && abs(myMario.y-coin_location[i].y)<coin->h)
            {
                coin_location[i].x=7000+i;
                DATA_SCORE++;
                play_sound("coin", DATA_SOUNDS);
            }
        }
        if(myMario.y<coin_location[i].y)
        {
            if(abs(myMario.x-DATA_SCROLL_POSITION-coin_location[i].x)<myMario.image->w && abs(myMario.y-coin_location[i].y)<myMario.image->h)
            {
                coin_location[i].x=7000+i;
                DATA_SCORE++;
                play_sound("coin", DATA_SOUNDS);
            }
        }
	}
}
bool check_collision_by_mushroom(mario myMario,object*** DATA_LOCATION_OBJECTS,int DATA_SCROLL_POSITION,SDL_Surface** DATA_OBJECTS_SURFACES,int DATA_LEVEL)
{
	for(int i=0;i<1;i++)
	{
        if(myMario.y<DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].y)
        {
            if(abs(myMario.x-DATA_SCROLL_POSITION-DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].x)<=myMario.image->w && abs(myMario.y-DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].y)<myMario.image->h)
            {
                DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].x=8000;
                return true;
            }
        }
        if(myMario.y>DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].y)
        {
            if(abs(myMario.x-DATA_SCROLL_POSITION-DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].x)<=myMario.image->w && abs(myMario.y-DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].y)<DATA_OBJECTS_SURFACES[22]->h)
            {
                DATA_LOCATION_OBJECTS[DATA_LEVEL-1][3][i].x=8000;
                return true;
            }
        }
        return false;
	}
}
bool check_collision_by_box(mario &myMario, object* boxes_location, SDL_Surface* box_surface, Mix_Chunk **DATA_SOUNDS, int DATA_SCROLL_POSITION)
{
    for (int i = 0; i < 3; i++)
    {
        if (myMario.y < boxes_location[i].y && myMario.y + myMario.image->h > boxes_location[i].y && myMario.y + myMario.image->h < boxes_location[i].y + box_surface->h)
        {
            if ((myMario.x < boxes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > boxes_location[i].x + DATA_SCROLL_POSITION + 10) || (myMario.x < boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w && myMario.x + myMario.image->w > boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w) || (myMario.x > boxes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w))
            {
                myMario.y = boxes_location[i].y - myMario.image->h;
                if (myMario.status == 8)
                    myMario.status = 0;
                else if (myMario.status == 9)
                    myMario.status = 1;
                else if (myMario.status == 18)
                    myMario.status = 10;
                else if (myMario.status == 19)
                    myMario.status = 11;
                return true;
            }
        }
        if (myMario.y < boxes_location[i].y + box_surface->h && myMario.y > boxes_location[i].y && myMario.y + myMario.image->h > boxes_location[i].y + box_surface->h)
            if ((myMario.x < boxes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > boxes_location[i].x + DATA_SCROLL_POSITION + 10) || (myMario.x < boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w - 10 && myMario.x + myMario.image->w > boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w) || (myMario.x > boxes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < boxes_location[i].x + DATA_SCROLL_POSITION + box_surface->w))
            {
                myMario.y = boxes_location[i].y + box_surface->h; 
                if (myMario.status == 8)
                    myMario.status = 0;
                else if (myMario.status == 9)
                    myMario.status = 1;
                else if (myMario.status == 18)
                    myMario.status = 10;
                else if (myMario.status == 19)
                    myMario.status = 11;
                return true;
            }
	    if (myMario.x + myMario.image->w > boxes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < boxes_location[i].x + box_surface->w + DATA_SCROLL_POSITION)
	        if ((myMario.y < boxes_location[i].y && myMario.y + myMario.image->h > boxes_location[i].y) || (myMario.y + myMario.image->h > boxes_location[i].y + box_surface->h && myMario.y < boxes_location[i].y + box_surface->h))
                {myMario.x = boxes_location[i].x + DATA_SCROLL_POSITION - myMario.image->w; return true;}
        if (myMario.x < boxes_location[i].x + box_surface->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > boxes_location[i].x + box_surface->w + DATA_SCROLL_POSITION)
            if ((myMario.y < boxes_location[i].y && myMario.y + myMario.image->h > boxes_location[i].y) || (myMario.y + myMario.image->h > boxes_location[i].y + box_surface->h && myMario.y < boxes_location[i].y + box_surface->h))
                {myMario.x = boxes_location[i].x + box_surface->w + DATA_SCROLL_POSITION;return true;}
    }
    return false;
}
bool check_collision_by_pipe(mario &myMario, object* pipes_location, SDL_Surface* pipe_surface, Mix_Chunk **DATA_SOUNDS, int DATA_SCROLL_POSITION)
{
    for (int i = 0; i < 2; i++)
    {
        if (myMario.y < pipes_location[i].y && myMario.y + myMario.image->h > pipes_location[i].y && myMario.y + myMario.image->h < pipes_location[i].y + pipe_surface->h)
        {
            if ((myMario.x < pipes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > pipes_location[i].x + DATA_SCROLL_POSITION + 10) || (myMario.x < pipes_location[i].x + DATA_SCROLL_POSITION + pipe_surface->w - 10 && myMario.x + myMario.image->w > pipes_location[i].x + DATA_SCROLL_POSITION + pipe_surface->w) || (myMario.x > pipes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < pipes_location[i].x + DATA_SCROLL_POSITION + pipe_surface->w))
            {
                myMario.y = pipes_location[i].y - myMario.image->h; 
                if (myMario.status == 8)
                    myMario.status = 0;
                else if (myMario.status == 9)
                    myMario.status = 1;
                else if (myMario.status == 18)
                    myMario.status = 10;
                else if (myMario.status == 19)
                    myMario.status = 11;
                return true;
            }
        }
        if (myMario.x + myMario.image->w > pipes_location[i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < pipes_location[i].x + pipe_surface->w + DATA_SCROLL_POSITION)
            if ((myMario.y > pipes_location[i].y && myMario.y < pipes_location[i].y + pipe_surface->h) || (myMario.y + myMario.image->h > pipes_location[i].y && myMario.y  + myMario.image->h < pipes_location[i].y + pipe_surface->h) || (myMario.y < pipes_location[i].y && myMario.y + myMario.image->h > pipes_location[i].y + pipe_surface->h))
                {myMario.x = pipes_location[i].x + DATA_SCROLL_POSITION - myMario.image->w; return true;}
        if (myMario.x < pipes_location[i].x + pipe_surface->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > pipes_location[i].x + pipe_surface->w + DATA_SCROLL_POSITION)
            if ((myMario.y > pipes_location[i].y && myMario.y < pipes_location[i].y + pipe_surface->h) || (myMario.y + myMario.image->h > pipes_location[i].y && myMario.y  + myMario.image->h < pipes_location[i].y + pipe_surface->h) || (myMario.y < pipes_location[i].y && myMario.y + myMario.image->h > pipes_location[i].y + pipe_surface->h))
                {myMario.x = pipes_location[i].x + pipe_surface->w + DATA_SCROLL_POSITION;return true;}
    }
    return false;
}
void kill_enemy(enemy &myEnemy, int &DATA_SCORE)
{
    DATA_SCORE += 20;
    myEnemy.x += 10000;
}
bool check_collision_by_enemy(mario myMario, enemy &myEnemy, int DATA_SCROLL_POSITION, SDL_Surface* enemy_surface, int &DATA_SCORE)
{
    if (myMario.y < myEnemy.y && myMario.y + myMario.image->h > myEnemy.y && myMario.y + myMario.image->h < myEnemy.y + enemy_surface->h)
        if ((myMario.x < myEnemy.x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > myEnemy.x + DATA_SCROLL_POSITION) || (myMario.x < myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION) || (myMario.x > myEnemy.x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION))
            kill_enemy(myEnemy, DATA_SCORE);
    if (myMario.x + myMario.image->w > myEnemy.x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION)
        if ((myMario.y < myEnemy.y && myMario.y + myMario.image->h > myEnemy.y) || (myMario.y + myMario.image->h > myEnemy.y + enemy_surface->h && myMario.y < myEnemy.y + enemy_surface->h) || (myMario.y == myEnemy.y && myMario.y + myMario.image->h == myEnemy.y + enemy_surface->h))
            return true;
    if (myMario.x < myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > myEnemy.x + enemy_surface->w + DATA_SCROLL_POSITION)
        if ((myMario.y < myEnemy.y && myMario.y + myMario.image->h > myEnemy.y) || (myMario.y + myMario.image->h > myEnemy.y + enemy_surface->h && myMario.y < myEnemy.y + enemy_surface->h) || (myMario.y == myEnemy.y && myMario.y + myMario.image->h == myEnemy.y + enemy_surface->h))
            return true;
    return false;
}
bool is_on_the_last_pipe(mario myMario, object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES, int DATA_LEVEL, int DATA_SCROLL_POSITION)
{
    if (myMario.x + myMario.image->w > DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][1].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][1].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION)
        return true;
    if (myMario.x < DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][1].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][1].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION)
        return true;
    return false;
}
bool is_on_the_pipe(mario myMario, object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES, int DATA_LEVEL, int DATA_SCROLL_POSITION)
{
    for(int i = 0; i< 2; i++)
    {
        if (myMario.x + myMario.image->w > DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w < DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][i].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION)
            return true;
        if (myMario.x < DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][i].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w > DATA_LOCATION_OBJECTS[DATA_LEVEL-1][6][i].x + DATA_OBJECTS_SURFACES[23]->w + DATA_SCROLL_POSITION)
            return true;
    }
    return false;
}
bool is_on_the_box(mario &myMario, object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES, int DATA_LEVEL, int DATA_SCROLL_POSITION)
{
    for (int i = 0; i < 3; i++)
    {
        if (myMario.x + myMario.image->w >= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].x + DATA_SCROLL_POSITION && myMario.x + myMario.image->w <= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].x + DATA_OBJECTS_SURFACES[32]->w + DATA_SCROLL_POSITION + 5)
            if (myMario.y + myMario.image->h >= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].y)
                return true;
        if (myMario.x <= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].x + DATA_OBJECTS_SURFACES[32]->w + DATA_SCROLL_POSITION && myMario.x + myMario.image->w >= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].x + DATA_OBJECTS_SURFACES[32]->w + DATA_SCROLL_POSITION)
            if (myMario.y + myMario.image->h >= DATA_LOCATION_OBJECTS[DATA_LEVEL-1][1][i].y)
                return true;
    }
    return false;
}
int main()
{
    SDL_Surface *DATA_SCREEN = SDL_SetVideoMode( get_screen_width(), get_screen_height(), 32, SDL_FULLSCREEN );
    SDL_Surface **DATA_OBJECTS_SURFACES = new SDL_Surface* [45];
    Mix_Music *music = NULL;
    Mix_Chunk **DATA_SOUNDS = new Mix_Chunk* [10];
    TTF_Font *DATA_FONT = NULL;
    int DATA_LEVEL = 1;
    int DATA_SCROLL_POSITION = 0;
    int DATA_GAME_STATUS = 0;
    bool quit = 0;
    int DATA_SCORE = 0;
    int collision=0;
    object*** DATA_LOCATION_OBJECTS = new object**[get_levels_count()];
    for(int i=0;i<get_levels_count();i++)
    {
        DATA_LOCATION_OBJECTS[i]=new object*[7];
        DATA_LOCATION_OBJECTS[i][0] = new object[5];
    	DATA_LOCATION_OBJECTS[i][1] = new object[3];
    	DATA_LOCATION_OBJECTS[i][2] = new object[5];
    	DATA_LOCATION_OBJECTS[i][3] = new object[1];
    	DATA_LOCATION_OBJECTS[i][4] = new object[3];
    	DATA_LOCATION_OBJECTS[i][5] = new object[10];
    	DATA_LOCATION_OBJECTS[i][6] = new object[2];
    }
    init_sdl();
    init_sounds(DATA_SOUNDS);
    init_surfaces(DATA_OBJECTS_SURFACES);
    init_fonts();
    SDL_Event event;
    mario myMario;
    myMario.image = DATA_OBJECTS_SURFACES[1];
    myMario.x = 150;
    myMario.y0 = get_screen_height() - get_earth_height() - myMario.image->h + 5;
    myMario.y = myMario.y0;
    myMario.vx = get_mario_speed();
    myMario.vy0 = 0;
    myMario.vy = 0;
    myMario.status = 1;
    myMario.is_hidden = false;
    myMario.hidden_counter = 0;
    myMario.walk_counter = 0;
    enemy myEnemy;
    int keystate = 0;
    setup_levels(DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES);
    setup_enemy(myEnemy, DATA_OBJECTS_SURFACES, DATA_LEVEL);
    Uint32 time_start = 0;
    Uint32 jump_start1 = 0;
    Uint32 jump_start = 0;
    int DATA_MENU_SELECT=0;
    while (!quit)
    {
        if (DATA_GAME_STATUS == 0)
        {
            apply_surface(0,0,DATA_OBJECTS_SURFACES[40],DATA_SCREEN);
            show_text("Super Mario",600,150,DATA_SCREEN,DATA_FONT,80);
            if(DATA_MENU_SELECT==0)
            {
                filledEllipseRGBA(DATA_SCREEN,670,385,8,8,255,0,0,255);
                show_text("Start",700,350,DATA_SCREEN,DATA_FONT,60);
                show_text("Exit",700,450,DATA_SCREEN,DATA_FONT,45);
            }
            if(DATA_MENU_SELECT==1)
            {
                filledEllipseRGBA(DATA_SCREEN,670,480,8,8,255,0,0,255);
                show_text("Start",700,350,DATA_SCREEN,DATA_FONT,45);
                show_text("Exit",700,450,DATA_SCREEN,DATA_FONT,60);
            }
            while( SDL_PollEvent( &event )  )
            {
                if( event.type == SDL_KEYDOWN )
                {
                    switch( event.key.keysym.sym )
                    {
                        case SDLK_UP:
                        {
                            DATA_MENU_SELECT=0;
                            break;
                        }
                        case SDLK_DOWN:
                        {
                            DATA_MENU_SELECT=1;
                            break;
                        }
                        case SDLK_RETURN:
                        {
                            if(DATA_MENU_SELECT==0)
                                {DATA_GAME_STATUS=1;break;}
                            if(DATA_MENU_SELECT==1)
                                {exit_game(DATA_SOUNDS, music, quit);break;}
                        }
                    }
                }
                SDL_Flip(DATA_SCREEN);
            }
        }
        if (DATA_GAME_STATUS == 1)
        {
            time_start = SDL_GetTicks();
            check_collision_by_coins(myMario,DATA_LOCATION_OBJECTS[DATA_LEVEL-1][5],DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES[30],DATA_SCORE,DATA_SOUNDS);
            if(check_collision_by_mushroom(myMario,DATA_LOCATION_OBJECTS,DATA_SCROLL_POSITION,DATA_OBJECTS_SURFACES,DATA_LEVEL))
            {
                myMario.grow();
                myMario.change_mario_surface(DATA_OBJECTS_SURFACES);
                play_sound("powerup", DATA_SOUNDS);
                myMario.y0 = get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[10]->h + 5;
                if(myMario.y > myMario.y0)
                    myMario.y = myMario.y0;
            }
            if(check_collision_by_enemy(myMario, myEnemy, DATA_SCROLL_POSITION, DATA_OBJECTS_SURFACES[34], DATA_SCORE))
            {
                if(!myMario.is_hidden)
                {
                    if(myMario.status > 9)
                    {
                        myMario.shrink();
                        myMario.change_mario_surface(DATA_OBJECTS_SURFACES);
                        play_sound("powerdown", DATA_SOUNDS);
                        myMario.y0 = get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[0]->h + 5;
                        myMario.y = myMario.y0;
                        myMario.hidden_counter = 0;
                        myMario.is_hidden = true;
                    }
                    else
                    {
                        play_sound("gameover", DATA_SOUNDS);
                        SDL_Delay(3500);
                        exit_game(DATA_SOUNDS, music, quit);
                    }
                }
            }
            check_collision_by_pipe(myMario, DATA_LOCATION_OBJECTS[DATA_LEVEL - 1][6], DATA_OBJECTS_SURFACES[23], DATA_SOUNDS, DATA_SCROLL_POSITION);
            check_collision_by_box(myMario, DATA_LOCATION_OBJECTS[DATA_LEVEL - 1][1], DATA_OBJECTS_SURFACES[32], DATA_SOUNDS, DATA_SCROLL_POSITION);
            if (myMario.y < myMario.y0 && myMario.status != 8 && myMario.status != 9 && myMario.status != 18 && myMario.status != 19 && !is_on_the_box(myMario,DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES, DATA_LEVEL, DATA_SCROLL_POSITION) && !is_on_the_pipe(myMario,DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES, DATA_LEVEL, DATA_SCROLL_POSITION))
            {
                myMario.vy0 = 0;
                jump_start = SDL_GetTicks();
                switch(myMario.status)
                {
                    case 0: 
                    case 2:
                    case 3:
                    case 4: {myMario.status = 8; break;}
                    case 1: 
                    case 5:
                    case 6:
                    case 7: {myMario.status = 9; break;}
                    case 10: 
                    case 12:
                    case 13:
                    case 14: {myMario.status = 18; break;}
                    case 11: 
                    case 15:
                    case 16:
                    case 17: {myMario.status = 19; break;}
                }
            }
            colorize_background(DATA_SCREEN);
            show_level(DATA_LEVEL,DATA_SCROLL_POSITION, DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES, DATA_SCREEN);
            if (myMario.is_hidden)
            {
                myMario.hidden_counter ++;
                if (myMario.hidden_counter % 10 < 5)
                {
                    show_mario(myMario,DATA_OBJECTS_SURFACES, DATA_SCREEN);
                }
                if (myMario.hidden_counter == get_mario_hidden_time())
                {
                    myMario.is_hidden = false;
                    myMario.hidden_counter = 0;
                }
            }
            else
                show_mario(myMario,DATA_OBJECTS_SURFACES, DATA_SCREEN);
            show_enemy(myEnemy,DATA_OBJECTS_SURFACES, DATA_SCREEN, DATA_SCROLL_POSITION);
            show_score_text(DATA_SCORE, DATA_SCREEN, DATA_FONT);
            show_level_text(DATA_LEVEL, DATA_SCREEN, DATA_FONT);
            while( SDL_PollEvent( &event ) )
            {
                if( event.type == SDL_KEYDOWN )
                {
                    switch( event.key.keysym.sym )
                    {
                        case SDLK_RIGHT:
                        {
                            if (keystate == 2)
			                    keystate = 3;
                            else
                                keystate = 1;
                            break;
                        }
                        case SDLK_LEFT:
                        {
        		            if (keystate == 1)
                                keystate = 4;
                            else
                                keystate = 2;
                            break;
                        }
                        case SDLK_DOWN:
                        {
                            if (is_on_the_last_pipe(myMario,DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES, DATA_LEVEL, DATA_SCROLL_POSITION) )
                                if(DATA_LEVEL != get_levels_count())
                                {
                                    play_sound("stage_clear", DATA_SOUNDS);
                                    SDL_Delay(3000);
                                    next_level(DATA_LEVEL, DATA_SCROLL_POSITION, myMario, DATA_SCORE, myEnemy, DATA_OBJECTS_SURFACES);
                                }
                                else
                                {
                                    play_sound("world_clear", DATA_SOUNDS);
                                    setup_levels(DATA_LOCATION_OBJECTS, DATA_OBJECTS_SURFACES);
                                    setup_enemy(myEnemy, DATA_OBJECTS_SURFACES, DATA_LEVEL);
                                    myMario.image = DATA_OBJECTS_SURFACES[1];
                                    myMario.x = 150;
                                    myMario.y0 = get_screen_height() - get_earth_height() - myMario.image->h + 5;
                                    myMario.y = myMario.y0;
                                    myMario.vx = get_mario_speed();
                                    myMario.vy0 = 0;
                                    myMario.vy = 0;
                                    myMario.status = 1;
                                    myMario.is_hidden = false;
                                    myMario.hidden_counter = 0;
                                    myMario.walk_counter = 0;
                                    DATA_LEVEL = 1;
                                    DATA_SCROLL_POSITION = 0;
                                    DATA_SCORE = 0;
                                    keystate = 0;
                                    SDL_Delay(2000);
                                    DATA_GAME_STATUS = 0;
                                }
                            break;
                        }
                        case SDLK_UP:
                        {
                            if (myMario.status != 8 && myMario.status != 9 && myMario.status != 18 && myMario.status != 19)
                            {
                                play_sound("jump", DATA_SOUNDS);
                                myMario.vy0= get_mario_jump_speed();
                                if (myMario.status == 0 || myMario.status == 2 || myMario.status == 3 || myMario.status == 4)
                                    myMario.status = 8;
                                if (myMario.status == 1 || myMario.status == 5 || myMario.status == 6 || myMario.status == 7)
                                    myMario.status = 9;
                                if (myMario.status == 10 || myMario.status == 12 || myMario.status == 13 || myMario.status == 14)
                                    myMario.status = 18;
                                if (myMario.status == 11 || myMario.status == 15 || myMario.status == 16 || myMario.status == 17)
                                    myMario.status = 19;
                                jump_start=SDL_GetTicks();
                            }
                            break;
                        }
                        case SDLK_ESCAPE:
                        {
                            exit_game(DATA_SOUNDS, music, quit);
                        }
                    }
                }
    	        if( event.type == SDL_KEYUP )
                {
    		        if (DATA_GAME_STATUS == 1) ////In Game
                    {
                        switch( event.key.keysym.sym )
                        {
                            case SDLK_RIGHT:
                            {
                                if(myMario.status == 8 || myMario.status == 9)
                                    myMario.status = 9;
                                else if(myMario.status == 18 || myMario.status == 19)
                                    myMario.status = 19;
                                else if(myMario.status < 10)
    		                        myMario.status = 1;
                                else
                                    myMario.status = 11;

    			                if (keystate == 3 || keystate == 4)
                                    keystate = 2;
                                else
                                    keystate = 0;
                                break;
                            }
                            case SDLK_LEFT:
                            {
                                if(myMario.status == 9  || myMario.status == 8)
                                    myMario.status = 8;
                                else if(myMario.status == 19 || myMario.status == 18)
                                    myMario.status = 18;
                                else if(myMario.status < 10)
        		                    myMario.status = 0;
                                else
                                    myMario.status = 10;

    			                if (keystate == 3 || keystate == 4)
                                    keystate = 1;
                                else
                                    keystate = 0;
                                break;
                            }
                        }
                    }
    	        }
                if( event.type == SDL_QUIT )
                    exit_game(DATA_SOUNDS, music, quit);
            }
    	    if( keystate == 2 || keystate == 4)
            {
    	        if (myMario.status == 1 || myMario.status == 5 || myMario.status == 6 || myMario.status == 7)
    		        myMario.status = 0;
                if (myMario.status == 11 || myMario.status == 15 || myMario.status == 16 || myMario.status == 17)
                    myMario.status = 10;
                if (myMario.status == 9)
                    myMario.status = 8;
                if (myMario.status == 19)
                    myMario.status = 18;
    	        myMario.walk_counter += 1;
    	        if (myMario.x > myMario.vx + 150)
                    myMario.x -= myMario.vx;
    	        else if (DATA_SCROLL_POSITION < (-1) * myMario.vx)
                    DATA_SCROLL_POSITION += myMario.vx;
            }
            if( keystate == 1 || keystate == 3)
            {
    	        if (myMario.status == 0 || myMario.status == 2 || myMario.status == 3 || myMario.status == 4)
    		        myMario.status = 1;
                if (myMario.status == 10 || myMario.status == 12 || myMario.status == 13 || myMario.status == 14)
                    myMario.status = 11;
                if (myMario.status == 8)
                    myMario.status = 9;
                if (myMario.status == 18)
                    myMario.status = 19;
    	        myMario.walk_counter += 1;
    	        if (myMario.x < get_screen_width()/2)
                    myMario.x += myMario.vx;
                else if (DATA_SCROLL_POSITION > (-1) * (get_levels_width() - get_screen_width()))
                    DATA_SCROLL_POSITION -= myMario.vx;
            }
            if (myMario.status == 8 || myMario.status == 18 || myMario.status == 9 || myMario.status == 19)
            {
                jump_start1=SDL_GetTicks()-jump_start;
                myMario.vy=10*jump_start1/200+myMario.vy0;
                if(myMario.y+myMario.vy>=myMario.y0)
                {
                    myMario.y=myMario.y0;
                    if (myMario.status == 8)
                        myMario.status = 0;
                    else if (myMario.status == 9)
                        myMario.status = 1;
                    else if (myMario.status == 18)
                        myMario.status = 10;
                    else if (myMario.status == 19)
                        myMario.status = 11;
                }
                else
                    myMario.y+=myMario.vy;
                //check_collision_by_box(myMario, DATA_LOCATION_OBJECTS[DATA_LEVEL - 1][1], DATA_OBJECTS_SURFACES[32], DATA_SOUNDS, DATA_SCROLL_POSITION);
            }
    	    if (myMario.walk_counter == get_step_interval())
    	    {
    	        switch(myMario.status)
    	        {
    		        case 0: { myMario.status = 2; break; }
    		        case 2: { myMario.status = 3; break; }
    		        case 3: { myMario.status = 4; break; }
    		        case 4: { myMario.status = 2; break; }
    		        case 1: { myMario.status = 5; break; }
    		        case 5: { myMario.status = 6; break; }
    		        case 6: { myMario.status = 7; break; }
    		        case 7: { myMario.status = 5; break; }
                    case 10: { myMario.status = 12; break; }
                    case 12: { myMario.status = 13; break; }
                    case 13: { myMario.status = 14; break; }
                    case 14: { myMario.status = 12; break; }
                    case 11: { myMario.status = 15; break; }
                    case 15: { myMario.status = 16; break; }
                    case 16: { myMario.status = 17; break; }
                    case 17: { myMario.status = 15; break; }
    	        }
    	        myMario.walk_counter = 0;
    	    }
            if (myEnemy.walk_counter == get_step_interval())
            {
                switch(myEnemy.status)
                {
                    case 34: { myEnemy.status = 35; break; }
                    case 35: { myEnemy.status = 36; break; }
                    case 36: { myEnemy.status = 34; break; }
                    case 37: { myEnemy.status = 38; break; }
                    case 38: { myEnemy.status = 39; break; }
                    case 39: { myEnemy.status = 37; break; }
                }
                myEnemy.walk_counter = 0;
            }
            myEnemy.walk_counter ++;
    	    SDL_Flip( DATA_SCREEN );
            int t = (1000 / get_frame_rate()) - (SDL_GetTicks() - time_start);
            if (t > 0)
                SDL_Delay (t);
        }
    }
    SDL_Quit();
    return 0;
}