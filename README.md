Super Mario

Install requirements:
sudo apt-get install libsdl-image1.2-dev libsdl1.2-dev libsdl-ttf2.0-dev libsdl-image1.2-dev libsdl-mixer1.2-dev

Compile:
g++ main.cpp config.cpp gui.cpp initialize.cpp levels.cpp structs.cpp -o mario.out -lSDL -lSDL_gfx -lSDL_mixer -lSDL_ttf -lSDL_image
