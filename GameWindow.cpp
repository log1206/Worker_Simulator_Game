#include "GameWindow.h"
#include "global.h"
#include <iostream>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))



// my add

void
GameWindow::game_init()
{


    //load the icon and two background
    icon = al_load_bitmap("./icon.png");
    background = al_load_bitmap("./StartScene/background_game.png");
    title = al_load_bitmap("./StartScene/Background.png");
    finish_back = al_load_bitmap("./StartScene/finish_back.png");
    rank1 = al_load_bitmap("./rank1.png");
    win = al_load_bitmap("./win.png");
    win_n = al_load_bitmap("./win_n.png");
    hunger_end = al_load_bitmap("./hunger_end.png");
    peepee_end = al_load_bitmap("./peepee_end.png");
    select = al_load_bitmap("./select.png");
    help= al_load_bitmap("./help.png");

    al_set_window_title(display,"LiverGame");
    al_set_display_icon(display, icon);
    al_reserve_samples(3);


    //for sound effect growl
    sample = al_load_sample("start.wav");
    startSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());


    //background song
    sample = al_load_sample("back_music.wav");       // change the song
    backgroundSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());

    sample = al_load_sample("title_music.wav");       // warn
    title_music = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(title_music, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(title_music, al_get_default_mixer());

    sample = al_load_sample("fail.wav");       // fail
    failSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(failSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(failSound, al_get_default_mixer());

    sample = al_load_sample("warn.wav");       // warn
    warn = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(warn, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(warn, al_get_default_mixer());

    sample = al_load_sample("win.wav");       // warn
    clearSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(clearSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(clearSound, al_get_default_mixer());

    sample = al_load_sample("timesup.wav");       // warn
    timesup = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(timesup, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(timesup, al_get_default_mixer());




    //slider create
    slider_e = new Slider(al_get_display_width(al_get_current_display()) / 3 + 35,200); // my add
    slider_v = new Slider(al_get_display_width(al_get_current_display()) / 3 + 35,350); // my add
    slider_v->set_label_content("volume");
    slider_e->set_label_content("effect volume");

    // for status create
    player_state = new Status();

    //computer new

    player_computer = new Computer();


    //paper new
    player_paper = new Paper();

    //phone new
    player_phone = new Phone();

    //peepee new
    player_peepee = new Peepee();

    //vendor new
    player_vendor = new Vendor();

}

bool
GameWindow::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}

void
GameWindow::game_loading(){

    int msg;
    msg = -1;


    while(1){

        if(entry==0){
            game_reset();
            game_title();

        }
        else if(entry==1){       //react to the state then enter
            game_begin();
           // set_gfx_mode(display, 1200, 900, 0, 0);
            while(msg != GAME_EXIT)
            {
                msg = game_run();

            }
            msg =-1;
            entry=3;

        }
       // else if(entry==2){

      //      game_option();
      //  }
        else if(entry==3){

            game_finish();
        }

    }


}
void
GameWindow::game_finish(){



     al_clear_to_color(al_map_rgb(100, 100, 100));   //draw part
        al_draw_bitmap(finish_back, 0, 0, 0);

        if(player_state->get_hunger()>=100){
            al_draw_bitmap(hunger_end, 70,100 , 0);
            al_draw_text(Large_font,BLACK,330,440,0,"stay hungry I'm foolish");
            al_play_sample_instance(failSound);

        }
        else if(player_state->get_peepee()>=100){

            al_draw_bitmap(peepee_end, 70,100 , 0);
            al_draw_text(Large_font,BLACK,330,440,0,"I can't take it any more");
            al_play_sample_instance(failSound);

        }
        else if(player_state->get_coin()>=100){
            al_draw_bitmap(rank1, 500,350 , 0);
            al_draw_bitmap(win_n, 70,80 , 0);
            al_draw_text(Large_font,BLACK,330,440,0,"Stonk!");
            al_play_sample_instance(clearSound);
        }
        else{
            al_draw_bitmap(win, 70,80 , 0);
            al_draw_text(Large_font,BLACK,330,440,0,"Nice Job");
            al_play_sample_instance(clearSound);
        }


    while(1){



        player_state->draw(350,100);

        al_draw_text(Large_font,BLACK,300,550,0,"press _R_ to title");
        al_flip_display();

        al_wait_for_event(event_queue, &event); //start receive event

        if(event.keyboard.keycode==ALLEGRO_KEY_R){
            entry=0;
            break;
        }

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)   game_destroy();

        if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
        }

    }

}


void
GameWindow::game_play()
{
    int msg;

    srand(time(NULL));
    msg = -1;
    game_reset();
    game_loading();

}

void
GameWindow::game_help(){
    Button *go_back = new Button(520,490,150,60);

    while(1){
            al_clear_to_color(al_map_rgb(100, 100, 100));       //draw part
            al_draw_bitmap(help, 0, 0, 0);
            if(go_back->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(520,490,670,550,ORANGE_DARK);
            else al_draw_filled_rectangle(520,490,670,550,ORANGE_LIGHT);
            al_draw_text(Large_font, al_map_rgb(255, 255, 255), 550, 500, 0, "back");
            al_flip_display();
            al_wait_for_event(event_queue, &event);

            if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
                mouse_x = event.mouse.x;
                mouse_y = event.mouse.y;
            }
            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                if(event.mouse.button==1){
                    if(go_back->isover(event.mouse.x,event.mouse.y))
                        break;
                }

            }

            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) game_destroy();


        }
                           //volume control

        delete go_back;



}

