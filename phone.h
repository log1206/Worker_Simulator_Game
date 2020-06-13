

#ifndef PHONE_H_INCLUDED
#define PHONE_H_INCLUDED


#include "computer.h"
class Phone
{
public:
    Phone()
    {
    img1 = al_load_bitmap("./item/phone_1.png");
    img2 = al_load_bitmap("./item/phone_2.png");
    interface1 = al_load_bitmap("./interface/phone_interface.png");

    sample = al_load_sample("buy.wav");
    Sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(Sound, al_get_default_mixer());
    for(int i=0;i<6;i++){
        Button * tmp = new Button((i%3+2)*100+85,(i/3+2)*115+30, 50,50,food_set[i],food_set_yummy[i],food_set_water[i],foodset_cost[i]);
        choose.push_back(tmp);
    }

    menuFont = al_load_ttf_font("pirulen.ttf", 12, 0); // load font

    }

    int getx();
    int gety();
    void draw(int,int);
    bool isover(int, int);
    void setActive();
    void setskin(int);
    bool isActived();
    void process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state);

private:
    int x =460;
    int y =250;
    int off_x= 150;
    int off_y= 200;
    int skin =1;
    bool actived= false;

    ALLEGRO_BITMAP *img1;
    ALLEGRO_BITMAP *img2;
    ALLEGRO_FONT* menuFont;
    std::vector<Button*> choose;

    std::string food_set[8] ={"happy_water","burger_set","normal_water","tabioka_milktea","instant_food","xxx"};
    int food_set_yummy[8] ={20,10,3,8,5,50};
    int food_set_water[8] ={30,10,15,20,5,10};
    int foodset_cost[8] ={20,10,0,15,5,50};

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound = NULL;

     ALLEGRO_BITMAP *interface1;
};


#endif // COMPUTER_H_INCLUDED


