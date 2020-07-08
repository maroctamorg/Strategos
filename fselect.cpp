#include "fselect.h"
#include "button.h"

const SDL_Colour fselect_menu::fs_bckgr_clr   { 230, 230, 230, 250 };
const SDL_Colour fselect_menu::fs_mn_clr      { 193, 193, 193, 250 };

const SDL_Color fselect_menu::fs_btt_clr { 95, 95, 95, 250 };
const SDL_Color fselect_menu::fs_btt_ftclr { 250, 250, 250, 250 };
const SDL_Color fselect_menu::fs_font_color { 0, 0, 0, 250 };

void fselect_menu::updateDimensions()
{
    int x, y, w, h;
    SDL_GetWindowSize(window, &w, &h);
    SDL_GetWindowPosition(window, &x, &y);
    fs_menurect = { x, y, w, h };

    //update buttons and text textures: figure out everything as ratios (mostly ptsize's)
    
}

fselect_menu::fselect_menu()
    :   fs_menurect { W_W/20, W_H/20, 9*W_W/10, 9*W_H/10 }, a1_remaining {0}, a2_remaining {0}, fs_btt {}, fs_txt {}, fs_bselected { nullptr, nullptr },
        gridRatio { UNDEFINED }, fs_effen { false }, fs_tn {0}, fs_an {0}, fs_kn {0}, fs_tot {0}
{
    std::cout << "fselect_menu() constructor called.\n";

    const int title_h {fs_menurect.h/5};
    const int title_w {fs_menurect.w/5};

    const int button_w {fs_menurect.w/4};
    const int button_h {fs_menurect.h/15};

    fs_btt[0].assign(nullptr, "  FORWARD", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+13*fs_menurect.h/15, button_w, button_h}, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+13*fs_menurect.h/15, button_w, button_h}, fs_btt_clr, true, 0);
    fs_btt[1].assign(nullptr, " REGULAR: 50*35", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.w/6+fs_menurect.x, fs_menurect.y+3*fs_menurect.h/10, button_w, button_h}, {fs_menurect.w/6+fs_menurect.x, fs_menurect.y+3*fs_menurect.h/10, button_w, button_h}, fs_btt_clr, true, 1);
    fs_btt[2].assign(nullptr, "  WIDE: 60*30", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+3*fs_menurect.h/10, button_w, button_h}, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+3*fs_menurect.h/10, button_w, button_h}, fs_btt_clr, true, 2);
    fs_btt[3].assign(nullptr, "  TALL: 35*40", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.x+fs_menurect.w/6, fs_menurect.y+3*fs_menurect.h/5, button_w, button_h}, {fs_menurect.x+fs_menurect.w/6, fs_menurect.y+3*fs_menurect.h/5, button_w, button_h}, fs_btt_clr, true, 3);
    fs_btt[4].assign(nullptr, " DOUBLE: 100*70", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+3*fs_menurect.h/5, button_w, button_h}, {fs_menurect.x+7*fs_menurect.w/12, fs_menurect.y+3*fs_menurect.h/5, button_w, button_h}, fs_btt_clr, true, 4);
    fs_btt[5].assign(nullptr, " .", "Krungthep.ttf", 25, fs_btt_ftclr, {fs_menurect.x+fs_menurect.w/6, fs_menurect.y+13*fs_menurect.h/15, 50, 50}, {fs_menurect.x+fs_menurect.w/6, fs_menurect.y+13*fs_menurect.h/15, button_h, button_h}, fs_btt_clr, true, 5);

    std::cout << "fs_btt assigned.\n";

    fs_txt[0].assign("SELECT FIELD", "Krungthep.ttf", 50, fs_font_color, { 2*fs_menurect.w/5+fs_menurect.x - 75, fs_menurect.y + title_h/4 + 25, fs_menurect.w/5, fs_menurect.h/5 });
    fs_txt[1].assign("  EFFECTS ENABLED","Krungthep.ttf", 25, fs_font_color, { fs_menurect.x+fs_menurect.w/6+50, fs_menurect.y+13*fs_menurect.h/15, 50, 50});

    std::cout << "fs_txt assigned.\n";

    int control = generateTextures();
    std::cout << "generateTextures returned flag: " << control << '\n';
}

int fselect_menu::generateTextures()
{
    int control {0};
    std::cout << "Call to yet to be implemented generateTextures() in fselect_menu.\n";
    return control;
    //implement when loading textures onto menu outside of buttons or texts
}

