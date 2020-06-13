

#ifndef VENDOR_H_INCLUDED
#define VENDOR_H_INCLUDED


#include "computer.h"
class Vendor
{
public:
    Vendor()
    {
    img = al_load_bitmap("./vendor.png");
    menuFont = al_load_ttf_font("pirulen.ttf", 24, 0); // load font
    interface1 = al_load_bitmap("./interface/vendor_interface.png");


    sample = al_load_sample("correct.wav");
    Sound1 = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(Sound1, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(Sound1, al_get_default_mixer());
    sample = al_load_sample("wrong.wav");
    Sound2 = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(Sound2, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(Sound2, al_get_default_mixer());
    for(int i=0;i<6;i++){
        Button * tmp = new Button((i%2)*100+280,(i/2)*100+190, 50,50);
        choose.push_back(tmp);
    }
    gacha =new Button(620,390,50,50);


    }

    int getx();
    int gety();
    void draw(int,int);
    bool isover(int, int);
    void setActive();
    bool isActived();
    int get_for_computer();
    int get_for_paper();
    int get_for_phone();

    void process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state);

private:
    int x =30;
    int y =30;
    int off_x= 150;
    int off_y= 200;
    bool actived= false;
    bool enable[8] ={true,true,true,true,true,true,true,true};
    int for_computer =1;
    int for_paper =1;
    int for_phone =1;
    int lock=1;
    ALLEGRO_BITMAP *img;
    ALLEGRO_FONT* menuFont;
    ALLEGRO_BITMAP *interface1;
    Button * gacha=NULL;
    std::vector<Button*> choose;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound1 = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound2 = NULL;

};


#endif // COMPUTER_H_INCLUDED


