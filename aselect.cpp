#include "aselect.h"

const SDL_Colour aselect_menu::as_bckgr_clr   { 230, 230, 230, 250 };
const SDL_Colour aselect_menu::as_mncolor      { 193, 193, 193, 250 };

const SDL_Color as_btt_clr { 95, 95, 95, 250 };
const SDL_Color as_btt_ftclr { 250, 250, 250, 250 };
const SDL_Color as_font_color { 0, 0, 0, 250 };


const SDL_Rect aselect_menu::as_menurect { W_W/20, W_H/20, 9*W_W/10, 9*W_H/10 };


aselect_menu::aselect_menu()
    :   as_btt {}, as_txt {}
{
    std::cout << "Call to aselect_menu constructor.\n";
    const int title_h {as_menurect.h/5};
    const int title_w {as_menurect.w/5};

    const int button_w {as_menurect.w/4};
    const int button_h {as_menurect.h/15};

    as_btt[0].assign(nullptr, "BACK", "Krungthep.ttf", 50, as_btt_ftclr, { W_W/2 - 150, W_H/2 - 300, 300, 200 }, { W_W/2 - 125, W_H/2 - 325, 300, 200 }, as_btt_clr, true, 6);
    as_btt[1].assign(nullptr, "START", "Krungthep.ttf", 50, as_btt_ftclr, { W_W/2 - 150, W_H/2 + 300, 300, 200 }, { W_W/2 - 125, W_H/2 + 325, 300, 200 }, as_btt_clr, true, 7);


    as_txt.assign("Army 1", "Krungthep.ttf", 20, as_btt_ftclr, { 100, 100, 500, 100 });
    
    int control = generateTextures();
    std::cout << "generateTextures returned flag: " << control << '\n';
}

/*
bool aselect_menu::button_functionality(int id)
{
    std::cout << "Aselect:\tCall to button functionality function.\n";

    std::cout << "Button id : " << id << '\n';
    switch(id)
    {
        
    }

    return false;
    
}

void aselect_menu::setCurrFlag(int flag) { curr_flag = flag; }
*/

int aselect_menu::generateTextures()
{
    int control {0};
    std::cout << "Call to yet to be implemented generateTextures() in aselect_menu.\n";
    return control;
    //implement when loading textures onto menu outside of buttons or texts
}

void aselect_menu::display()
{
    SDL_SetRenderDrawColor(renderer, as_bckgr_clr.r, as_bckgr_clr.g, as_bckgr_clr.b, as_bckgr_clr.a);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, as_mncolor.r, as_mncolor.g, as_mncolor.b, as_mncolor.a);
    SDL_RenderFillRect(renderer, &as_menurect);
    
    //for (int i {0}; i < as_txt.size(); i++)
    //{
        as_txt.displayText();
    //}

        for (int i {0}; i < as_btt.size(); i++)
        {
            as_btt[i].display();
        }
/*
    if (as_bSelected)
    {
        int x {0}, y {0};
        SDL_GetMouseState(&x, &y);

        SDL_Rect dstrect {x, y, as_bSelected->b_rect.w, as_bSelected->b_rect.h};

        SDL_RenderCopy(renderer, as_bSelected->b_texture, NULL, &dstrect);
    }
*/    

    SDL_RenderPresent(renderer);

}

/*
GAME_STATE aselect_menu::get_uinput()
{
    GAME_STATE state { NOINPUT };

    SDL_Event event;
    SDL_Point cursor_pos { 0, 0 };

        SDL_PollEvent(&event);
        std::cout << "Aselect:\tPolling Events...\n";
        switch(event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            //create Button class { title, rect, texture/colour, struct state {active, pressed }, isPressed(), press(), isActive(), activate() }
            //create as_buttons in main menu as std::array<Button>

            std::cout << "SDL_MOUSEBUTTONDOWN event registered.\n";

            SDL_GetMouseState(&(cursor_pos.x), &(cursor_pos.y));

            std::cout << "Mouse State obtained.\n";

                for (int i {0}; i < as_btt.size(); i++)
                {
                    std::cout << "Evaluating as_btt at " << i <<'\n';
                    if (as_btt[i].isActive() && as_btt[i].Clicked(cursor_pos))
                    {
                        state = UPDATE;

                        std::cout << "Call to press function.\n";

                        as_bpressed = as_btt[i].press();

                        std::cout << "as_bpressed: " << as_bpressed << '\n';
                        //element.press must return a pointer to button element
                    }
                }
            break;
        case SDL_QUIT:  
            state = TERMINATE;
            break;
        }
    
    return state;
}
*/

/*
bool aselect_menu::update()
{
// gets user input
// passes into class variables
// updates display

// get button id
// call button_functionality function from main menu - switch...

    bool done { false };

    std::cout << "Call to update function.\n";
    if (as_bpressed)
    {
        done = button_functionality(as_bpressed->b_id);
        as_bpressed = nullptr;
    }

    return done;    
    
}
*/

void aselect_menu::destroyTextures()
{
    for (int i{0}; i < as_btt.size(); i++)
    {
        as_btt[i].destroyTexture();
    }

    //for (int i{0}; i < as_txtTexture.size(); i++)
    //    {
            as_txt.destroyTxtTexture();
    //    }
}