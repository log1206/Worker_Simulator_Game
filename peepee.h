

#ifndef PEEPEE_H_INCLUDED
#define PEEPEE_H_INCLUDED


#include "computer.h"
class Peepee
{
public:
    Peepee()
    {
    img = al_load_bitmap("./peepee.png");
    interface1 = al_load_bitmap("./interface/peepee_interface.png");

     sample = al_load_sample("peeing.wav");
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
    void process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state);

private:
    int x =650;
    int y =120;
    int off_x= 150;
    int off_y= 200;
    int play_x=150;
    int dir =-1;
    int drip=0;
    bool actived= false;

    ALLEGRO_BITMAP *img;
    ALLEGRO_BITMAP *interface1;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound = NULL;

};


#endif // COMPUTER_H_INCLUDED


