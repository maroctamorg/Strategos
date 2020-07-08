#ifndef ASELECT_H
#define ASELECT_H

#include "global.h"
#include "button.h"
#include "text.h"
//#include "game.h"
//#include "field.h"
//#include "army.h"
//#include "unit.h"

class aselect_menu
{
private:

    static const SDL_Colour as_bckgr_clr;
    static const SDL_Colour as_mncolor;

    const SDL_Color as_btt_clr { 95, 95, 95, 250 };
    const SDL_Color as_btt_ftclr { 250, 250, 250, 250 };
    const SDL_Color as_font_color { 0, 0, 0, 250 };
    
    static const SDL_Rect as_menurect;

/*
    int curr_flag { 0 };

    int a1_remaining {0};
    int a2_remaining {0};
    
    std::array<Text, 4> as_txt;
    std::array<SDL_Texture*, 4> as_txtTexture;
*/
    Text as_txt;   
    std::array<Button, 2> as_btt;

/*
    Button *as_bpressed { nullptr };
    Button *as_bSelected { nullptr };

    std::array<SDL_Point, 3> initPos;
*/
    int generateTextures();

public:

    aselect_menu();
    
    //~aselect_menu();

    void setCurrFlag(int flag);

    void display();
    
    GAME_STATE get_uinput();
    
    bool update();

    void destroyTextures();
};

#endif