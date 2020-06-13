#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
class Status{
public:
    Status();

    void coin_change(int val);
    void stress_change(int val);
    void happiness_change(int val);
    void hunger_change(int val);
    void peepee_change(int val);
    void draw();
    void draw(int x,int y);
    int get_coin();
    int get_happiness();
    int get_hunger();
    int get_peepee();
    int get_stress();
    void coin_to(int);
    void happiness_to(int);
    void hunger_to(int);
    void peepee_to(int);
    void stress_to(int);

private:

    int coin, stress, happiness, hunger, peepee;

    ALLEGRO_BITMAP* coin_b;
    ALLEGRO_BITMAP* stress_b;
    ALLEGRO_BITMAP* happiness_b;
    ALLEGRO_BITMAP* hunger_b;
    ALLEGRO_BITMAP* peepee_b;
    ALLEGRO_BITMAP* status_b;

    ALLEGRO_FONT* menuFont;
};

#endif


//#endif // RECT_H_INCLUDED
