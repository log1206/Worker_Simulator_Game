#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

#include <allegro5/allegro.h> //my add
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>//try add
#include <allegro5/allegro_primitives.h>
#include "status.h"
#include "button.h"
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <stack>
#include <vector>
#define interface_width 600
#define interface_height 400

class Computer
{
public:
    Computer(){
    img1 = al_load_bitmap("./item/computer_1.png");
    img2 = al_load_bitmap("./item/computer_2.png");
    interface1 = al_load_bitmap("./interface/computer_interface.png");
    cd_ok =al_load_bitmap("./cd_ok.png");
    menuFont = al_load_ttf_font("pirulen.ttf", 24, 0); // load font
    sample = al_load_sample("boom.wav");
    Sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(Sound, al_get_default_mixer());

    }
    int getx();
    int gety();
    void draw();
    bool isover(int, int);
    void setActive();
    bool isActived();
    void setskin(int);
    void setcd();
    void process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state);

private:
    int x =110;
    int y =280;
    int off_x= 150;
    int off_y= 200;
    int keydown=0;
    int brick=0;
    int skin =1;
    bool actived= false;
    bool cd=false;
    ALLEGRO_BITMAP *img1;
    ALLEGRO_BITMAP *img2;
    ALLEGRO_BITMAP *interface1;
     ALLEGRO_BITMAP *cd_ok;
    ALLEGRO_FONT* menuFont;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound = NULL;


};


#endif // COMPUTER_H_INCLUDED
