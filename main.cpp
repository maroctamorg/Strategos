#include "global.h"
#include "fselect.h"
#include "aselect.h"
#include "game.h"

void Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_W, W_H, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void Quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();
}


bool exit_game { false };

int main (int argc, char *argv[])
{
    //Game::init()
    Init();

    if( !window || !renderer ) { std::cout << "Window and renderer improperly initialised.\n";}
    GAME_STATE menu_state { NOINPUT };

//First game loop : MAIN MENU (field + army selection + config)
    fselect_menu f_menu{};
    //generates textures, shapes, display objects (buttons) + temporary input variables(to handle user input : flags, field choice, army choice)
    //maybe takes in flag which is stored and accessed by switch statements
        //Main_menu main_menu{ 0 }...
  
    //field select screen
    bool mm_done { false };

    f_menu.display();
    while (!mm_done && !exit_game)
    {

        //SDL_Delay(10000);
        menu_state = f_menu.get_uinput();

        //std::cout << "Menu state: " << menu_state << '\n';

        if (menu_state == UPDATE)
        {
            mm_done = f_menu.update();
            std::cout << "mm_done : " << mm_done << '\n';
            //check all button presses: call functions
        }
        
        if (menu_state == TERMINATE)
        {
            mm_done = true;
            exit_game = true;
        }

        f_menu.display();
    }

/*

    //army select screen
    aselect_menu a_menu {};

    
    SDL_Event event;
    mm_done = false;
    while (!mm_done && !exit_game)
    {
        //Game::render()
        a_menu.display();

        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                mm_done = true;
                exit_game = true;
        }

        //SDL_Delay(10000);
        //menu_state = a_menu.get_uinput();

        std::cout << "Menu state: " << menu_state << '\n';

        if (menu_state == UPDATE)
        {
            //mm_done = a_menu.update();
            //check all button presses: call functions
        }
        
        if (menu_state == TERMINATE)
        {
            mm_done = true;
            exit_game = true;
        }
    }

*/


//Second game loop : GAME
    
    
    std::cout << "Field grid_ratio: " << f_menu.gridRatio << '\n';

    Field field { f_menu.gridRatio, f_menu.fs_effen };
    
    std::vector<SDL_Point> tPos1 { {1, 1}, {5, 1}, {10, 1} };
    std::vector<SDL_Point> aPos1 { {1, 5}, {1, 10}, {1, 15} };
    std::vector<SDL_Point> kPos1 { {5, 5} };

    std::vector<SDL_Point> tPos2 { {-1, 1}, {-5, 1}, {-10, 1} };
    std::vector<SDL_Point> aPos2 { {-1, 5}, {-1, 10}, {-1, 15} };
    std::vector<SDL_Point> kPos2 { {-5, 5} };

    Army army1 { field.f_grid, tPos1, aPos1, kPos1 };
    Army army2 { field.f_grid, tPos2, aPos2, kPos2 };
    Game game { &field, &army1, &army2 };
    std::cout << "Initialising game...\n";
    //pass onto constructor input from main_menu : initialize field and armies with user input
    //generates personalized field, two armies (which must include initial positions by default)

    //game.display();

    //SDL_Delay(1000);

    while(!exit_game){
        GAME_STATE game_state { NOINPUT };

        //user 1 input game loop
        bool p1_done { false };

        while (!exit_game && !p1_done)
        {
            //Game::render()
            game.display();

            if(game_state == ANIMATION) {
                game.move_animation();

            } else {

                //Game::get_user_input()
                game_state = game.get_uinput();

                //Game::update()
                if (game_state == UPDATE)
                {
                    p1_done = game.update();
                        //make sure all selected items can perform that action (special wizard and archer classes)
                }

                if (game_state == TERMINATE)
                {
                    p1_done = true;
                    exit_game = true;
                }
            }
            
        }
        
        //user 2 input game loop
        bool p2_done { false };
        while (!exit_game && !p2_done)
        {
            //Game::render()
            game.display();

            if(game_state == ANIMATION) {
                game.move_animation();

            } else {

                //Game::get_user_input()
                game_state = game.get_uinput();

                //Game::update()
                if (game_state == UPDATE)
                {
                    p2_done = game.update();
                        //make sure all selected items can perform that action (special wizard and archer classes)
                }

                if (game_state == TERMINATE)
                {
                    p2_done = true;
                    exit_game = true;
                }
            }

        }
    }    
    



    Quit(); //add called interfaces/menus

    return 0;
}
