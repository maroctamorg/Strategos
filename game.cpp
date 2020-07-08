#include "game.h"

const SDL_Color Game::gBtt_clr { 95, 95, 95, 250 };
const SDL_Color Game::gBtt_ftclr { 250, 250, 250, 250 };
const SDL_Color Game::gFont_color { 0, 0, 0, 250 };

Game::Game(Field *field, Army *army1, Army *army2)
    :   g_field { field }, g_army1 { army1 }, g_army2 {army2}
{
    //gButtons[0].assign(nullptr, "FORTH", "Krungthep.ttf", 25, gBtt_ftclr, {, , button_w, button_h}, {, , button_w, button_h}, gBtt_clr, true, 0);

}


/*
bool Game::bFunct(int id)
{
    std::cout << "Call to button functionality function.\n";

    std::cout << "Button id : " << id << '\n';
    switch(id)
    {
        case 0:
            if (gButtonPressed.at(0))
            {
                gButtons[0].b_color = ;
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
*/

void Game::display()
{
    //display setup
    //SDL_SetRenderDrawColor(renderer, 102, 12, 0, 250);
    SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
    SDL_RenderClear(renderer);

    g_field->display();

    g_army1->display();
    g_army2->display();

    SDL_RenderPresent(renderer);

}

void Game::move_animation() {

}

void Game::attack_animation() {

}

GAME_STATE Game::get_uinput()
{
    GAME_STATE state { NOINPUT };

    SDL_Event event;
    SDL_Point cursor_pos { 0, 0 };

        SDL_PollEvent(&event);
        std::cout << "Polling Events...\n";
        switch(event.type)
        {
        case SDL_WINDOWEVENT_RESIZED:
            g_field->updateDimensions();
            state = UPDATE;
            break;
        case SDL_MOUSEBUTTONDOWN:

            std::cout << "SDL_MOUSEBUTTONDOWN event registered.\n";

            SDL_GetMouseState(&(cursor_pos.x), &(cursor_pos.y));

            std::cout << "Mouse State obtained.\n";

                for (int i {0}; i < gButtons.size(); i++)
                {
                    std::cout << "Evaluating fs_btt at " << i <<'\n';
                    if (cursor_pos.x < g_field->f_grid.x0)
                    {
                        if (gButtons[i].isActive() && gButtons[i].Clicked(cursor_pos))
                        {
                            state = UPDATE;

                            std::cout << "Call to press function.\n";

                            gButtonPressed = gButtons[i].press();

                            std::cout << "gButtonPressed: " << gButtonPressed << '\n';
                            //element.press must return a pointer to button element
                        }
                    //else if (player1) {check unit selections}
                    //else if (player2) {check unit selctions}
                    }
                    
                }
            break;
        case SDL_QUIT:
            state = TERMINATE;
            break;
        }
        
    return state;
}

bool Game::update()
{
    bool done { false };

    std::cout << "Call to update function.\n";
    if (gButtonPressed)
    {
        //done = bFunct(gButtonPressed->b_id);
        gButtonPressed = nullptr;
    }

    return done;

}