    #include "game.h"

    const SDL_Color Game::gBtt_clr { 95, 95, 95, 250 };
    const SDL_Color Game::gBtt_ftclr { 250, 250, 250, 250 };
    const SDL_Color Game::gFont_color { 0, 0, 0, 250 };
    const SDL_Color gBttPress_clr { 250, 250, 250, 250 };

    Game::Game(Field *field, Army *army1, Army *army2)
        :   g_field { field }, g_army1 { army1 }, g_army2 {army2}
    {
        int buttonX { 15 };
        int buttonW { 50 };
        int buttonY { g_field->f_grid.y0};
        int buttonH { g_field->f_grid.h/8 };

        gButtons[1].assign(nullptr, "FORTH" ,   "Krungthep.ttf", 25, gBtt_ftclr, { buttonX + 3, buttonY + g_field->f_grid.h/16, buttonW, buttonH }, { buttonX, buttonY, buttonW, buttonH }, gBtt_clr, false, 0);
        gButtons[2].assign(nullptr, "BACK"  ,   "Krungthep.ttf", 25, gBtt_ftclr, { buttonX + 3, buttonY + g_field->f_grid.h/16, buttonW, buttonH }, { buttonX, buttonY + g_field->f_grid.h/4, buttonW, buttonH }, gBtt_clr, false, 0);
        gButtons[3].assign(nullptr, "UP"    ,   "Krungthep.ttf", 25, gBtt_ftclr, { buttonX + 3, buttonY + g_field->f_grid.h/16, buttonW, buttonH }, { buttonX, buttonY + 2*g_field->f_grid.h/4, buttonW, buttonH }, gBtt_clr, false, 0);
        gButtons[4].assign(nullptr, "DOWN"  ,   "Krungthep.ttf", 25, gBtt_ftclr, { buttonX + 3, buttonY + g_field->f_grid.h/16, buttonW, buttonH }, { buttonX, buttonY + 3*g_field->f_grid.h/4, buttonW, buttonH }, gBtt_clr, false, 0);

    }



    bool Game::bFunct(int id)
    {
        bool done {false};

        std::cout << "Call to button functionality function.\n";

        std::cout << "Button id : " << id << '\n';
        switch(id)
        {
            case 0:
                if (gButtonPressed)
                {
                    gButtons[0].b_color = gBttPress_clr;

                    //implement save functionality

                    done = false;
                }
                break;
                    
            case 1:
                if (g_selectedUnits.at(0))
                {
                    gButtons[1].b_color = gBttPress_clr;

                    for (Unit *sUnit : g_selectedUnits) {
                        sUnit->move(FORTH, g_field->f_grid);
                    }

                    mvAnimation = true;

                    done = true;
                }
                break;
                
            case 2:
                if (g_selectedUnits.at(0))
                {
                    gButtons[1].b_color = gBttPress_clr;

                    for (Unit *sUnit : g_selectedUnits) {
                        sUnit->move(BACK, g_field->f_grid);
                    }

                    mvAnimation = true;

                    done = true;
                }
                break;
                
            case 3:
                if (g_selectedUnits.at(0))
                {
                    gButtons[1].b_color = gBttPress_clr;

                    for (Unit *sUnit : g_selectedUnits) {
                        sUnit->move(UP, g_field->f_grid);
                    }

                    mvAnimation = true;

                    done = true;
                }
                break;
                
            case 4:
                if (g_selectedUnits.at(0))
                {
                    gButtons[1].b_color = gBttPress_clr;

                    for (Unit *sUnit : g_selectedUnits) {
                        sUnit->move(DOWN, g_field->f_grid);
                    }

                    mvAnimation = true;

                    done = true;
                }
                break;
                
            case 5:
                //figure out attack implementation

                done = true;
                break;
                
            case 6:
                //figure out quit implementation: send back to main menu?



                done = true;
                break;
        }

        return done;
        
    }


    void Game::display()
    {
        //display setup
        //SDL_SetRenderDrawColor(renderer, 102, 12, 0, 250);
        SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
        SDL_RenderClear(renderer);

        g_field->display();

        g_army1->display();
        g_army2->display();

        for (auto &button : gButtons) {
            button.display();
        }

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
                    } else if (curr_army == ARMY1) {
                        for (Troop &troop : g_army1->mTroop) {
                            if (troop.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!troop.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(troop.uSelect(pos));
                                } else {
                                    troop.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + troop.posUSelect);
                                }

                            }
                        }
                        for (Archer &archer : g_army1->mArcher) {
                            if (archer.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!archer.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(archer.uSelect(pos));
                                } else {
                                    archer.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + archer.posUSelect);
                                }

                            }
                        }
                        for (Knight &knight : g_army1->mKnight) {
                            if (knight.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!knight.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(knight.uSelect(pos));
                                } else {
                                    knight.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + knight.posUSelect);
                                }

                            }
                            
                        }
                    } else if (curr_army == ARMY2) {
                        for (Troop &troop : g_army2->mTroop) {
                            if (troop.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!troop.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(troop.uSelect(pos));
                                } else {
                                    troop.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + troop.posUSelect);
                                }

                            }
                        }
                        for (Archer &archer : g_army2->mArcher) {
                            if (archer.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!archer.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(archer.uSelect(pos));
                                } else {
                                    archer.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + archer.posUSelect);
                                }

                            }
                        }
                        for (Knight &knight : g_army2->mKnight) {
                            if (knight.Clicked(cursor_pos)){
                                state = UPDATE;
                                
                                std::cout << "Call to uSelect function.\n";

                                if (!knight.isSelected()) {
                                    int pos = g_selectedUnits.size();
                                    g_selectedUnits.push_back(knight.uSelect(pos));
                                } else {
                                    knight.uDeSelect();
                                    g_selectedUnits.erase(g_selectedUnits.begin() + knight.posUSelect);
                                }

                            }
                            
                        }
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

        //check selected units and enable buttons


        std::cout << "Call to update function.\n";
        if (gButtonPressed)
        {
            done = bFunct(gButtonPressed->b_id);
            gButtonPressed = nullptr;
        }

        return done;

    }