void
GameWindow::game_option()
{

        pause=1;
        Button *go_back = new Button(320,490,150,60);

        while(1){


            al_clear_to_color(al_map_rgb(100, 100, 100));       //draw part
            al_draw_bitmap(background, 0, 0, 0);
            if(go_back->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(320,490,470,550,ORANGE_DARK);
            else al_draw_filled_rectangle(320,490,470,550,ORANGE_LIGHT);
            al_draw_text(Large_font, al_map_rgb(255, 255, 255), 350, 500, 0, "back");
            al_draw_filled_rounded_rectangle(200,50,600,450,50,50,al_map_rgb(246,243,153));
            sound_control();
            al_flip_display();
            al_wait_for_event(event_queue, &event);


            if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
                mouse_x = event.mouse.x;
                mouse_y = event.mouse.y;
            }
            if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                if(event.mouse.button==1){
                    if(go_back->isover(event.mouse.x,event.mouse.y))
                        pause=0;
                        break;
                }

            }


 /*           if(event.keyboard.keycode==ALLEGRO_KEY_O) {
               pause=0;


               break;
            }
*/
            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) game_destroy();









        }
                           //volume control

        delete go_back;
}

void
GameWindow::sound_control(){

    ALLEGRO_MOUSE_STATE state_f_sound;

  //  int down=0;
    int cur_x,cur_y;


    al_wait_for_event(event_queue, &event);
    if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

        if(event.mouse.button==1){//&&down==0
           // down=1;
            cur_x =event.mouse.x;
            cur_y =event.mouse.y;

            if(slider_e->isClicked(cur_x,cur_y))slider_e->toggleDrag();
            if(slider_v->isClicked(cur_x,cur_y))slider_v->toggleDrag();

        }
    }

    if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){//&&down==1
            //down=0;
            //cur_x =event.mouse.x;
        //    cur_y =event.mouse.y;
            if(slider_e->isDragged()){
                 slider_e->toggleDrag();
                 al_play_sample_instance(startSound);
            }
            if(slider_v->isDragged()){
                slider_v->toggleDrag();
            }
    }


    if(slider_e->isDragged()){
        al_get_mouse_state(&state_f_sound);
        slider_e->Drag( state_f_sound.x , state_f_sound.y);
        sound_e =slider_e->getDegree();
        al_set_sample_instance_gain(startSound, sound_e);

    }
    else if(slider_v->isDragged()){
        al_get_mouse_state(&state_f_sound);
        slider_v->Drag(state_f_sound.x,state_f_sound.y);
        sound_v = slider_v->getDegree();
        al_set_sample_instance_gain(backgroundSound, sound_v);

    }

    slider_e->Draw();     //my add
    slider_v->Draw();     //my add
    al_flip_display();


}

void GameWindow::game_end(){

    game_destroy();

}