bool fselect_menu::button_functionality(int id)
{
    std::cout << "Call to button functionality function.\n";

    std::cout << "Button id : " << id << '\n';
    switch(id)
    {
        case 0:
            if (fs_bselected.at(0))
            {
                fs_btt[0].b_color = fs_bckgr_clr;
                return true;
            }
            break;
                  
        case 1:
            if (fs_bselected.at(0))
            {
                fs_bselected[0]->b_color = fs_btt_clr;
            }

            fs_bselected[0] = &fs_btt[1];
            fs_bselected[0]->b_color = fs_bckgr_clr;

            gridRatio = REGULAR;

            std::cout << "Field size: 50*35\n";
            break;
            
        case 2:
            if (fs_bselected.at(0))
            {
                fs_bselected[0]->b_color = fs_btt_clr;
            }

            fs_bselected[0] = &fs_btt[2];
            fs_bselected[0]->b_color = fs_bckgr_clr;

            gridRatio = WIDE;

            std::cout << "Field size: 75*40\n";

            break;
            
        case 3:
            if (fs_bselected.at(0))
            {
                fs_bselected[0]->b_color = fs_btt_clr;
            }

            fs_bselected[0] = &fs_btt[3];
            fs_bselected[0]->b_color = fs_bckgr_clr;

            gridRatio = TALL;

            std::cout << "Field size: 50*75\n";

            break;
            
        case 4:
            if (fs_bselected.at(0))
            {
                fs_bselected[0]->b_color = fs_btt_clr;
            }

            fs_bselected[0] = &fs_btt[4];
            fs_bselected[0]->b_color = fs_bckgr_clr;

            gridRatio = DOUBLE;

            std::cout << "Field size: 100*70\n";

            break;
            
        case 5:
            if (fs_bselected.at(1))
            {
                fs_bselected[1]->b_color = fs_btt_clr;
                fs_effen = false;
                fs_bselected[1] = nullptr;

                std::cout << "Field Effects disabled.\n";
            }
            else {

                fs_bselected[1] = &fs_btt[5];
                fs_bselected[1]->b_color = fs_bckgr_clr;

                fs_effen = true;

                std::cout << "Field Effects enabled.\n";
            }

            break;
            
        case 6:
            break;
            
        case 7:
            break;
    }

    return false;
    
}

void fselect_menu::display()
{
    SDL_SetRenderDrawColor(renderer, fs_bckgr_clr.r, fs_bckgr_clr.g, fs_bckgr_clr.b, fs_bckgr_clr.a);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, fs_mn_clr.r, fs_mn_clr.g, fs_mn_clr.b, fs_mn_clr.a);
    SDL_RenderFillRect(renderer, &fs_menurect);
    
    for (int i {0}; i < fs_txt.size(); i++)
    {
        fs_txt[i].displayText();
    }

    for (int i {0}; i < fs_btt.size(); i++)
    {
        fs_btt[i].display();
    }


    SDL_RenderPresent(renderer);

}

GAME_STATE fselect_menu::get_uinput()
{
    GAME_STATE state { NOINPUT };

    SDL_Event event;
    SDL_Point cursor_pos { 0, 0 };

        SDL_PollEvent(&event);
        std::cout << "Polling Events...\n";
        switch(event.type)
        {
        case SDL_MOUSEBUTTONDOWN:

            std::cout << "SDL_MOUSEBUTTONDOWN event registered.\n";

            SDL_GetMouseState(&(cursor_pos.x), &(cursor_pos.y));

            std::cout << "Mouse State obtained.\n";

                for (int i {0}; i < fs_btt.size(); i++)
                {
                    std::cout << "Evaluating fs_btt at " << i <<'\n';
                    if (fs_btt[i].isActive() && fs_btt[i].Clicked(cursor_pos))
                    {
                        state = UPDATE;

                        std::cout << "Call to press function.\n";

                        fs_bpressed = fs_btt[i].press();

                        std::cout << "fs_bpressed: " << fs_bpressed << '\n';
                        //element.press must return a pointer to button element
                    }
                }
            break;
        case SDL_WINDOWEVENT_RESIZED:
            updateDimensions();
            break;

        case SDL_QUIT:  
            state = TERMINATE;
            break;
        }
    
    return state;
}

bool fselect_menu::update()
{
// gets user input
// passes into class variables
// updates display

// get button id
// call button_functionality function from main menu - switch...

    bool done { false };

    std::cout << "Call to update function.\n";
    if (fs_bpressed)
    {
        done = button_functionality(fs_bpressed->b_id);
        fs_bpressed = nullptr;
    }

    return done;    
    
}