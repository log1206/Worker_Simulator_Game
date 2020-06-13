
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "computer.h"
#include <string>
class Button
{
public:
    Button(int pos_x, int pos_y, int w, int h){

        x = pos_x;
        y = pos_y;
        width = w;
        height =h;
        img = al_load_bitmap("./SettingScene/up.png");
    }
    Button(int pos_x, int pos_y, int w, int h, std::string str){

        x = pos_x;
        y = pos_y;
        width = w;
        height =h;
        name =str;
        img = al_load_bitmap("./SettingScene/up.png");
    }
    Button(int pos_x, int pos_y, int w, int h, std::string str, int yum, int wa, int cos){

        x = pos_x;
        y = pos_y;
        width = w;
        height =h;
        name =str;
        yummy =yum;
        water=wa;
        cost=cos;

        char buffer[50];
        if(name=="happy_water")
             img = al_load_bitmap("./SettingScene/happy_water.png");
        else if(name=="burger_set")
             img = al_load_bitmap("./SettingScene/burger.png");
        else if(name=="normal_water")
             img = al_load_bitmap("./SettingScene/normal_water.png");
        else if(name=="tabioka_milktea")
             img = al_load_bitmap("./SettingScene/tabioka_milktea.png");
        else if(name=="instant_food")
             img = al_load_bitmap("./SettingScene/instant_food.png");
        else if(name=="xxx")
             img = al_load_bitmap("./SettingScene/xxx.png");
        else{
            img = al_load_bitmap("./SettingScene/up.png");
        }

    }
    int getx();
    int gety();
    int getyummy();
    int getwater();
     int getcost();
    void draw();
    bool isover(int, int);


private:
    int x ;
    int y ;
    int height;
    int width;
    int yummy;
    int water;
    int cost;
    std::string name;

    ALLEGRO_BITMAP *img;


};


#endif // COMPUTER_H_INCLUDED
