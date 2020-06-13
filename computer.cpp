#include "computer.h"


int Computer::getx(){
    return x;
}
int Computer::gety(){
    return y;
}
void Computer::setActive(){
    if(actived)
        actived =false;
    else
        actived = true;
}
bool Computer::isActived(){
    return (actived==true)? true:false;
}
void Computer::setcd(){
    cd = true;
}
void Computer::setskin(int k){
    skin = k;
}
void Computer::process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state){
    if(isActived()){



        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            switch(event.keyboard.keycode)

            if(event.mouse.button ==2){     //add money
                player_state->coin_change(2);
            }

        }


    if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_SPACE:

                if(keydown==0) brick++;

                keydown =1;

            break;

            case ALLEGRO_KEY_ESCAPE:
                setActive();
                break;


        }
    }
    if(event.type ==ALLEGRO_EVENT_KEY_UP){
            switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_SPACE:

                keydown =0;
                break;




        }

    }

    if(brick ==25){

        player_state->coin_change(30);
        al_play_sample_instance(Sound);
        setActive();
    }



    }
    else{

        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if(event.mouse.button == 1) {
                if(isover(mouse_x, mouse_y)&& cd==true){

                    setActive();
                    brick =0;
                    keydown =0;
                    cd = false;
                }

            }

        }


    }


}


void Computer::draw(){







    if(actived){
        al_draw_bitmap(interface1,110,110,0);

        al_draw_text(menuFont,al_map_rgb(255,255,255),170,170,0,"STACK: gan ni nyan sai bou");
        al_draw_line(290,380,630,380,al_map_rgb(255,255,255),4);
        al_draw_line(290,380,290,250,al_map_rgb(255,255,255),4);
        al_draw_line(630,380,630,250,al_map_rgb(255,255,255),4);
        int j =brick/5;
        int brick_x=300;
        int brick_y=350;
        int brick_w=60;
        int brick_h=20;

        for(;j>=0;j--){
            for(int i=0;i <5;i++){
                if(i+j*5>=brick) break;
                al_draw_filled_rectangle(brick_x+65*i,brick_y-j*25,brick_x+brick_w+65*i,brick_y+brick_h-j*25,al_map_rgb(255,255,255));


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


        if(cd ==true){
                al_draw_bitmap(cd_ok,x-25,y-25,0);
        /*
            al_draw_line(x, y, x, off_y+y,al_map_rgb(0,250,250), 1);
            al_draw_line(off_x+x, y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
            al_draw_line(x, y, off_x+x, y,al_map_rgb(0,250,250), 1);
            al_draw_line(x, off_y+y, off_x+x, off_y+y,al_map_rgb(0,250,250), 1);
        */
        }


    }
}
bool Computer::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+off_x && m_y > y && m_y < y+off_y){

        return true;
    }
    return false;
}
