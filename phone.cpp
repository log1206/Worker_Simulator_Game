
#include "phone.h"


int Phone::getx(){
    return x;
}
int Phone::gety(){
    return y;
}
void Phone::setActive(){
    if(actived)
        actived =false;
    else
        actived = true;
}

bool Phone::isActived(){
    return (actived==true)? true:false;
}

void Phone::setskin(int k){
    skin = k;
}


void Phone::process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state){

    if(isActived()){



        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            for(int i=0;i<6;i++){

                if(choose[i]->isover(mouse_x,mouse_y)){

                    if(choose[i]->getcost()<=player_state->get_coin()){
                        player_state->coin_change(-choose[i]->getcost());
                        player_state->hunger_change(-choose[i]->getyummy());
                        player_state->peepee_change(choose[i]->getwater());
                         al_play_sample_instance(Sound);
                    }

                }
            }


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

void Phone::draw(int mouse_x,int mouse_y){



    char buffer[50];



    if(actived){
        al_draw_bitmap(interface1,110,110,0);
         for(int i=0;i<6;i++){
           choose[i]->draw();
         }
         for(int i=0;i<6;i++){
           if(choose[i]->isover(mouse_x,mouse_y)){
                al_draw_filled_rectangle(mouse_x,mouse_y,mouse_x+120,mouse_y+100,al_map_rgb(250,250,250));
                sprintf(buffer, "yummy: %d", choose[i]->getyummy());
                al_draw_text(menuFont, al_map_rgb(155, 155, 155),  mouse_x+10,mouse_y+20, 0, buffer);
                sprintf(buffer, "water: %d", choose[i]->getwater());
                al_draw_text(menuFont, al_map_rgb(155, 155, 155),  mouse_x+10,mouse_y+40, 0, buffer);
                sprintf(buffer, "cost: %d", choose[i]->getcost());
                al_draw_text(menuFont, al_map_rgb(155, 155, 155),  mouse_x+10,mouse_y+60, 0, buffer);


           }
         }


    }
    else{
        if(skin==1){
            al_draw_bitmap(img1, x, y, 0);
        }
        else if(skin==2){
            al_draw_bitmap(img2, x, y, 0);
        }
        /*
        al_draw_line(x, y, x, off_y+y,al_map_rgb(0,250,250), 1);
        al_draw_line(off_x+x, y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
        al_draw_line(x, y, off_x+x, y,al_map_rgb(0,250,250), 1);
        al_draw_line(x, off_y+y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
        */
    }
}
bool Phone::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+off_x && m_y > y && m_y < y+off_y){

        return true;
    }
    return false;
}
