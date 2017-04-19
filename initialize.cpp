#include "initialize.h"
bool init_sdl()
{
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1)
        return false;
}
bool init_screen(SDL_Surface* DATA_SCREEN)
{
    DATA_SCREEN = SDL_SetVideoMode( get_screen_width(), get_screen_height(), 32, SDL_FULLSCREEN );
    if( DATA_SCREEN == NULL )
        return false;
    SDL_WM_SetCaption( "Super Mario!", NULL );
    return true;
}
bool init_sounds(Mix_Chunk **DATA_SOUNDS)
{
    if (Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1)
        return false;
    DATA_SOUNDS[0] = Mix_LoadWAV( "resources/sounds/coin.wav" );
    DATA_SOUNDS[1] = Mix_LoadWAV( "resources/sounds/jump.wav" );
    DATA_SOUNDS[2] = Mix_LoadWAV( "resources/sounds/powerup.wav" );
    DATA_SOUNDS[3] = Mix_LoadWAV( "resources/sounds/powerdown.wav" );
    DATA_SOUNDS[4] = Mix_LoadWAV( "resources/sounds/die.wav" );
    DATA_SOUNDS[5] = Mix_LoadWAV( "resources/sounds/gameover.wav" );
    DATA_SOUNDS[6] = Mix_LoadWAV( "resources/sounds/stage_clear.wav" );
    DATA_SOUNDS[7] = Mix_LoadWAV( "resources/sounds/world_clear.wav" );
    return true;
}
bool free_sounds(Mix_Chunk **DATA_SOUNDS, Mix_Music *music)
{
    for (int i = 0; i < 3; i++)
    {
        Mix_FreeChunk( DATA_SOUNDS[i] );
    }
    Mix_FreeMusic( music );
    Mix_CloseAudio();
}
SDL_Surface *load_image( string filename )
{
     SDL_Surface* loadedImage = NULL;
     SDL_Surface* optimizedImage = NULL;
     loadedImage = IMG_Load( filename.c_str() );
     if( loadedImage != NULL ) {
         optimizedImage = SDL_DisplayFormat( loadedImage );
         SDL_FreeSurface( loadedImage );
     }
     return optimizedImage;
}
bool init_surfaces(SDL_Surface** DATA_OBJECTS_SURFACES)
{
    DATA_OBJECTS_SURFACES[0] = load_image("resources/sprites/mario-s-stop-l.gif");
    DATA_OBJECTS_SURFACES[1] = load_image("resources/sprites/mario-s-stop-r.gif");
    DATA_OBJECTS_SURFACES[2] = load_image("resources/sprites/mario-s-walk-1-l.gif");
    DATA_OBJECTS_SURFACES[3] = load_image("resources/sprites/mario-s-walk-2-l.gif");
    DATA_OBJECTS_SURFACES[4] = load_image("resources/sprites/mario-s-walk-3-l.gif");
    DATA_OBJECTS_SURFACES[5] = load_image("resources/sprites/mario-s-walk-1-r.gif");
    DATA_OBJECTS_SURFACES[6] = load_image("resources/sprites/mario-s-walk-2-r.gif");
    DATA_OBJECTS_SURFACES[7] = load_image("resources/sprites/mario-s-walk-3-r.gif");
    DATA_OBJECTS_SURFACES[8] = load_image("resources/sprites/mario-s-jump-l.gif");
    DATA_OBJECTS_SURFACES[9] = load_image("resources/sprites/mario-s-jump-r.gif");
    DATA_OBJECTS_SURFACES[10] = load_image("resources/sprites/mario-b-stop-l.gif");
    DATA_OBJECTS_SURFACES[11] = load_image("resources/sprites/mario-b-stop-r.gif");
    DATA_OBJECTS_SURFACES[12] = load_image("resources/sprites/mario-b-walk-1-l.gif");
    DATA_OBJECTS_SURFACES[13] = load_image("resources/sprites/mario-b-walk-2-l.gif");
    DATA_OBJECTS_SURFACES[14] = load_image("resources/sprites/mario-b-walk-3-l.gif");
    DATA_OBJECTS_SURFACES[15] = load_image("resources/sprites/mario-b-walk-1-r.gif");
    DATA_OBJECTS_SURFACES[16] = load_image("resources/sprites/mario-b-walk-2-r.gif");
    DATA_OBJECTS_SURFACES[17] = load_image("resources/sprites/mario-b-walk-3-r.gif");
    DATA_OBJECTS_SURFACES[18] = load_image("resources/sprites/mario-b-jump-l.gif");
    DATA_OBJECTS_SURFACES[19] = load_image("resources/sprites/mario-b-jump-r.gif");
    DATA_OBJECTS_SURFACES[20] = load_image("resources/sprites/tree.gif");
    DATA_OBJECTS_SURFACES[21] = load_image("resources/sprites/tree-small.gif");
    DATA_OBJECTS_SURFACES[22] = load_image("resources/sprites/mushroom.gif");
    DATA_OBJECTS_SURFACES[23] = load_image("resources/sprites/pipe.gif");
    DATA_OBJECTS_SURFACES[24] = load_image("resources/sprites/cloud-single.gif");
    DATA_OBJECTS_SURFACES[25] = load_image("resources/sprites/cloud-double.gif");
    DATA_OBJECTS_SURFACES[26] = load_image("resources/sprites/cloud-triple.gif");
    DATA_OBJECTS_SURFACES[27] = load_image("resources/sprites/bush-single.gif");
    DATA_OBJECTS_SURFACES[28] = load_image("resources/sprites/bush-double.gif");
    DATA_OBJECTS_SURFACES[29] = load_image("resources/sprites/bush-triple.gif");
    DATA_OBJECTS_SURFACES[30] = load_image("resources/sprites/coin.gif");
    DATA_OBJECTS_SURFACES[31] = load_image("resources/sprites/earth.gif");
    DATA_OBJECTS_SURFACES[32] = load_image("resources/sprites/box1.gif");
    DATA_OBJECTS_SURFACES[33] = load_image("resources/sprites/box2.gif");
    DATA_OBJECTS_SURFACES[34] = load_image("resources/sprites/enemy-walk-1-r.gif");
    DATA_OBJECTS_SURFACES[35] = load_image("resources/sprites/enemy-walk-2-r.gif");
    DATA_OBJECTS_SURFACES[36] = load_image("resources/sprites/enemy-walk-3-r.gif");
    DATA_OBJECTS_SURFACES[37] = load_image("resources/sprites/enemy-walk-1-l.gif");
    DATA_OBJECTS_SURFACES[38] = load_image("resources/sprites/enemy-walk-2-l.gif");
    DATA_OBJECTS_SURFACES[39] = load_image("resources/sprites/enemy-walk-3-l.gif");
    DATA_OBJECTS_SURFACES[40] = load_image("resources/sprites/menuimage.jpg");
}
bool init_fonts()
{
    TTF_Init();
    return true;
}
bool free_fonts()
{
    TTF_Quit();
}