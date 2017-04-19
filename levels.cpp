#include "levels.h"
void setup_levels(object*** DATA_LOCATION_OBJECTS, SDL_Surface** DATA_OBJECTS_SURFACES)
{
    /////////////////  level 1
    object myTree1;myTree1.x = 1000;
    object myTree2;myTree2.x = 1500;
    object myTree3;myTree3.x = 3000;
    object myTree4;myTree4.x = 4000;
    object myTree5;myTree5.x = 4800;
    DATA_LOCATION_OBJECTS[0][0][0] = myTree1;
    DATA_LOCATION_OBJECTS[0][0][1] = myTree2;
    DATA_LOCATION_OBJECTS[0][0][2] = myTree3;
    DATA_LOCATION_OBJECTS[0][0][3] = myTree4;
    DATA_LOCATION_OBJECTS[0][0][4] = myTree5;

    object myBox1;myBox1.x = 2400;myBox1.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    object myBox2;myBox2.x = 2400+DATA_OBJECTS_SURFACES[32]->w;myBox2.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    object myBox3;myBox3.x = 2400+DATA_OBJECTS_SURFACES[32]->w;myBox3.y=get_screen_height()-2*DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[0][1][0] = myBox1;
    DATA_LOCATION_OBJECTS[0][1][1] = myBox2;
    DATA_LOCATION_OBJECTS[0][1][2] = myBox3;

    object myCloud1;myCloud1.x = 1200;myCloud1.y=100;
    object myCloud2;myCloud2.x = 2400;myCloud2.y=50;
    object myCloud3;myCloud3.x = 3600;myCloud3.y=100;
    object myCloud4;myCloud4.x = 4800;myCloud4.y=100;
    object myCloud5;myCloud5.x = 5800;myCloud5.y=68;
    DATA_LOCATION_OBJECTS[0][2][0] = myCloud1;
    DATA_LOCATION_OBJECTS[0][2][1] = myCloud2;
    DATA_LOCATION_OBJECTS[0][2][2] = myCloud3;
    DATA_LOCATION_OBJECTS[0][2][3] = myCloud4;
    DATA_LOCATION_OBJECTS[0][2][4] = myCloud5;

    object myMushroom;myMushroom.x=2400+DATA_OBJECTS_SURFACES[32]->w+15;myMushroom.y=get_screen_height()-2*DATA_OBJECTS_SURFACES[32]->h-70-get_earth_height();
    DATA_LOCATION_OBJECTS[0][3][0] = myMushroom;

    object myBush1;myBush1.x = 2000;
    object myBush2;myBush2.x = 3500;
    object myBush3;myBush3.x = 4400;
    DATA_LOCATION_OBJECTS[0][4][0] = myBush1;
    DATA_LOCATION_OBJECTS[0][4][1] = myBush2;
    DATA_LOCATION_OBJECTS[0][4][2] = myBush3;

    object myCoin1;myCoin1.x = 610;myCoin1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    object myCoin2;myCoin2.x = 670;myCoin2.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    object myCoin3;myCoin3.x = 2420;myCoin3.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    object myCoin4;myCoin4.x = 3300;myCoin4.y=get_screen_height()-90-get_earth_height();
    object myCoin5;myCoin5.x = 3500;myCoin5.y=get_screen_height()-90-get_earth_height();
    object myCoin6;myCoin6.x = 3700;myCoin6.y=get_screen_height()-90-get_earth_height();
    object myCoin7;myCoin7.x = 4200;myCoin7.y=get_screen_height()-90-get_earth_height();
    object myCoin8;myCoin8.x = 4400;myCoin8.y=get_screen_height()-90-get_earth_height();
    object myCoin9;myCoin9.x = 4600;myCoin9.y=get_screen_height()- 90-get_earth_height();
    object myCoin10;myCoin10.x = 5200;myCoin10.y=get_screen_height()-90-get_earth_height();
    DATA_LOCATION_OBJECTS[0][5][0] = myCoin1;
    DATA_LOCATION_OBJECTS[0][5][1] = myCoin2;
    DATA_LOCATION_OBJECTS[0][5][2] = myCoin3;
    DATA_LOCATION_OBJECTS[0][5][3] = myCoin4;
    DATA_LOCATION_OBJECTS[0][5][4] = myCoin5;
    DATA_LOCATION_OBJECTS[0][5][5] = myCoin6;
    DATA_LOCATION_OBJECTS[0][5][6] = myCoin7;
    DATA_LOCATION_OBJECTS[0][5][7] = myCoin8;
    DATA_LOCATION_OBJECTS[0][5][8] = myCoin9;
    DATA_LOCATION_OBJECTS[0][5][9] = myCoin10;

    object myPipe1;myPipe1.x=600;myPipe1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    object myPipe2;myPipe2.x=5300;myPipe2.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[0][6][0] = myPipe1;
    DATA_LOCATION_OBJECTS[0][6][1] = myPipe2;

    /////////////////  level 2
    myTree1;myTree1.x = 1500;
    myTree2;myTree2.x = 2500;
    myTree3;myTree3.x = 3200;
    myTree4;myTree4.x = 3500;
    myTree5;myTree5.x = 4500;
    DATA_LOCATION_OBJECTS[1][0][0] = myTree1;
    DATA_LOCATION_OBJECTS[1][0][1] = myTree2;
    DATA_LOCATION_OBJECTS[1][0][2] = myTree3;
    DATA_LOCATION_OBJECTS[1][0][3] = myTree4;
    DATA_LOCATION_OBJECTS[1][0][4] = myTree5;

    myBox1;myBox1.x = 2700;myBox1.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    myBox2;myBox2.x = 2700+DATA_OBJECTS_SURFACES[32]->w;myBox2.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    myBox3;myBox3.x = 2700+2*DATA_OBJECTS_SURFACES[32]->w;myBox3.y=get_screen_height()-2*DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[1][1][0] = myBox1;
    DATA_LOCATION_OBJECTS[1][1][1] = myBox2;
    DATA_LOCATION_OBJECTS[1][1][2] = myBox3;

    myCloud1;myCloud1.x = 2000;myCloud1.y=100;
    myCloud2;myCloud2.x = 2600;myCloud2.y=50;
    myCloud3;myCloud3.x = 3000;myCloud3.y=100;
    myCloud4;myCloud4.x = 3400;myCloud4.y=150;
    myCloud5;myCloud5.x = 3800;myCloud5.y=68;
    DATA_LOCATION_OBJECTS[1][2][0] = myCloud1;
    DATA_LOCATION_OBJECTS[1][2][1] = myCloud2;
    DATA_LOCATION_OBJECTS[1][2][2] = myCloud3;
    DATA_LOCATION_OBJECTS[1][2][3] = myCloud4;
    DATA_LOCATION_OBJECTS[1][2][4] = myCloud5;

    myMushroom;myMushroom.x=2885;myMushroom.y=get_screen_height()-2*DATA_OBJECTS_SURFACES[32]->h-DATA_OBJECTS_SURFACES[22]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[1][3][0] = myMushroom;

    myBush1;myBush1.x = 2000;
    myBush2;myBush2.x = 4000;
    myBush3;myBush3.x = 5000;
    DATA_LOCATION_OBJECTS[1][4][0] = myBush1;
    DATA_LOCATION_OBJECTS[1][4][1] = myBush2;
    DATA_LOCATION_OBJECTS[1][4][2] = myBush3;

    myCoin1;myCoin1.x = 630;myCoin1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin2;myCoin2.x = 800;myCoin2.y=get_screen_height()-90-get_earth_height();
    myCoin3;myCoin3.x = 1000;myCoin3.y=get_screen_height()-90-get_earth_height();
    myCoin4;myCoin4.x = 1200;myCoin4.y=get_screen_height()-90-get_earth_height();
    myCoin5;myCoin5.x = 2000;myCoin5.y=get_screen_height()-DATA_OBJECTS_SURFACES[30]->h-DATA_OBJECTS_SURFACES[28]->h-get_earth_height();
    myCoin6;myCoin6.x = 4000;myCoin6.y=get_screen_height()-DATA_OBJECTS_SURFACES[30]->h-DATA_OBJECTS_SURFACES[28]->h-get_earth_height();
    myCoin7;myCoin7.x = 4800;myCoin7.y=get_screen_height()-DATA_OBJECTS_SURFACES[30]->h-DATA_OBJECTS_SURFACES[28]->h-get_earth_height();
    myCoin8;myCoin8.x = 5000;myCoin8.y=get_screen_height()-DATA_OBJECTS_SURFACES[30]->h-DATA_OBJECTS_SURFACES[28]->h-get_earth_height();
    myCoin9;myCoin9.x = 5200;myCoin9.y=get_screen_height()-DATA_OBJECTS_SURFACES[30]->h-DATA_OBJECTS_SURFACES[28]->h-get_earth_height();
    myCoin10;myCoin10.x = 5330;myCoin10.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[1][5][0] = myCoin1;
    DATA_LOCATION_OBJECTS[1][5][1] = myCoin2;
    DATA_LOCATION_OBJECTS[1][5][2] = myCoin3;
    DATA_LOCATION_OBJECTS[1][5][3] = myCoin4;
    DATA_LOCATION_OBJECTS[1][5][4] = myCoin5;
    DATA_LOCATION_OBJECTS[1][5][5] = myCoin6;
    DATA_LOCATION_OBJECTS[1][5][6] = myCoin7;
    DATA_LOCATION_OBJECTS[1][5][7] = myCoin8;
    DATA_LOCATION_OBJECTS[1][5][8] = myCoin9;
    DATA_LOCATION_OBJECTS[1][5][9] = myCoin10;

    myPipe1;myPipe1.x=600;myPipe1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    myPipe2;myPipe2.x=5300;myPipe2.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[1][6][0] = myPipe1;
    DATA_LOCATION_OBJECTS[1][6][1] = myPipe2;

    /////////////////  level 3
    myTree1;myTree1.x = 2500;
    myTree2;myTree2.x = 3100;
    myTree3;myTree3.x = 3700;
    myTree4;myTree4.x = 4000;
    myTree5;myTree5.x = 4600;
    DATA_LOCATION_OBJECTS[2][0][0] = myTree1;
    DATA_LOCATION_OBJECTS[2][0][1] = myTree2;
    DATA_LOCATION_OBJECTS[2][0][2] = myTree3;
    DATA_LOCATION_OBJECTS[2][0][3] = myTree4;
    DATA_LOCATION_OBJECTS[2][0][4] = myTree5;

    myBox1;myBox1.x = 1000;myBox1.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    myBox2;myBox2.x = 1500;myBox2.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    myBox3;myBox3.x = 2000;myBox3.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[2][1][0] = myBox1;
    DATA_LOCATION_OBJECTS[2][1][1] = myBox2;
    DATA_LOCATION_OBJECTS[2][1][2] = myBox3;

    myCloud1;myCloud1.x = 200;myCloud1.y=100;
    myCloud2;myCloud2.x = 800;myCloud2.y=50;
    myCloud3;myCloud3.x = 3000;myCloud3.y=100;
    myCloud4;myCloud4.x = 5200;myCloud4.y=150;
    myCloud5;myCloud5.x = 5800;myCloud5.y=68;
    DATA_LOCATION_OBJECTS[2][2][0] = myCloud1;
    DATA_LOCATION_OBJECTS[2][2][1] = myCloud2;
    DATA_LOCATION_OBJECTS[2][2][2] = myCloud3;
    DATA_LOCATION_OBJECTS[2][2][3] = myCloud4;
    DATA_LOCATION_OBJECTS[2][2][4] = myCloud5;

    myMushroom;myMushroom.x=2200;myMushroom.y=get_screen_height()-2*DATA_OBJECTS_SURFACES[22]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[2][3][0] = myMushroom;

    myBush1;myBush1.x = 2800;
    myBush2;myBush2.x = 3400;
    myBush3;myBush3.x = 4300;
    DATA_LOCATION_OBJECTS[2][4][0] = myBush1;
    DATA_LOCATION_OBJECTS[2][4][1] = myBush2;
    DATA_LOCATION_OBJECTS[2][4][2] = myBush3;

    myCoin1;myCoin1.x = 640;myCoin1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin2;myCoin2.x = 1010;myCoin2.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin3;myCoin3.x = 1510;myCoin3.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin4;myCoin4.x = 2010;myCoin4.y=get_screen_height()-DATA_OBJECTS_SURFACES[32]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin5;myCoin5.x = 2800;myCoin5.y=get_screen_height()-DATA_OBJECTS_SURFACES[28]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin6;myCoin6.x = 3400;myCoin6.y=get_screen_height()-DATA_OBJECTS_SURFACES[28]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin7;myCoin7.x = 4300;myCoin7.y=get_screen_height()-DATA_OBJECTS_SURFACES[28]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    myCoin8;myCoin8.x = 5000;myCoin8.y=get_screen_height()-90-get_earth_height();
    myCoin9;myCoin9.x = 5200;myCoin9.y=get_screen_height()- 90-get_earth_height();
    myCoin10;myCoin10.x = 5350;myCoin10.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-DATA_OBJECTS_SURFACES[30]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[2][5][0] = myCoin1;
    DATA_LOCATION_OBJECTS[2][5][1] = myCoin2;
    DATA_LOCATION_OBJECTS[2][5][2] = myCoin3;
    DATA_LOCATION_OBJECTS[2][5][3] = myCoin4;
    DATA_LOCATION_OBJECTS[2][5][4] = myCoin5;
    DATA_LOCATION_OBJECTS[2][5][5] = myCoin6;
    DATA_LOCATION_OBJECTS[2][5][6] = myCoin7;
    DATA_LOCATION_OBJECTS[2][5][7] = myCoin8;
    DATA_LOCATION_OBJECTS[2][5][8] = myCoin9;
    DATA_LOCATION_OBJECTS[2][5][9] = myCoin10;

    myPipe1;myPipe1.x=600;myPipe1.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    myPipe2;myPipe2.x=5300;myPipe2.y=get_screen_height()-DATA_OBJECTS_SURFACES[23]->h-get_earth_height();
    DATA_LOCATION_OBJECTS[2][6][0] = myPipe1;
    DATA_LOCATION_OBJECTS[2][6][1] = myPipe2;
}
void setup_enemy(enemy &myEnemy, SDL_Surface** DATA_OBJECTS_SURFACES, int DATA_LEVEL)
{
    myEnemy.image = DATA_OBJECTS_SURFACES[34];
    myEnemy.status = 34;
    myEnemy.y = get_screen_height() - get_earth_height() - DATA_OBJECTS_SURFACES[34]->h + 5;
    myEnemy.walk_counter = 0;
    if (DATA_LEVEL == 1)
    {
        myEnemy.v = 3;
        myEnemy.x = 3000;
        myEnemy.startx = 3000;
        myEnemy.endx = 3500;
    }
    if (DATA_LEVEL == 2)
    {
        myEnemy.v = 4;
        myEnemy.x = 1000;
        myEnemy.startx = 1000;
        myEnemy.endx = 2000;
    }
    if (DATA_LEVEL == 3)
    {
        myEnemy.v = 5;
        myEnemy.x = 3500;
        myEnemy.startx = 3000;
        myEnemy.endx = 4000;
    }
}