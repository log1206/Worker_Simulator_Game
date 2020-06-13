#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro.h> //my add
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>//try add
#include <vector>
#include <list>
#include <time.h>
//#include <stdlib.h>
#include <iostream>

#include "Slider.h"
#include "Status.h"
#include "Computer.h"

#include "Phone.h"
#include "Peepee.h"
#include "Vendor.h"
#include "Paper.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7
#define GAME_FINISH 8

// clock rate
const float FPS = 60;



// 1 coin every 2 seconds
const int CoinSpeed = FPS * 2;


class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();
    void game_title();
    void game_option();
    void game_end();
    void game_finish();
    void game_help();

    void sound_control();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);
    // detect if a tower will be constructed on road
    void game_loading();

public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *title = NULL; //my title
    ALLEGRO_BITMAP *finish_back = NULL;
    ALLEGRO_BITMAP *rank1;
    ALLEGRO_BITMAP *win;
    ALLEGRO_BITMAP *win_n;
    ALLEGRO_BITMAP *peepee_end;
    ALLEGRO_BITMAP *hunger_end;
    ALLEGRO_BITMAP *select;
    ALLEGRO_BITMAP *help;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *title_music = NULL;
    ALLEGRO_SAMPLE_INSTANCE *warn = NULL;
    ALLEGRO_SAMPLE_INSTANCE *timesup = NULL;

    Slider *slider_v =NULL; //myadd
    Slider *slider_e =NULL; //myadd

    //for status
    Status *player_state=NULL;

    Computer *player_computer=NULL;
    Paper *player_paper=NULL;
    Phone *player_phone=NULL;
    Vendor *player_vendor=NULL;
    Peepee *player_peepee=NULL;



    int mouse_x, mouse_y;
    float sound_e;
    float sound_v;

    int entry =0;

    int pause =0;
    bool redraw = false;
    bool mute = false;


    int count_t=0;
    int time_r=90;

    int now_actived =-1;    //1 for Computer
                        //2 for paper
                        //3 for phone
                        //4 for peepee
                        //5 for vendor


};


#endif // MAINWINDOW_H_INCLUDED
