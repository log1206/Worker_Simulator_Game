
#include "button.h"


int Button::getx(){
    return x;
}
int Button::gety(){
    return y;
}
int Button::getwater(){
    return water;
}
int Button::getyummy(){
    return yummy;
}
int Button::getcost(){
    return cost;
}


void Button::draw(){

        al_draw_bitmap(img, x, y, 0);

}

bool Button::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+width && m_y > y && m_y < y+height){

        return true;
    }
    return false;
}
