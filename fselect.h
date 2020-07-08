#ifndef FSELECT_H
#define FSELECT_H

#include "global.h"
#include "button.h"

class fselect_menu
{
private:

    static const SDL_Colour fs_bckgr_clr;
    static const SDL_Colour fs_mn_clr;

    static const SDL_Color fs_btt_clr;
    static const SDL_Color fs_btt_ftclr;
    static const SDL_Color fs_font_color;
    
    SDL_Rect fs_menurect;

    int a1_remaining {0};
    int a2_remaining {0};
    
    std::array<Text, 2> fs_txt;

    std::array<Button, 6> fs_btt;

    Button *fs_bpressed { nullptr };
    std::array<Button*, 2> fs_bselected { nullptr, nullptr };
    
    int fs_tn {0};
    int fs_an {0};
    int fs_kn {0};
    int fs_tot {0};
    
    bool button_functionality(int id);

    int generateTextures();

public:

    bool fs_effen { false };
    gRatio gridRatio { UNDEFINED };

    void updateDimensions();

    fselect_menu();

    void display();
    
    GAME_STATE get_uinput();
    
    bool update();

    void destroyTextures();
};

#endif
