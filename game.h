#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "unit.h"
#include "army.h"
#include "button.h"
#include "field.h"

class Game
{
private:

    static const SDL_Color gBtt_clr;
    static const SDL_Color gBtt_ftclr;
    static const SDL_Color gFont_color;

    Field *g_field;

    Army *g_army1;
    Army *g_army2;

    std::array<Button, 8> gButtons;
    Button *gButtonPressed { nullptr };

    std::vector<Unit*> g_selectedUnits { nullptr };

    bool bFunct(int id);

    //implement text and texture generation for texts

    //implement selected units paradigm using pointer vector as stack


public:

    Army_enum curr_army { ARMY1 };

    bool mvAnimation { false };

    Game() = default;
    Game(Field *field, Army *army1, Army *army2);
    ~Game() {};

    bool collision(Army *army, Unit_Division division, int index);
    
    void display();

    void move_animation();

    void attack_animation();
    
    GAME_STATE get_uinput();
    
    bool update();

};

#endif