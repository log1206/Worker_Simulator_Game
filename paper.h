
#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED
#define word_length 7

#include "computer.h"
class Paper
{
public:
    Paper()
    {
    img1 = al_load_bitmap("./item/paper_1.png");
    img2 = al_load_bitmap("./item/paper_2.png");
    up = al_load_bitmap("./SettingScene/up.png");
    down = al_load_bitmap("./SettingScene/down.png");
    left = al_load_bitmap("./SettingScene/left.png");
    right = al_load_bitmap("./SettingScene/right.png");
    interface1 = al_load_bitmap("./interface/paper_interface.png");
    cd_ok =al_load_bitmap("./cd_ok.png");
    menuFont = al_load_ttf_font("pirulen.ttf", 12, 0); // load font
    sample = al_load_sample("good.wav");
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
    void setcd();
    void setskin(int);
    void process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state);

private:
    int x =280;
    int y =150;
    int off_x= 150;
    int off_y= 200;
    bool actived= false;
    bool cd =false;
    int skin =1;
    ALLEGRO_FONT* menuFont;
    std::map<int ,std::string> test_set ={{0,"21344121321"},{1, "1233421"},{2,"221342132"}};
    std::map<char ,int> num_to_key ={{'1',ALLEGRO_KEY_UP},{'2',ALLEGRO_KEY_DOWN},{'3',ALLEGRO_KEY_LEFT},{'4',ALLEGRO_KEY_RIGHT}};
    std::vector<char> test;
    ALLEGRO_BITMAP *img1;
    ALLEGRO_BITMAP *img2;
    ALLEGRO_BITMAP *up;
    ALLEGRO_BITMAP *down;
    ALLEGRO_BITMAP *left;
    ALLEGRO_BITMAP *right;
    ALLEGRO_BITMAP *interface1;
    ALLEGRO_BITMAP *cd_ok;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *Sound = NULL;
};


#endif // COMPUTER_H_INCLUDED


