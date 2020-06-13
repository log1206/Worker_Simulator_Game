#include "paper.h"


int Paper::getx(){
    return x;
}
int Paper::gety(){
    return y;
}
void Paper::setActive(){
    if(actived)
        actived =false;
    else
        actived = true;
}
void Paper::setcd(){
    cd = true;
}
bool Paper::isActived(){
    return (actived==true)? true:false;
}
void Paper::setskin(int k){
    skin = k;
}



void Paper::process(ALLEGRO_EVENT event, int mouse_x, int mouse_y, Status * player_state){

    if(isActived()){

            if(test.empty()){
            //play music and go out
            player_state->coin_change(30);
            al_play_sample_instance(Sound);

            //while(al_get_sample_instance_playing(Sound));

            setActive();
        }



        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {




        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {



        }


        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)    setActive();

            if(event.keyboard.keycode == num_to_key[test[0]]){
                test.erase(test.begin());
            }
        }




    }
    else{

        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if(event.mouse.button == 1) {
                if(isover(mouse_x, mouse_y)&& cd==true) {
                        setActive();
                        int i=rand()%3;    //need to change to random
                        for(int j=0;j<(test_set[i]).size();j++){

                            test.push_back((test_set[i])[j]);
                        }
                        cd =false;
                }
            }
        }


    }

}

void Paper::draw(){


    char buffer[50];

    if(actived){
        //al_draw_filled_rectangle(100,130,100+interface_width,100+interface_height,al_map_rgb(255,255,255));
        al_draw_bitmap(interface1,110,110,0);
        al_draw_text(menuFont, al_map_rgb(0, 0, 0), 150, 150, 0, "follow the instruction");
       // al_draw_bitmap(up, 150*60, 200, 0);
        int length= test.size();
        //std::cout << length<<"\n";
     //   std::cout << test[0]<< test[1]<<test[2]<< test[3]<<test[4]<< test[5]<<test[6];
        int j=0;
        for(int i=0;i <length;i++ ){
              // std::cout << test[i];

            switch(test[i]){

            case '1':

                al_draw_bitmap(up, 150+(i%6)*60, (i/6)*50+200, 0);
                break;
            case '2':
                al_draw_bitmap(down, 150+(i%6)*60, (i/6)*50+200, 0);
                break;
            case '3':
                al_draw_bitmap(left, 150+(i%6)*60, (i/6)*50+200, 0);
                break;
            case '4':
                al_draw_bitmap(right, 150+(i%6)*60, (i/6)*50+200, 0);
                break;

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

        if(cd==true){
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
bool Paper::isover(int m_x,int m_y){


    if(m_x > x && m_x < x+off_x && m_y > y && m_y < y+off_y){

        return true;
    }
    return false;
}