void
GameWindow::game_title()
{

    Button * play = new Button(250,310,520-250,350-310);
    Button * option = new Button(250,380,270,40);
    Button * guide = new Button(250,450,270,40);
    bool in_option=false;

    al_play_sample_instance(title_music);

    al_clear_to_color(al_map_rgb(100, 100, 100));   //draw part
    al_draw_bitmap(title, 0, 0, 0);
    if(play->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(play->getx(),play->gety(),520,350,ORANGE_DARK);
    else al_draw_filled_rectangle(play->getx(),play->gety(),520,350,ORANGE_LIGHT);

    if(option->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(option->getx(),option->gety(),520,420,ORANGE_DARK);
    else al_draw_filled_rectangle(option->getx(),option->gety(),520,420,ORANGE_LIGHT);

    if(guide->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(guide->getx(),guide->gety(),520,490,ORANGE_DARK);
    else al_draw_filled_rectangle(guide->getx(),guide->gety(),520,490,ORANGE_LIGHT);



    al_draw_text(Large_font, al_map_rgb(255, 255, 255), 335, 375, 0, "option");
    al_draw_text(Large_font, al_map_rgb(255, 255, 255), 345, 450, 0, "help");
    al_draw_text(Large_font, al_map_rgb(255, 255, 255), 340, 310, 0, "start");
    // al_draw_text(Medium_font, al_map_rgb(255, 255, 255), 300, 525, 0, "press 'o' to option");

    al_flip_display();




    while(1){               //doing with the state control


        al_wait_for_event(event_queue, &event); //start receive event

        if(event.keyboard.keycode==ALLEGRO_KEY_1){
            entry=1;
            break;
        }
        else if(event.keyboard.keycode==ALLEGRO_KEY_2){
            game_option();
        }


        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(event.mouse.button==1){
              //  std::cout <<"x: " <<mouse_x << " y: " << mouse_y<<"\n";

                if(play->isover(mouse_x,mouse_y)&&in_option==false)  {
                    entry=1;
                    break;
                }
                else if(option->isover(mouse_x,mouse_y)&&in_option==false){

                    in_option =true;
                    game_option();
                    in_option =false;

                }
                 else if(guide->isover(mouse_x,mouse_y)&&in_option==false){

                    game_help();

                }
            }


        }









        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)   game_destroy();

        if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
        }

        al_clear_to_color(al_map_rgb(100, 100, 100));   //draw part
        al_draw_bitmap(title, 0, 0, 0);
        if(play->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(play->getx(),play->gety(),520,350,ORANGE_DARK);
        else al_draw_filled_rectangle(play->getx(),play->gety(),520,350,ORANGE_LIGHT);

        if(option->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(option->getx(),option->gety(),520,420,ORANGE_DARK);
        else al_draw_filled_rectangle(option->getx(),option->gety(),520,420,ORANGE_LIGHT);

        if(guide->isover(mouse_x,mouse_y)) al_draw_filled_rectangle(guide->getx(),guide->gety(),520,490,ORANGE_DARK);
        else al_draw_filled_rectangle(guide->getx(),guide->gety(),520,490,ORANGE_LIGHT);



        al_draw_text(Large_font, al_map_rgb(255, 255, 255), 335, 375, 0, "option");
        al_draw_text(Large_font, al_map_rgb(255, 255, 255), 345, 450, 0, "help");
        al_draw_text(Large_font, al_map_rgb(255, 255, 255), 340, 310, 0, "start");
        // al_draw_text(Medium_font, al_map_rgb(255, 255, 255), 300, 525, 0, "press 'o' to option");

        al_flip_display();



    }
    al_stop_sample_instance(title_music);

    delete  play;
    delete option;
    delete  guide;
}





void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}





GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);



    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    game_init();
}

void
GameWindow::game_begin()
{



    al_play_sample_instance(startSound);
    while(al_get_sample_instance_playing(startSound));
    al_play_sample_instance(backgroundSound);
    draw_running_map();
    al_start_timer(timer);

}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;


    if (!al_is_event_queue_empty(event_queue)) {

        error = process_event();
    }
    return error;
}

int
GameWindow::game_update()
{
    unsigned int i, j;



    return GAME_CONTINUE;
}

void
GameWindow::game_reset()
{
    // reset game and begin


    mute = false;
    redraw = false;
    time_r =90;
    entry =0;
    now_actived=0;
    pause =0;
    player_state->coin_to(0);
    player_state->happiness_to(0);
    player_state->hunger_to(50);
    player_state->peepee_to(25);
    player_state->stress_to(25);
    if(player_computer->isActived())    player_computer->setActive();
    if(player_phone->isActived())    player_phone->setActive();
    if(player_paper->isActived())    player_paper->setActive();
    if(player_peepee->isActived())    player_peepee->setActive();
    if(player_vendor->isActived())    player_vendor->setActive();
    // stop sample instance
    al_stop_sample_instance(backgroundSound);
    al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);

}

void
GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);


    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);

    al_destroy_sample(sample);
    al_destroy_sample_instance(startSound);
    al_destroy_sample_instance(backgroundSound);

    delete [] slider_e;
    delete [] slider_v;

    delete [] player_computer;
    delete [] player_state;


}

