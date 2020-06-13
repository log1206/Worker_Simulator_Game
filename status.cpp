#include"status.h"


Status::Status(){

    this->coin =0;
    this->happiness= 0;
    this->hunger = 50;
    this->peepee = 25;
    this->stress = 25;

    coin_b = al_load_bitmap("./state_icon/coin.png");
    stress_b = al_load_bitmap("./state_icon/stress.png");
    happiness_b = al_load_bitmap("./state_icon/happiness.png");
    hunger_b = al_load_bitmap("./state_icon/hunger.png");
    peepee_b = al_load_bitmap("./state_icon/peepee.png");
    menuFont = al_load_ttf_font("pirulen.ttf", 12, 0); // load font
    status_b = al_load_bitmap("./status.png");
}


void Status::coin_change(int val){
    coin +=val;
}
void Status::stress_change(int val){
     stress +=val;
}
void Status::happiness_change(int val){
    happiness += val;
}
void Status::hunger_change(int val){
     hunger +=val;
}
void Status::peepee_change(int val){
     peepee +=val;
}

void Status::coin_to(int val){
    coin =val;
}
void Status::stress_to(int val){
     stress =val;
}
void Status::happiness_to(int val){
    happiness = val;
}
void Status::hunger_to(int val){
     hunger =val;
}
void Status::peepee_to(int val){
     peepee =val;
}

int Status::get_coin(){
    return coin;
}
int Status::get_stress(){
     return stress;
}
int Status::get_happiness(){
    return happiness;
}
int Status::get_hunger(){
     return hunger;
}
int Status::get_peepee(){
     return peepee;
}

void Status::draw(){

    char buffer[50];
    int x=200;
    int y=0;
    int off_x=600;
    int off_y=100;
    al_draw_filled_rounded_rectangle(x,y,off_x+x,off_y+y,50,50,al_map_rgb(50,50,50));
    al_draw_bitmap(status_b,x,y,0);


    sprintf(buffer, "%d", coin);
    al_draw_bitmap(coin_b, x+50, y+5, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+50, y+20, 0, buffer);

    sprintf(buffer, "%d", stress);
    al_draw_bitmap(stress_b, x+50, y+45, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+50, y+60, 0, buffer);

    sprintf(buffer, "%d", happiness);
    al_draw_bitmap(happiness_b, x+250, y+5, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+250,y+20, 0, buffer);

    sprintf(buffer, "%d", hunger);
    al_draw_bitmap(hunger_b, x+250, y+45, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+250, y+60, 0, buffer);

    sprintf(buffer, "%d", peepee);
    al_draw_bitmap(peepee_b, x+450, y+5, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+450, y+20, 0, buffer);



}
void Status::draw(int x,int y){

    char buffer[50];
    int off_x=600;
    int off_y=150;



    sprintf(buffer, "%d", coin);
    al_draw_bitmap(coin_b, x+50, y+20, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+150, y+30, 0, buffer);

    sprintf(buffer, "%d", stress);
    al_draw_bitmap(stress_b, x+50, y+70, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+150, y+80, 0, buffer);

    sprintf(buffer, "%d", happiness);
    al_draw_bitmap(happiness_b, x+50, y+120, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+150,y+130, 0, buffer);

    sprintf(buffer, "%d", hunger);
    al_draw_bitmap(hunger_b, x+50, y+160, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+150, y+170, 0, buffer);

    sprintf(buffer, "%d", peepee);
    al_draw_bitmap(peepee_b, x+50, y+200, 0);
    al_draw_text(menuFont, al_map_rgb(255, 255, 255), 2*al_get_bitmap_width(coin_b) + x+150, y+210, 0, buffer);



}
