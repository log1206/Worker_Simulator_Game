

#include "peepee.h"


int Peepee::getx(){
    return x;
}
int Peepee::gety(){
    return y;
}
void Peepee::setActive(){
    if(actived)
        actived =false;
    else
        actived = true;
}
bool Peepee::isActived(){
    return (actived==true)? true:false;
}

void Peepee::process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state){

     if(isActived()){

            if(dir==1){
                if(play_x <340)
                    play_x +=2;
            }
            else{
                if(play_x>150)
                    play_x -= 2;
            }

        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            if(event.mouse.button ==2 ){
               dir=1;
            }


        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

            if(event.mouse.button ==2){
               dir=-1;
            }


        }


        if(play_x > 290&& play_x<320 && player_state->get_peepee()>0){
            drip+=1;

            if(drip==30){
                drip=0;
                if(player_state->get_peepee()<6)    player_state->peepee_to(0);
                else    player_state->peepee_change(-6);
            }

            al_play_sample_instance(Sound);
        }

        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)    setActive();
        }




    }
    else{

        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if(event.mouse.button == 1) {
                if(isover(mouse_x, mouse_y)) setActive();
            }

        }


    }

}

void Peepee::draw(){



    if(actived){
       al_draw_bitmap(interface1,110,110,0);
       //int d_x =play_x/2;
       if(play_x>290 && play_x<320) al_draw_arc(90+play_x,350,play_x-100,3.3,3,al_map_rgb(0,255,255),3);
        else if(play_x>160)al_draw_arc(90+play_x,350,play_x-100,3.2,3,al_map_rgb(255,255,255),3);
       //al_draw_line(play_x, 440, play_x, 460,al_map_rgb(0,250,250), 5);
    }
    else{
        al_draw_bitmap(img, x, y, 0);


        /*
        al_draw_line(x, y, x, off_y+y,al_map_rgb(0,250,250), 1);
        al_draw_line(off_x+x, y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
        al_draw_line(x, y, off_x+x, y,al_map_rgb(0,250,250), 1);
        al_draw_line(x, off_y+y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
        */
    }
}
bool Peepee::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+off_x && m_y > y && m_y < y+off_y){

        return true;
    }
    return false;
}