int
GameWindow::process_event()
{
    int i;
    int instruction = GAME_CONTINUE;

    if(player_state->get_hunger()>100|| player_state->get_peepee()>100 ||player_state->get_happiness()>100) {      //see if time run out
        al_stop_sample_instance(backgroundSound);
        al_play_sample_instance(timesup);
        while(al_get_sample_instance_playing(timesup));
        return GAME_EXIT;
    }

    if(player_state->get_hunger()>=90 ||player_state->get_peepee()>=90){
        al_play_sample_instance(warn);
    }






    al_wait_for_event(event_queue, &event);
    redraw = false;


    switch(now_actived){
        case 1:
            player_computer->process(event, mouse_x, mouse_y, player_state);
            break;
        case 2:
            player_paper->process(event, mouse_x, mouse_y, player_state);
            break;
        case 3:
            player_phone->process(event, mouse_x, mouse_y, player_state);
            break;
        case 4:
            player_peepee->process(event, mouse_x, mouse_y, player_state);
            break;
        case 5:
            al_stop_timer(timer);
            player_vendor->process(event, mouse_x, mouse_y, player_state);

            break;
        default:
            player_computer->process(event, mouse_x, mouse_y, player_state);
            player_paper->process(event, mouse_x, mouse_y, player_state);
            player_phone->process(event, mouse_x, mouse_y, player_state);
            player_vendor->process(event, mouse_x, mouse_y, player_state);
            player_peepee->process(event, mouse_x, mouse_y, player_state);
            al_start_timer(timer);

    }


    if(player_computer->isActived()) now_actived=1;
    else if(player_paper->isActived()) now_actived=2;
    else if(player_phone->isActived()) now_actived=3;
    else if(player_peepee->isActived()) now_actived=4;
    else if(player_vendor->isActived()) now_actived=5;
    else now_actived=-1;


    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            redraw = true;

            if(count_t>60) {            //count time
                count_t=0;
                player_state->hunger_change(1);
                player_state->happiness_change(1);
                time_r--;

                int x=rand()%10;                    //random give task
                if(x>5&& !player_paper->isActived()){
                    player_paper->setcd();
                }
                x=rand()%10;
                if(x>5&& !player_computer->isActived()){
                    player_computer->setcd();
                }
            }
            else count_t++;


           //do thing with timer count


        }
        else {
            //do thing when not timer
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            game_destroy();
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_P:

                while(1){
                    game_option();
                    entry=2;
                    if(pause==0)    break;
                }

            break;

            case ALLEGRO_KEY_M:
                mute = !mute;
                if(mute)
                    al_stop_sample_instance(backgroundSound);
                else
                    al_play_sample_instance(backgroundSound);
                break;


        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if(event.mouse.button == 1) {

        }
        else if (event.mouse.button==2){        //if mouse keft button down get money

        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;

    }


    player_computer->setskin(player_vendor->get_for_computer());
    player_paper->setskin(player_vendor->get_for_paper());
    player_phone->setskin(player_vendor->get_for_phone());

   // if(redraw) {
        // update each object in game
       // instruction = game_update();

        // Re-draw map

        draw_running_map();


     //   redraw = false;
   // }

    return instruction;
}

void
GameWindow::draw_running_map()
{
    unsigned int i, j;
    char buffer[50];

    al_clear_to_color(al_map_rgb(100, 100, 100));
    al_draw_bitmap(background, 0, 0, 0);

  //  sprintf(buffer, "Timer: %lld",time_r );
  //  al_draw_text(Large_font, al_map_rgb(255, 255, 255), 20, 20, 0, buffer);
   // al_draw_filled_rectangle(field_width, 0, window_width, window_height, al_map_rgb(100, 100, 100));

    switch(now_actived){
        case 1:
            player_computer->draw();
            break;
        case 2:
            player_paper->draw();
            break;
        case 3:
            player_phone->draw(mouse_x,mouse_y);
            break;
        case 4:
            player_peepee->draw();
            break;
        case 5:
            player_vendor->draw(mouse_x,mouse_y);
            break;
        default:
            player_computer->draw();
            player_paper->draw();
            player_phone->draw(mouse_x,mouse_y);
            player_peepee->draw();
            player_vendor->draw(mouse_x,mouse_y);
            if(player_peepee->isover(mouse_x,mouse_y)) al_draw_bitmap(select,player_peepee->getx(),player_peepee->gety(),0);
            if(player_paper->isover(mouse_x,mouse_y)) al_draw_bitmap(select,player_paper->getx(),player_paper->gety(),0);
            if(player_phone->isover(mouse_x,mouse_y)) al_draw_bitmap(select,player_phone->getx(),player_phone->gety(),0);
            if(player_computer->isover(mouse_x,mouse_y)) al_draw_bitmap(select,player_computer->getx(),player_computer->gety(),0);
            if(player_vendor->isover(mouse_x,mouse_y)) al_draw_bitmap(select,player_vendor->getx(),player_vendor->gety(),0);
    }
        player_state->draw();


       al_flip_display();

}
