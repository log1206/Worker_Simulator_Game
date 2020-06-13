
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#include "vendor.h"


int Vendor::getx(){
    return x;
}
int Vendor::gety(){
    return y;
}
void Vendor::setActive(){
    if(actived)
        actived =false;
    else
        actived = true;
}
bool Vendor::isActived(){
    return (actived==true)? true:false;
}

int Vendor::get_for_computer(){
    return for_computer;
}

int Vendor::get_for_paper(){
    return for_paper;
}
int Vendor::get_for_phone(){
    return for_phone;
}
void Vendor::process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state){

    if(isActived()){



        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {




            for(int i=0;i<6;i++){

                if(choose[i]->isover(mouse_x,mouse_y)){

                    if(enable[i]==true){
                        switch(i){

                           case 0:
                                for_computer = 1;
                                break;
                           case 1:
                                for_computer =2;
                                break;
                           case 2:
                                for_paper = 1;
                                break;
                           case 3:
                                for_paper = 2;
                                break;
                           case 4:
                                for_phone = 1;
                                break;
                           case 5:
                                for_phone= 2;
                                break;
                        }
                    }

                }
            }

            if(gacha->isover(mouse_x,mouse_y)){
                if(player_state->get_coin()>0){
                    player_state->coin_change(-1);
                    int x =rand()%5;
                    if(x==0){
                        //play_unlock;

                        for(int i=0;i<8;i++){
                            enable[i] =true;
                            lock =0;
                            al_play_sample_instance(Sound1);
                        }
                    }
                    else{
                            if(player_state->get_hunger()>5) player_state->hunger_change(-5);
                            if(player_state->get_peepee()>5) player_state->peepee_change(-5);

                            al_play_sample_instance(Sound2);

                    }
                }
            }
            if(event.mouse.button==2){
                player_state->happiness_change(5);
            }






        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {




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

void Vendor::draw(int mouse_x, int mouse_y){




    char buffer[50];


    if(actived){



        al_draw_bitmap(interface1, 110, 110, 0);

      for(int i=0;i<6;i++){


           if(i%2==1  && lock==1){

           }
           else {
                if(choose[i]->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(choose[i]->getx(),choose[i]->gety(),choose[i]->getx()+50,choose[i]->gety()+50,ORANGE_DARK);
                else al_draw_filled_rectangle(choose[i]->getx(),choose[i]->gety(),choose[i]->getx()+50,choose[i]->gety()+50,ORANGE_LIGHT);
                sprintf(buffer,"%d",i%2+1);
                al_draw_text(menuFont,al_map_rgb(0,0,0),choose[i]->getx()+10,choose[i]->gety()+10,0,buffer);

           }

         }

          if(gacha->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(gacha->getx(),gacha->gety(),gacha->getx()+50,gacha->gety()+50,ORANGE_DARK);
          else al_draw_filled_rectangle(gacha->getx(),gacha->gety(),gacha->getx()+50,gacha->gety()+50,ORANGE_LIGHT);

        al_draw_text(menuFont,al_map_rgb(0,0,0),gacha->getx()+10,gacha->gety()+10,0,"$1");
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
bool Vendor::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+off_x && m_y > y && m_y < y+off_y){

        return true;
    }
    return false;
}
